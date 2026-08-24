# Student Management System

A console-based Student Management System developed in the C Programming Language.

This project allows users to create, manage, update, search, delete, save, and load student records using dynamic memory allocation and file handling.

---

## Features

### Student Management

- Add new students
- Display student records
- Search students by:
  - Full Name
  - Student Number
- Update student information
- Delete student records

### Data Validation

- Prevents duplicate student numbers
- Handles invalid menu choices
- Validates user input
- Prevents duplicate records during updates

### Statistics Report

Generate statistics from student marks:

- Highest scoring student
- Lowest scoring student
- Mean
- Median
- Mode

### File Handling

- Save records to a binary file
- Load records from a binary file
- Persistent storage between program executions

### Dynamic Memory Management

- Uses `calloc()` for initial allocation
- Uses `realloc()` when adding or deleting students
- Uses `free()` for memory cleanup

---

## Technologies Used

- C Programming Language
- Structures
- Pointers
- Dynamic Memory Allocation
- File Handling
- Modular Programming
- Data Validation

---

## Concepts Demonstrated

This project demonstrates:

- Arrays of Structures
- Pointer Arithmetic
- Function Decomposition
- Dynamic Memory Allocation
- Binary File Operations
- Searching Algorithms
- Statistical Calculations
- Menu-Driven Applications
- Input Validation
- Memory Management

---

## Project Functions

### InputStudent()

Captures student information and validates student numbers.

### DisplayStudent()

Displays all student records stored in memory.

### AddMoreStudent()

Adds new students using dynamic memory reallocation.

### SearchStudent()

Searches for student records using:

- Full Name
- Student Number

### UpdateStudent()

Updates a student's details while maintaining student number uniqueness.

### DeleteStudent()

Removes a student record and reallocates memory.

### StatisticReport()

Generates:

- Mean
- Median
- Mode
- Highest Marks
- Lowest Marks

### SaveStudent()

Stores student records in a binary file.

### LoadFromFile()

Loads records from a binary file into memory.

---

## File Structure

```text
Student-Management-System
│
├── initial.c
├── initial.dat
└── README.md
```

---

## Compilation

Using GCC:

```bash
gcc initial.c -o student_management
```

Run the program:

```bash
./student_management
```

Windows:

```bash
student_management.exe
```

---

## Program Menu

```text
1. Add Students
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Statistics Report
7. Save Students To File
8. Load Students From File
9. Exit
```

---

## Sample Features

### Add Student

```text
Enter full name:
Enter student number:
Enter gender:
Enter marks:
```

### Search Student

```text
1. Full Name
2. Student Number
```

### Statistics Report

```text
Highest Student
Lowest Student
Mean
Median
Mode
```

---

## Learning Outcomes

Through this project, I enhanced my understanding of:

- Memory Allocation
- Pointers
- Structures
- File Processing
- Program Debugging
- Data Validation
- Problem Solving
- Software Design Principles

---

## Future Improvements

Potential future enhancements include:

- Login Authentication System
- Sorting Records
- Student Grades Classification
- CSV Import and Export
- Linked List Implementation
- Database Integration (MySQL)
- Graphical User Interface (GUI)
- Report Generation

---

## Author

**Arnoth Shikukutu**

Bachelor of Computer Science (NQF Level 7)

---

## License

This project is available under the Apache