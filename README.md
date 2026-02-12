# Exercise 3: Student Linked List

A C++ program with a Student struct that uses dynamically allocated arrays in a linked list.

## Requirements Met

1. ✓ Separate declaration (Student.h) from definition (Student.cpp)
2. ✓ Asks how many students will be entered
3. ✓ Gets student info until all are entered
4. ✓ Prints all students
5. ✓ Tests edge cases

## Files

- **Student.h** - Student struct declaration
- **Student.cpp** - Student implementation
- **main.cpp** - Main program
- **test.cpp** - Test suite
- **Makefile** - Build script

## Compilation

```bash
make            # Compile all
make run-main   # Run main program
make run-test   # Run tests
make clean      # Clean build files
```

## Features

- **Student struct**: name, numAssignments, dynamically allocated scores array
- **Copy constructor & assignment operator**: Deep copy semantics
- **Destructor**: Proper cleanup of dynamic memory
- **Linked list**: Dynamically allocated StudentNode pointers
- **7 edge case tests**: Zero assignments, copy constructor, assignment operator, average calculation, linked lists (single/multiple nodes), boundary values

## Example

```bash
$ ./main
===== Student Linked List =====
How many students? 2

Student 1:
Name: Alice
Number of assignments: 2
Score 1: 85
Score 2: 90

Student 2:
Name: Bob
Number of assignments: 1
Score 1: 92

===== All Students =====
Name: Alice, Assignments: 2, Average: 87.50
Name: Bob, Assignments: 1, Average: 92.00
```

## Edge Cases Tested

1. Zero assignments
2. Copy constructor (deep copy)
3. Assignment operator (deep copy)
4. Average calculation
5. Linked list - single node
6. Linked list - multiple nodes
7. Boundary score values (0-100)