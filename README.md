# remove_empty_dirs

A lightweight Windows command-line utility written in C++17 to delete empty directories within a specified folder.
Uses the C++ standard `<filesystem>` library for robust directory handling.

## Features

- Validates the input path to ensure it exists and is a directory.
- Removes empty subdirectories within the specified folder.
- Provides clear error messages for invalid paths, permissions issues, or filesystem errors.

## Requirements

- Windows operating system.
- MinGW-w64 with C++17 support (e.g., installed via `scoop install mingw-winlibs-llvm-ucrt`).
- CMake 3.30 or later.
- C++17-compatible compiler (e.g., GCC 14.2.0 or later).

## Building

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/MrDwarf7/rm_stubs_cpp.git
   cd rm_stubs_cpp
   ```

2. **Configure CMake**:
    - Create and navigate to a build directory:
      ```bash
      mkdir build
      cd build
      cmake .. -G "MinGW Makefiles"
      make # debug 
      # or
      cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
      ```
    - This generates makefiles for MinGW.

3. **Build the Project**:
    - From the `build` directory:
      ```bash
      cmake --build . --config Release
      ```
    - The executable will be in `build/rm_stubs.exe`.

4. **Clean Build Artifacts** (Optional):
   ```bash
   rmdir /S /Q build
   ```

## Usage

Run the program with a directory path to delete its empty subdirectories:

```bash
.\build\rm_stubs.exe "C:\path\to\folder"
```

- **Example**:
  ```bash
  mkdir "C:\Temp\test_dir"
  .\build\rm_stubs.exe "C:\Temp"
  ```
  Output (if `test_dir` is empty):
  ```
  Removed empty directory "C:\Temp\test_dir"
  ```

- **Error Handling**:
    - Invalid paths: "Error: path does not exist or is not a directory."
    - Non-empty directories: Skipped without deletion.
    - Usage error: `Usage: rm_stubs.exe <folder_path>` if no/invalid arguments.
    - Filesystem errors: Detailed error messages with system error codes.

## Project Structure

- `main.cpp`: Core program logic using C++17 `<filesystem>`.
- `CMakeLists.txt`: CMake configuration for building the project.
- `build/`: Output directory containing `rm_stubs.exe` and build artifacts.

## Notes

- Built with C++17 for `<filesystem>` support.
- Tested with MinGW-w64 (GCC 14.2.0) on Windows.
- CMake sets C++26 standard, but the code is C++17-compatible.
- Cross-platform compatible (Linux/macOS with minor adjustments, e.g., path separators).

## Contributing

Feel free to open issues or submit pull requests on [GitHub](https://github.com/MrDwarf7/rm_stubs_cpp.git).

## License

MIT License (see LICENSE file, if added).
