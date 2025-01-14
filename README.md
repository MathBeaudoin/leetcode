# Leetcode
A repository for all Leetcode problem I am solving.

## File organization
The root contains directories for the different languages used, but note that I am not solving problems with every languages. The directories act more like an abstraction for config and main files. I will be using the language that interests me the most when solving problems.

In the subdirectories, every problem is solved in its own directory. The root of the subdirectories contain, as said above, config and main files; the main will simply import the current problem's solution and run it.

## C++ 
CMake is used to compile the code and build the executable. Solutions are added to `CMakeLists.txt` to quickly check if they compile without copy-pasting to Leetcode. 

To do so, run (from `/c++/` directory):
```
cmake -B ./build && cmake --build ./build && ./build/new_target
```