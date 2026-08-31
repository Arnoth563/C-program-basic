Dynamic Memory Allocation in C
This folder contains practical exercises completed during Week 13 of my C Programming learning journey.

The focus of this week was understanding dynamic memory allocation using:
malloc()
calloc()
realloc()
free()
The exercises were designed to strengthen my understanding of dynamic data storage, structures, memory management, traversal, searching, updating, deleting, and statistics generation.

Learning Objectives
By completing these exercises, I practiced:

Dynamic memory allocation
Dynamic arrays
Structures
CRUD(Create, Read, Update, Delete) operations
Searching algorithms
Statistical calculations
Memory management
Menu-driven applications
Input validation
Program design
Exercises Completed
________________________________________________________________________________
Exercise 1 - Employee Management System
Features
Add employees
Display employee information
Add more employees using realloc()
Dynamic memory allocation
Employee ID validation
Concepts Practiced
Structures
calloc()
realloc()
free()
Arrays of structures
_____________________________________________________________________________________
Exercise 2 - Dynamic Marks Manager
Features
Store student marks dynamically
Add more marks using realloc()
Display marks
Calculate:
Highest mark
Lowest mark
Average
Median
Mode
Concepts Practiced
Dynamic integer arrays
Statistical analysis
Dynamic memory management
____________________________________________________________________________________
Exercise 3 - Supplier Database
Features
Add suppliers
Display suppliers
Search supplier by name
Delete supplier records
Dynamic growth of records
Concepts Practiced
Structures
Searching
Dynamic arrays
Record deletion
_____________________________________________________________________________
Exercise 4 - Dynamic Budget System
Features
Add departments
Update department budgets
Calculate total budget
Find department with the highest budget
Add more departments dynamically
Concepts Practiced
Structures
Dynamic memory
Searching
Financial calculations
________________________________________________________________________
Exercise 5 - Movie Collection System
Features
Add movies
Display movies
Search movies
Delete movies
Expand movie collection dynamically
Movie Information Stored
Movie Title
Release Year
Rating
___________________________________________________________________________
Concepts Practiced
CRUD operations
Structures
Dynamic memory allocation
Menu-driven applications
Key Concepts Learned
malloc()
Used to allocate memory dynamically.

Example:

ptr = malloc(sizeof(int));
calloc()
Used to allocate and initialize memory.

Example:

ptr = calloc(size, sizeof(struct employee));
realloc()
Used to increase or decrease allocated memory.

Example:

ptr = realloc(ptr, new_size);
free()
Used to release allocated memory.

Example:

free(ptr);
Skills Developed
Dynamic Memory Allocation
Structures
Searching
Updating Records
Deleting Records

✅ Statistical Reports

✅ Input Validation

✅ Menu-Driven Programs

✅ Problem Solving

✅ Memory Management

Reflection
Week 13 significantly improved my understanding of how memory is managed in C programs. Through multiple practical exercises, I learned how to create applications that grow dynamically during runtime using malloc(), calloc(), realloc(), and free().

The exercises also strengthened my confidence in designing complete console applications using