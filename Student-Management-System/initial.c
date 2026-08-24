#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
char full_name[100];
char student_no[25];
char gender[10];
int marks;
};

void PrintStudent(struct student *stud, int position) {

printf("Full name: %s\n", stud[position].full_name);
printf("Student Number: %s\n", stud[position].student_no);
printf("Gender: %s\n", stud[position].gender);
printf("Marks : %d\n", stud[position].marks);
}
/*Function 1: InputStudent()
purpose of the function
New students
Added students after realloc()
*/

void InputStudent(struct student *stud, int start, int end) {
int i, j, found, file_size;
char student_number[25];
char ch;
struct student temp;
FILE*fp;
while(ch=getchar()!='\n' && ch!=EOF);
for(i=start; i<end; i++) {
printf("\n--------Student details %d-------------\n", i+1);
printf("Enter full name: ");
fgets((stud+i)->full_name, sizeof((stud+i)->full_name), stdin);
(stud+i)->full_name[strcspn((stud+i)->full_name, "\n")]='\0';
do{
found=0;
printf("Enter student number: ");
fgets(student_number, sizeof(student_number), stdin);
student_number[strcspn(student_number, "\n")]='\0';
for(j=0; j<i; j++) {
if(strcmp((stud+j)->student_no, student_number)==0) {
found=1;
break;
}

}

if(found==0) {
fp=fopen("initial.dat", "rb");
if(fp!=NULL) {

fread(&file_size, sizeof(int), 1, fp);

while(fread(&temp, sizeof(struct student), 1, fp)==1) {
if(strcmp(temp.student_no, student_number)==0){
found=1;
break;
}

}


fclose(fp);

}

}

if(found==1) {
printf("Student number exist please use a different one.\n");
}else if(found==0){
strcpy((stud+i)->student_no, student_number);
}

}while(found==1);

printf("Enter Gender: ");
fgets((stud+i)->gender, sizeof((stud+i)->gender), stdin);
(stud+i)->gender[strcspn((stud+i)->gender, "\n")]='\0';
printf("Enter Marks: ");
scanf("%d", &(stud+i)->marks);

while(getchar()!='\n');
printf("<>>>>>>>>>>>>>>><>\n");

}

printf("\n");
char save_choice;

printf("\nStudent records have been added successfully.\n");
printf("Would you like to save the records now? (Y/N): ");
scanf(" %c", &save_choice);

if(save_choice == 'Y' || save_choice == 'y') {
    SaveStudent(stud, end);
}

}
//Function 2: DisplayStudent()

void DisplayStudent(struct student *stud, int size) {
int i;

if(stud==NULL || size<=0) {
printf("No student records  available.\n");
return;
}

for(i=0; i<size; i++) {
printf("\n===Student details %d=====\n", i+1);
PrintStudent(stud, i);
printf(".....................................................\n");

}

printf("\n");

}

//Function 3: AddMoreStudent()

struct student *AddMoreStudent(struct student *stud, int *size) {
int i, extra;
printf("How many student do you want to add? ");
if(scanf("%d", &extra)!=1) {
printf("Invalid input please try again.\n");
while(getchar()!='\n');

return stud;
}
if(extra<=0) {
printf("Invalid  number of student!\n");
return stud;
}
struct student *temp;
temp=realloc(stud, (*size+extra)*sizeof(struct student));
if(temp==NULL) {
printf("Memory allocation failed.\n");

return stud;
}
stud=temp;
InputStudent(stud, *size, (*size+extra));
*size+=extra;
return stud;
}
//Function 4: SearchStudent()
void SearchStudent(struct student *stud, int size) {
int i, found=0, found_position=0, attempt=0, choice=0;
char name[100], number[25];
if(stud==NULL || size<=0) {
printf("No student record available.\n");

return;
}

do{
printf("\n=========Choice to search using the detail below\n===================\n");
printf("1. Full Name.\n");
printf("2. Student Number.\n");
printf("3.Exit.\n");
printf("............................................\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
continue;
}
printf("\n@@@@@@@@@@\n");
while(getchar()!='\n');
switch(choice) {
case 1: found=0;
printf("Enter full name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")]='\0';
if(stud==NULL) {
printf("Database is empty.\n");

return;
}

for(i=0; i<size; i++) {
if(strcmp((stud+i)->full_name, name)==0) {
found=1;
found_position=i;
break;
}

}

if(found==1) {
printf("\n----------Student Found------------------\n");
PrintStudent(stud, found_position);
printf(".....................................................\n");
return;
}else {
printf("Student not found. please try again.\n");
}
break;
case 2:found=0;
printf("Enter student number: ");
fgets(number, sizeof(number), stdin);
number[strcspn(number, "\n")]='\0';
if(stud==NULL) {
printf("Database is empty.\n");

return;
}

for(i=0; i<size; i++) {
if(strcmp((stud+i)->student_no, number)==0) {
found=1;
found_position=i;
break;
}

}

if(found==1) {
printf("\n----------Student Found------------------\n");
PrintStudent(stud, found_position);
printf(".....................................................\n");
return;
}else {
printf("Student not found. please try again.\n");
}
break;
case 3: printf("Thank you for using our system.\n"); return;
default: printf("\nInvalid entery. please try again.\n"); continue;
}
attempt++;

if(attempt>=4) {
printf("You have reached the maximum number of search attempts.\n");
return;
}

}while(choice!=3);

printf("\n");
}

//Function 5: UpdateStudent()
void UpdateStudent(struct student *hello, int size) {
int i, j, found=0, found_position=0, choice=0, attempt=0, found_student;
char name[100];
char number[25];
char update;
if(hello==NULL || size<=0 ) {
printf("No student records availble.\n");
return;
}

do{
choice=0;
found=0;
printf("\n<><><><><><><><\n");
printf("Search student by the details below.\n");
printf("===================\n");
printf("\n1. Full name.\n");
printf("2. Student number.\n");
printf("3. Exit.\n");
printf("*********************\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
continue;
}
printf("@@@@@@@@@\n");
while(getchar()!='\n');

switch(choice) {
case 1: printf("Enter full name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")]='\0';
for(i=0; i<size; i++) {
if(strcmp((hello+i)->full_name, name)==0) {
found=1;
found_position=i;
break;
}

}
break;
case 2: printf("Enter Student Number: ");
fgets(number, sizeof(number), stdin);
number[strcspn(number, "\n")]='\0';
for(i=0; i<size; i++) {
if(strcmp((hello+i)->student_no, number)==0) {
found=1;
found_position=i;
break;
}

}
break;
case 3: printf("Thanks for interacting with the system Goodbey.\n"); return;
default: printf("Invalide entery please try again.\n"); continue;

}

if(found==1) {
printf("\n=======Student found==========\n");
PrintStudent(hello, found_position);
printf("\n-----------\nDo you want to update student profile\n................\n");
printf("Enter  Y  an key to not update: ");
scanf(" %c", &update);
if(update== 'Y' || update== 'y') {
while(getchar()!='\n');
printf("\n====Enter new student details to update========\n");
printf("Full name: ");
fgets((hello+found_position)->full_name, sizeof((hello+found_position)->full_name), stdin);
(hello+found_position)->full_name[strcspn((hello+found_position)->full_name, "\n")]='\0';
printf("Gender: ");
fgets((hello+found_position)->gender, sizeof((hello+found_position)->gender), stdin);
(hello+found_position)->gender[strcspn((hello+found_position)->gender, "\n")]='\0';
printf("Marks: ");
if(scanf("%d", &(hello+found_position)->marks)!=1) {
printf("Invalid marks entered.\n");
while(getchar()!='\n');
continue;
}
while(getchar()!='\n');
do{
found_student=0;
printf("Student Number: ");
fgets((hello+found_position)->student_no, sizeof((hello+found_position)->student_no), stdin);
(hello+found_position)->student_no[strcspn((hello+found_position)->student_no, "\n")]='\0';
for(j=0; j<size; j++) {
if(j!=found_position && strcmp((hello+found_position)->student_no, (hello+j)->student_no)==0) {
found_student=1;
break;
}
}
if(found_student==1) {
printf("The student number already exist try again.\n");
}

}while(found_student==1);
printf("\n====================================\n");
printf("Student record successfully updated.\n");
printf("====================================\n");

}else {
printf("Thanks for using the interface.\n");
return;
}
}else {
printf("Student not found.\n");
}
attempt++;

if(attempt>=4) {
printf("You have reached maximum search attempts.\n");
return;
}


}while(choice!=3);

}

//Function 6: DeleteStudent()
struct student *DeleteStudent(struct student *stud, int *size) {
int i, position, found, choice, attempt=0;
char delete;
struct student *temp;
char name[100], number[25];

if(stud==NULL || *size<=0) {
printf("No student records available");
return stud;
}

do{
choice=0;
found=0;
printf("\n========================================\n");
printf("Choice from below to search a student to delete \n");
printf("..................................................................................................\n");
printf("\n1. Full name\n");
printf("2. Student Number\n");
printf("3.Exit.\n ");
printf("__________________________________________________\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
continue;
} 
while(getchar()!='\n');
switch(choice) {
case 1: printf("Enter Full name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name,"\n")]='\0';
for(i=0; i< *size; i++) {
if(strcmp((stud+i)->full_name, name)==0) {
found=1;
position=i;
break;
}

}
break;
case 2:printf("Enter Student Number: ");
fgets(number, sizeof(number), stdin);
number[strcspn(number,"\n")]='\0';
for(i=0; i< *size; i++) {
if(strcmp((stud+i)->student_no, number)==0) {
found=1;
position=i;
break;
}

}
break;
case 3: printf("Thanks for interacting with the interface.\n"); return stud;
default: printf("invalid choice please try again"); continue;
}
if(found==1) {
printf("\n______Student found_________\n");
PrintStudent(stud, position);
printf("<>>>><<<<<<<><>\n");
printf("\nDo you really want to delete this student?\n");
printf("Enter Y to delete or any key to keep the record: ");
scanf(" %c", &delete);

while(getchar()!='\n');//Clear Input buffer
if(delete== 'Y' || delete== 'y') {
for(i=position; i< *size-1; i++) {
*(stud+i)= *(stud+i+1);
}
(*size)--;
if( *size==0) {
printf("Student successfully deleted.\n");
free(stud);

return NULL;
}
temp=realloc(stud, (*size)*sizeof(struct student));
if(temp==NULL) {
printf("Memory allocation failed.\n");

return stud;
}
stud=temp;
printf("Student successfull deleted.\n");
return stud;
}else {
printf("No changes were made.\n");
}

}else {
printf("Student not found. Please try again.\n");
}

attempt++;
if(attempt>=4) {
printf("You have been search for a while now try again in few minutes.\n");
return stud;
}

}while(choice!=3);

return stud;
}
//Function 7: StatisticReport()

void StatisticReport(struct student *stud, int size) {
if(size<=0 || stud==NULL) {
printf("No student records avalible.\n");
return;
}
int i, j, count, max_count, mode, highest, lowest, highest_position, lowest_position;
int already_count=0, sum_marks=0, num;
float mean, median;
int *temp;
temp=(int *)malloc(size*sizeof(int));
if(temp==NULL) {
printf("Memory allocation failed.\n");
return;
}

for(i=0; i<size; i++) {
temp[i]=(stud+i)->marks;
}
for(i=0; i<size-1; i++) {

for(j=i+1; j<size; j++) {

if(temp[i]>temp[j]) {
num=temp[i];
temp[i]=temp[j];
temp[j]=num;

}

}

}

if(size%2==0) {
median=(float)((temp[(size/2)-1])+(temp[size/2]))/2.00;
}else{
median=(float)(temp[size/2]);
}
free(temp);
count=0;
max_count=0;
mode= (stud+0)->marks;

for(i=0; i<size; i++) {
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

if(lowest>(stud+i)->marks) {
lowest=(stud+i)->marks;
lowest_position=i;

}

sum_marks+= (stud+i)->marks;
}

mean= (float)sum_marks/size;

printf("\n========================\n");
printf("STUDENT STATISTICS REPORT\n");
printf("______________________________\n");
printf("Number of student: %d\n", size);
printf("\n...........Highest student....................\n");
PrintStudent(stud, highest_position);
printf("\n...........Lowest student....................\n");
PrintStudent(stud, lowest_position);
printf("\n__________\n");
printf("Median marks: %.2f\n", median);
printf("...........................\n");
printf("\n==============\n");
printf("Mean marks: %.2f\n", mean);
printf("------------------------\n");
printf("\n<><><><><><><><><>\n");
if(max_count<=1) {
printf("All marks occured once.\n");
}else {
printf("Mode marks: %d\n", mode);
}
printf("<<<<<>>>>>>>>>>>\n");

}
//Function 8: SaveStudentFile()
void SaveStudent(struct student *stud, int size) {
FILE*file;

if(stud==NULL || size<=0) {
printf("No student records available to save.\n");
return;
}
file=fopen("initial.dat", "wb");

if(file==NULL) {
printf("failed to open file for writting.\n");
return;
}

if(fwrite(&size, sizeof(int), 1, file)!=1) {
printf("Failed to save size information.\n");
fclose(file);
return;
}

if(fwrite(stud, sizeof(struct student), size, file)!=size) {
printf("Failed student records in the file.\n");
fclose(file);
return;
}

fclose(file);
printf("\n---------\nData successfull saved\n==========\n");
return;
}
// Function 9: LoadFromFile(struct *stud, int *size)
struct student *LoadFromFile(struct student *stud, int *size) {

if(size == NULL) {
    printf("Invalid parameter.\n");
    return stud;
}
FILE*fp;
fp=fopen("initial.dat", "rb");
if(fp==NULL) {
printf("File does not exist.\n");
return stud;
}

if(fread(size, sizeof(int), 1, fp)!=1) {
printf("Failed to read file header.\n");
fclose(fp);
return stud;
}
if( *size<1 || *size> 10000) {
printf("Invalid file format.\n");
fclose(fp);
return NULL;
}
struct student *sut;
sut=realloc(stud, (*size)*sizeof(struct student));
if(sut==NULL) {
printf("Memory allocation failed.\n");
fclose(fp);
return stud;
}
stud=sut;
if(fread(stud, sizeof(struct student), *size, fp)!= *size) {
printf("Failed to load student record.\n");
fclose(fp);
free(stud);
return NULL;
}


fclose(fp);
printf("Data successfull loaded.\n");
return stud;
}
int main() {
int size=0, start_choice, choice;
struct student *gang=NULL;
do{
start_choice=0;
printf("\n_____________________\n");
printf("WELCOME\n");
printf(">>>>>>>>>><<<<<<<<<<<<\n");
printf("\n1. New student database\n");
printf("2. Load student database\n");
printf("3. Exit\n");
printf("---------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &start_choice)!=1){
while(getchar()!='\n');

continue;
}
printf("<<<<<<<>>>>>>>\n");

if(start_choice<1 || start_choice>3) {
continue;

}

switch(start_choice) {
case 1: printf("How many student do you want to add initial? ");
scanf("%d", &size);
if(size<=0) {
printf("Invalid number of student.\n");
continue;
}

gang=calloc(size, sizeof(struct student));

if(gang==NULL) {
printf("Memory allocation failed.\n");
return 0;
}
InputStudent(gang, 0, size);
printf("Initial student successful  entered.\n"); break;
case 2: {struct student *temp;
temp=LoadFromFile(gang, &size);
if(temp!=NULL) {
gang=temp;
}else {
printf("Failed to load from file.\n");
}
break;
}
case 3: printf("Thank you for interacting with the interface.\n"); return 0; 
}

}while(start_choice<1 || start_choice>3);


do{
choice=0;
printf("\n===============================\n");
printf("STUDENT MANAGEMENT SYSTEM\n");
printf("=================================\n");
printf("\n1. Add Students\n");
printf("2. Display Students\n");
printf("3. Search Student\n");
printf("4. Update Student\n");
printf("5. Delete Student\n");
printf("6. Statistics Report\n");
printf("7. Save Students To File\n");
printf("8. Load Students From File\n");
printf("9. Exit\n");
printf("........................................................\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');

continue;
}
printf("-------------------------\n");

if(choice<1 || choice>9) {
while(getchar()!='\n');
continue;
}

switch(choice) {
case 1: gang=AddMoreStudent(gang,  &size); break;
case 2: DisplayStudent(gang, size); break;
case 3: SearchStudent(gang, size); break;
case 4: UpdateStudent(gang, size); break;
case 5: gang=DeleteStudent(gang, &size);
if(gang==NULL) {
printf("No record is available to delete.\n");
}
break;
case 6: StatisticReport(gang, size); break;
case 7: SaveStudent(gang, size); break;
case 8: gang=LoadFromFile(gang, &size);
if(gang==NULL) {
printf("Failed to load from file.\n");

};
break;
case 9: printf("Thanks for using our system.\n"); break;

}

}while(choice!=9);

free(gang);

return 0;
}