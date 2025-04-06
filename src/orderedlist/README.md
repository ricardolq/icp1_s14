# Ordered Linked List Implementation

This project implements an ordered linked list in C. The linked list stores `Person` structures and provides various operations such as insertion, deletion, searching, and printing.

## Features
- Insert nodes in an ordered manner based on the name.
- Insert nodes at the beginning, end, or a specific position.
- Delete nodes by name, at the beginning, end, or a specific position.
- Search for nodes by name.
- Print all nodes or a specific node by position.
- Clear the entire list.

## Files
- `listsordered.c`: Contains the implementation of the ordered linked list.
- `CMakeLists.txt`: Build configuration file for the project.

## Build Instructions
1. Ensure you have CMake installed on your system.
2. Navigate to the project directory:
   ```bash
   cd /Users/creepbook/ie/cp1/repos/icp1_s14/src/orderedlist
   ```
3. Create a build directory and navigate into it:
   ```bash
   mkdir build && cd build
   ```
4. Run CMake to generate the build files:
   ```bash
   cmake ..
   ```
5. Build the project:
   ```bash
   make
   ```

## Run Instructions
1. After building, run the executable:
   ```bash
   ./SimpleOrderedLinkedList
   ```
2. The program will demonstrate various operations on the ordered linked list.

## Example Output
```
Name: Alice, Age: 25, Gender: F
Name: Bob, Age: 30, Gender: M
Name: Charlie, Age: 35, Gender: M
Second round
Name: Alice, Age: 25, Gender: F
Name: Bob, Age: 30, Gender: M
Name: Eve, Age: 45, Gender: F
Name: Charlie, Age: 35, Gender: M
Name: David, Age: 40, Gender: M
```
