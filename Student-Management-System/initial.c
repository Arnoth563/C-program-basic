/*
Student Management System in C
A console-based Student Management System developed in C to demonstrate dynamic memory allocation, structures, string handling, searching algorithms, statistics generation, and menu-driven programming.

Features
Register students dynamically using calloc()
Add more students using realloc()
Display all student records
Search students by full name using strcmp()
Generate student statistics
Highest Mark Student
Lowest Mark Student
Mean
Median
Mode
Dynamic memory management using calloc(), realloc(), and free()
String handling using fgets() and strcspn()
Modular programming using functions
Menu-driven user interface
Technologies Used
C Programming Language
Dynamic Memory Allocation
Structures
Pointers
Functions
Strings
Searching Algorithms
Statistical Analysis
Sample Menu
================== STUDENT MANAGEMENT SYSTEM
Display Students
Search Student
Add More Students
Statistics Report
Exit
Concepts Demonstrated
calloc()
realloc()
free()
Arrays of Structures
Pointer to Structure (->)
fgets()
strcmp()
Dynamic Data Expansion
Modular Design
Learning Outcomes
This project was developed as part of my journey toward mastering C programming and preparing for larger projects such as:

Library Management System
Inventory Management System
Banking System
Store Credit Management System
It helped strengthen my understanding of dynamic memory allocation, program design, data management, and statistics processing.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
char full_name[100];
char gender[10];
char student_no[25];
int marks;

};
void InputStudent(struct student *stud, int start, int end) {
int i;

while(getchar()!='\n');
for(i=start; i<end; i++) {
printf("\n======Enter student detail's %d========\n", i+1);
printf("Full name: ");
fgets((stud+i)->full_name, sizeof((stud+i)->full_name), stdin);
(stud+i)->full_name[strcspn((stud+i)->full_name, "\n")]='\0';
printf("Student Number: ");
fgets((stud+i)->student_no, sizeof((stud+i)->student_no), stdin);
(stud+i)->student_no[strcspn((stud+i)->student_no, "\n")]='\0';
printf("Gender: ");
fgets((stud+i)->gender, sizeof((stud+i)->gender), stdin);
(stud+i)->gender[strcspn((stud+i)->gender, "\n")]='\0';
printf("Marks: ");
scanf("%d", &(stud+i)->marks);
while(getchar()!='\n');
printf("...............................................................\n");


}
printf("\n");

}
void DisplayStudent(struct student *stud, int size) {
int i;

for(i=0; i<size; i++) {
printf("\n=========Student detail %d=======\n", i+1);
printf("Student number: %s\n", (stud+i)->student_no);
printf("Full Name: %s\n", (stud+i)->full_name);
printf("Gender: %s\n", (stud+i)->gender);
printf("Marks: %d\n", (stud+i)->marks);
printf("............................................................\n");

}

printf("\n");

}

struct student *AddMoreStudent(struct student *stud, int *size) {
int extra;
printf("How many student you want to add: ");
scanf("%d", &extra);
if(extra<=0) {
printf("invalide number of student.\n");
return stud;
}
struct student *temp;

temp=realloc(stud, (*size+extra)*sizeof(struct student));
if(temp==NULL) {
printf("Memory allcation failed.\n");

return stud;
}

stud=temp;
InputStudent(stud, *size, (*size+extra));
*size+=extra;


return stud;
}
void SearchStudent(struct student *stud, int size) {
int i, choice, found=0, found_position=0, attempt=0;
char name[100];
char number[25];
do{
choice=0;
found=0;
printf("\n=======Search student by the details that you have==========\n");
printf("1. Full name\n");
printf("2.Student number\n");
printf("3. Exit.\n");
printf("...................................................\n");
printf("Enter your choice: ");
scanf("%d", &choice);
printf("_____________________________\n");
if(choice<1 || choice> 3) {
printf("\nEnter number from 1 to 3.\n");
continue;
}
while(getchar()!='\n');
switch (choice) {
case 1: printf("Enter full name to search for student: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")]='\0';
for(i=0; i<size; i++) {
if(strcmp((stud+i)->full_name, name)==0) {
found=1;
found_position=i;
break;
}
}
if(found==0) {
printf("Student name not found try again later.\n");
}else {
printf("\n_______Student found__________\n");
printf("Full Name: %s\n", (stud+found_position)->full_name);
printf("Student Number: %s\n", (stud+found_position)->student_no);
printf("Gender: %s\n", (stud+found_position)->gender);
printf("Marks : %d\n", (stud+found_position)->marks);
printf("....................................................................\n");
}
break;
case 2:printf("Enter student number to search for student: ");
fgets(number, sizeof(number), stdin);
number[strcspn(number, "\n")]='\0';
for(i=0; i<size; i++) {
if(strcmp((stud+i)->student_no, number)==0) {
found=1;
found_position=i;
break;
}
}
if(found==0) {
printf("Student number not found try again later.\n");
}else {
printf("\n_______Student found__________\n");
printf("Full Name: %s\n", (stud+found_position)->full_name);
printf("Student Number: %s\n", (stud+found_position)->student_no);
printf("Gender: %s\n", (stud+found_position)->gender);
printf("Marks : %d\n", (stud+found_position)->marks);
printf("....................................................................\n");
}
break;
case 3: printf("\nThank you for using our system\n"); break;
default: printf("Invalid entery.\n"); break;
}
if(attempt>=3) {
printf("You have been trying to search for student for a while\n try agin later \n");
return;
}
attempt++;

}while(choice!=3 && found==0);


}
void StatisticReport(struct student *stud, int size) {
int i, j, count, already_count, max_count, highest_position, lowest_position, mode;
int highest, lowest, sum_marks, num;
float mean, median;
int *temp_marks;
temp_marks=malloc(size*sizeof(int));
if(temp_marks==NULL) {
printf("Memory allocation failed.\n");
return;
}

if(size==0) {
printf("No student record available.\n");
return;
}
for(i=0; i<size; i++) {
temp_marks[i]=(stud+i)->marks;
}
for(i=0; i<size-1; i++) {
for(j=i+1; j<size; j++) {
if(temp_marks[i]>temp_marks[j]) {
num=temp_marks[i];
temp_marks[i]=temp_marks[j];
temp_marks[j]=num;
}

}

}
if(size%2==0) {
median=(float)(temp_marks[(size/2)-1]+ temp_marks[size/2])/2.00;
}else {
median=(float)temp_marks[size/2];
}
free(temp_marks);
highest= (stud+0)->marks;
highest_position=0;
lowest=(stud+0)->marks;
lowest_position=0;
sum_marks=0;
for(i=0; i<size; i++) {
if(highest< (stud+i)->marks) {
highest=(stud+i)->marks;
highest_position=i;
}

if(lowest> (stud+i)->marks) {
lowest=(stud+i)->marks;
lowest_position=i;
}

sum_marks+=(stud+i)->marks;
}

count=0;
max_count=0;

for (i=0; i<size; i++) {
already_count=0;
for(j=0; j<i; j++) {
if((stud+i)->marks==(stud+j)->marks) {
already_count=1;
break;
}

}

if(already_count==1) {
continue;
}

count=1;

for(j=i+1; j<size; j++) {
if((stud+i)->marks==(stud+j)->marks) {
count++;
}
}

if(count>max_count) {
max_count=count;
mode=(stud+i)->marks;
}

}

mean=(float)sum_marks/size;

printf("\n==========================\n");
printf("STUDENT'S STATISTICS REPORT.\n");
printf("_________________________________\n");
printf("\n---------Highest student-------------\n");
printf("Full name: %s\n", (stud+highest_position)->full_name);
printf("Student number: %s\n", (stud+highest_position)->student_no);
printf("Gender: %s\n", (stud+highest_position)->gender);
printf("Marks: %d\n---------------------------- \n", highest);
printf("\n......................Lowest student..............................\n");
printf("Full name: %s\n", (stud+lowest_position)->full_name);
printf("Student number: %s\n", (stud+lowest_position)->student_no);
printf("Gender: %s\n", (stud+lowest_position)->gender);
printf("Marks: %d\n......................................... \n", lowest);
printf("<><><><><>\nMean: %.2f\n<><><><>", mean);
printf("\n########\nMedian: %.2f\n######", median);
printf("\n********\nMode: %d\n********", mode);
printf("\n@@@@@@@@@@@@@@@\n");

}
void SaveStudentFile(struct student *stud, int size) {
FILE*gd;
gd=fopen("initial.dat", "wb");

if(gd==NULL) {
printf("Error occured during opening the file.\n");
return;
}


if(fwrite(&size, sizeof(int), 1, gd)!=1) {
printf("Filed to save in file.\n");
return;
}

if(fwrite(stud, sizeof(struct student), size, gd)!=size) {
printf("File to save student records.\n");
return;
}

fclose(gd);
printf("\n.............................\nStudent successfull saved in the file.\n<><><><><><><><>\n");
}
struct student *LoadFromFile(struct student *stud, int *size) {
FILE*fp;
fp=fopen("initial.dat", "rb");

if(fp==NULL) {
printf("Error occured during opening the file.\n");
return stud;
}
struct student *temp;
if(fread(size, sizeof(int), 1, fp)!=1) {
fclose(fp);
return stud;
}
if(*size <= 0 || *size > 10000) {
    printf("Invalid file format.\n");
    fclose(fp);
    return NULL;
}

temp=realloc(stud, (*size)*sizeof(struct student));
if(temp==NULL) {
printf("Memory allocation failed.\n");
fclose(fp);
return stud;
}
stud=temp;

if(fread(stud, sizeof(struct student), *size, fp)!= *size) {
printf("File data may be corrupted.\n");
fclose(fp);
return stud;
}

fclose(fp);
printf("Data successfull loaded.\n");
return stud;
}
int main() {

int start_choice;
struct student *favour = NULL;
int size = 0;
do{
printf("\n===================\n");
printf("WELCOME\n");
printf("=====================\n");
printf("\n1. New Student Database\n");
printf("2. Load Student Database\n");
printf("3. Exit.\n");
printf("\n<><><><><><><><><><><><>\n");
printf("Enter choice: ");
if(scanf("%d", &start_choice)!=1){
while(getchar()!='\n');
continue;

}
printf("\n************************\n");
if(start_choice==1) {
printf("How many student to add initial: ");
scanf("%d", &size);
favour= (struct student *)calloc(size, sizeof(struct student));
if(favour==NULL) {
printf("Memory allocation failed.\n");
free(favour);
return 0;
}
InputStudent(favour, 0, size);
printf("Initial student successfull saved.\n-------------------\n \n");

}else if(start_choice==2){

favour=LoadFromFile(favour, &size); 
if(favour==NULL) {
printf("Loading failed.\n");
return 0;
}
}else if(start_choice==3) {
printf("Goodbey.\n");
return 0;
}else {
printf("Invalid entery try again in few munites.\n");
return 0;
}


}while(start_choice<1 || start_choice>3);

int choice;
do{
choice=0;
printf("\n==================================\n");
printf("STUDENT MANAGEMENT SYSTEM\n");
printf("\n==================================\n");
printf("1. Add Students\n");
printf("2. Display Students.\n");
printf("3. Search Student.\n");
printf("4. Statistics Report.\n");
printf("5. Save Students To File.\n");
printf("6. Load Students From File.\n");
printf("7. Exit.\n");
printf(".................................................\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
printf("Invalide input.\n");
while(getchar()!='\n');
continue;

}
printf("\n$$$$$$$$$$$$$$$$$$$$$$$\n");
if(choice<1 || choice>7) {
continue;
}
switch(choice) {
case 1: favour=AddMoreStudent(favour, &size);break;
case 2: DisplayStudent(favour, size);break;
case 3: SearchStudent(favour, size);break;
case 4: StatisticReport(favour, size);break;
case 5: SaveStudentFile(favour, size); break;
case 6: favour=LoadFromFile(favour, &size); DisplayStudent(favour, size);break;
case 7:printf("Thank you for using our system.\n");break;
default: printf("Invalid entery please try again.\n");

}


}while(choice!=7);


free(favour);

return 0;
}











