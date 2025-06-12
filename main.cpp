/* Author: Blake // MrDwarf7
 * Date: 2025-06-13
 * Description: This program removes empty directories from a specified folder.
 * Usage: ./rm_stubs <folder_path>
 * License: MIT License
 */
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main(const int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <folder_path>\n";
        return 1;
    };

    const fs::path root{argv[1]};

    try {
        if (!fs::exists(root) || !fs::is_directory(root)) {
            std::cerr << "Error: path does not exist or is not a directory.\n";
            return 1;
        };

        /* actual processing here */
        for (const auto &entry: fs::directory_iterator(root)) {
            if (entry.is_directory()) {
                if (const fs::path &subdir = entry.path(); fs::is_empty(subdir)) {
                    std::error_code error_code;
                    fs::remove(subdir, error_code);
                    if (error_code) {
                        std::cerr << "Failed to remove " << subdir << ": " << error_code.message() << "\n";
                    } else {
                        std::cout << "Removed empty directory" << subdir << " \n";
                    }
                }
            }
        }

    } catch (const fs::filesystem_error &e) {
        std::cerr << "Filesystem error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
