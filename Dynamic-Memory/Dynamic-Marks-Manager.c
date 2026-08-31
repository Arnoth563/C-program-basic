#include <stdio.h>
#include <stdlib.h>
void PrintStudentMarks(int *marks, int position) {
printf("Marks: %d\n", marks[position]);
printf("\n");
}
void DisplayStudentMarks(int *marks, int size) {
int i;

for(i=0; i<size; i++) {
printf("\n========Student Marks %d=======\n", i+1);
PrintStudentMarks(marks, i);
printf("___________________________________\n");
}
printf("\n");
printf("Total student: %d\n", size);

}
void InputStudentMarks(int *marks, int start, int end) {
if(start>end) {
printf("Invalide number of student.\n");

return;
}

int i;
for(i=start; i<end; i++) {
printf("\n=========Enter student marks %d=========\n", i+1);
printf("Marks: ");
if(scanf(" %d", &marks[i])!=1) {
printf("Invalid mark entered.\n");
while(getchar()!='\n');
i--;
continue;

}
printf("................................................................................\n");
}
printf("\n");
printf("You have successfull added student marks.\n");
printf("<><><><><><><><><><><>\n");
}
int *AddMoreStudentMarks(int *marks, int *size) {
if(marks==NULL || *size<=0) {
printf("Invalide student marks.\n");

return marks;
}
int extra;
printf("How many student marks do you want to add? ");
if(scanf("%d", &extra)!=1){
printf("Invali value antered.\n");
while(getchar()!='\n');
}

if(extra<=0) {
printf("Invalide entery.\n");
return marks;
}
int *mark;
mark=realloc(marks, (*size+extra)*sizeof(int));

if(mark==NULL) {
printf("Memory Allocation failed.\n");

return marks;
}
marks=mark;
InputStudentMarks(marks, *size, (*size+extra));
*size+=extra;
return marks;
}

void MarksStatisticsReport(int *marks, int size) {
if(marks==NULL || size<=0) {
printf("No student marks records available.\n");

return;
}
int i, j, num, count, max_count, highest, lowest, highest_position, lowest_position, sum_marks, mode, already_count;
float median, mean;
int *mark;
mark=malloc(size* sizeof(int));
if(mark==NULL) {
printf("Memory Allocation failed.\n");
return;
}
mode=mark[0];
for(i=0; i<size-1; i++) {
for(j=i+1; j<size; j++) {
mark[i]=marks[i];
if( *(mark+i)> *(mark+j)) {
num= *(marks+i);
*(mark+i)= *(mark+j);
*(mark+j)=num;
}

}

}
if(size%2==0) {
median=(float)(mark[(size/2)-1]+ mark[size/2])/2.00;
}else {
median=(float)(mark[size/2]);
}

free(mark);
max_count=0;
count=0;

for(i=0; i<size; i++) {
already_count=0;
for(j=0; j<i; j++) {
if(marks[i]==marks[j]) {
already_count=1;
break;
}
}


if(already_count==1) {
continue;
}

count=1;

for(j=i+1; j<size; j++) {
if(marks[i]==marks[j]) {
count++;
}

}


if(count>max_count) {
max_count=count;
mode=marks[i];
}


}
sum_marks=0;
lowest= marks[0];
lowest_position=0;
highest=marks[0];
highest_position=0;
for(i=0; i<size; i++) {

if(lowest>marks[i]) {
lowest=marks[i];
lowest_position=i;
}

if(highest<marks[i]) {
highest=marks[i];
highest_position=i;

}
sum_marks+=marks[i];
}
mean=(float)sum_marks/size;

printf("\n===============================\n");
printf("Student Marks Statistics Report.\n");
printf("........................................................................\n");
printf("\nHighest marks\n");
PrintStudentMarks(marks, highest_position);
printf("__________________\n");
printf("\nLowest marks\n");
PrintStudentMarks(marks, lowest_position);
printf("________________\n");
printf("\n<><><><><><><><><>\n");
printf("Mean: %.2f\n", mean);
printf("..........................................\n");
printf("\n<<<<<<<<<>>>>>>>>>>>>\n");
printf("Median : %.2f\n", median);
printf("_____________________\n");
if(max_count==1) {
printf("All marks occured once.\n");
}else {
printf("\n<><><><><><><><><><><>\n");
printf("Mode: %d\n", mode);
printf("..................................................\n");
}


}
int main() {
int size, choice, attemp=0;
do{
printf("How many student marks do you want to add initial? ");
if(scanf("%d", &size)!=1) {
printf("Invalid input. Please try again.\n");
while(getchar()!='\n');
continue;
}
if(attemp>=3) {
printf("Thank you for interacting with our system. You have reached maximum attempts.\n");
return 0;
}
attemp++;

}while(size<=0);
int *marks;
marks=malloc(size*sizeof(int));
if(marks==NULL) {
printf("Memory allocation failed.\n");
return 0;
}

InputStudentMarks(marks, 0, size);
do{
choice=0;
printf("\n======================================\n");
printf("Welcome to student marks management system.\n");
printf("____________________________________________\n");
printf("\n1. Add Student Marks.\n");
printf("2. Display Student Marks.\n");
printf("3. Student marks Statistics Report.\n");
printf("4.Exit.\n");
printf("......................................................................................\n");
printf("Enter choice: ");
if(scanf("%d", &choice)!=1) {
printf("Invalid entery. Please try again.\n");
while(getchar()!='\n');
continue;
}
switch(choice) {
case 1: marks=AddMoreStudentMarks(marks, &size); break;
case 2: DisplayStudentMarks(marks, size);break;
case 3: MarksStatisticsReport(marks, size); break;
case 4: printf("Thank you for using our system.\n");break;
default: printf("Invalid choice. Please try agin.\n");break;

}


}while(choice!=4);

free(marks);
return 0;
}
