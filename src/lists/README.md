# SimpleLinkedList: Singly Linked List Implementation

This project implements a singly linked list to manage a list of `Person` structures. It provides various operations such as insertion, deletion, searching, and printing.

## Features

- **Insertions**:
  - At the beginning of the list.
  - At the end of the list.
  - At a specific position in the list.
- **Deletions**:
  - By name.
  - At the beginning of the list.
  - At the end of the list.
  - At a specific position in the list.
- **Searching**:
  - Find a node by the name of the person.
- **Printing**:
  - Print the entire list.
  - Print a specific node by position.
- **Clearing**:
  - Free all allocated memory and clear the list.

## Files

- `CMakeLists.txt`: Build configuration for the project.
- `lists.c`: Implementation of the singly linked list.

## How to Build and Run

1. Use CMake to configure and build the project:
   ```bash
   cmake .
   make
   ```
2. Run the executable:
   ```bash
   ./SimpleLinkedList
   ```

## Example Usage

The `main` function demonstrates the usage of the linked list functions by performing the following steps:

1. Create a list of `Person` structures.
2. Insert nodes at various positions.
3. Print the list.
4. Perform deletions and search operations.