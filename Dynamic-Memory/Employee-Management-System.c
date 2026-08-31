#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee {
char employee_id[25];
char full_name[100];
float salary;

};
void PrintEmployee(struct employee *emp, int position) {
printf("Employee ID: %s\n", emp[position].employee_id);
printf("Full Name: %s\n", emp[position].full_name);
printf("Salary: N$ %.2f\n", emp[position].salary);

}

void InputEmployee(struct employee *emp, int start, int end) {
if(start>end) {
printf("Invalid number of employees.\n");
return;
}
int i, j, found=0, attemp=0;
char id[25];
char ch;
while((ch=getchar())!='\n' && ch!=EOF);

for(i=start; i<end; i++) {
attemp=0;
printf("\n====Employees details %d========\n", i+1);
do{
found=0;
printf("Identity Number: ");
fgets(id, sizeof(id), stdin);
id[strcspn(id, "\n")]='\0';
for(j=0; j<i; j++) {
if(strcmp(emp[j].employee_id, id)==0) {
found=1;
break;
}

}
if(found==1) {
printf("Employee identity number exist. please try again.\n");
}else {
strcpy(emp[i].employee_id, id);
}
if(attemp>5) {
printf("Please make use of login.\n");
return;
}
attemp++;

}while(found==1);

printf("Full Name: ");
fgets(emp[i].full_name, sizeof(emp[i].full_name), stdin);
emp[i].full_name[strcspn(emp[i].full_name, "\n")]='\0';

printf("Salary: ");
scanf("%f", &emp[i].salary);
while(getchar()!='\n');
printf("...............................................................\n");


}

printf("\nThe employee records have successfull added.\n");
}

struct employee *AddMoreEmployee(struct employee *emp, int *size) {
int extra;
printf("How many Employee do you want to add? ");
if(scanf("%d", &extra)!=1) {
printf("Invalid entery.\n");
while(getchar()!='\n');
return emp;
}
if(extra<=0) {
printf("Invalid number of Employee.\n");
return emp;
}

struct employee *hello;
hello=realloc(emp, (*size+extra)*sizeof(struct employee));

if(hello==NULL) {
printf("Memory allocation failed");

return emp;
}

emp=hello;
InputEmployee(emp, *size, (*size+extra));
*size+=extra;

return emp;
}

void DisplayEmployee(struct employee *emp, int size) {
if(emp==NULL || size<=0) {
printf("No employees records available.\n");

return;
}

int i;
for(i=0; i<size; i++) {
printf("\n======Employee details %d==========\n", i+1);
PrintEmployee(emp, i);
printf(".................................................................\n");
}
printf("\n");

printf("Total number of employees: %d\n", size);
}

int main() {
int size, choice;
do{
size=0;
printf("How many employee do you want to add initial? ");
if(scanf("%d", &size)!=1) {
printf("Invalid entery.\n");
while(getchar()!='\n');
continue;
}

if(size<=0) {
printf("Please enter number greater than a zero.\n");
continue;
}

}while(size<=0);
struct employee *emp;
emp=calloc(size, sizeof(struct employee));
if(emp==NULL) {
printf("Memory allocation failed.\n");
return 0;
}
InputEmployee(emp, 0, size);
do{
choice=0;
printf("\n==============================================\n");
printf("WELCOME TO EMPLOYEES MANAGEMENT SYSTEM.\n");
printf(".........................................................................................................\n");
printf("\n1. Add More Employee.\n");
printf("2. Display Employees.\n");
printf("3. Ext.\n");
printf("<><><><><><><><><><><><><><><><><>.\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');

continue;

}
printf("<<<<<<<<<<<<<<<<<>>>>>>>>>>>>\n");

switch(choice) {
case 1: emp=AddMoreEmployee(emp, &size);break;
case 2: DisplayEmployee(emp, size); break;
case 3: printf("Thanks for using our Employee management system.\n "); break;
default: printf("Invalid choice. Please try again.\n"); break;
}

}while(choice!=3);
free(emp);

return 0;
}
