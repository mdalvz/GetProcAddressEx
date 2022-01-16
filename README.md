# GetProcAddressEx

Adaptation of the classic WinApi GetProcAddress, so that it can now find symbols from modules in external processes.

Process memory reads are cached by default, although a non-cached reader included in the source if the cache code is buggy.

# Running The Test

1. Clone the repository
2. Compile the source with CMake
3. Run Test.exe

## Example Output

![Example Output](/example.png?raw=true)