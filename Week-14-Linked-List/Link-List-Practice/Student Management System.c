#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
char student_no[25];
char full_name[100];
int marks;

};
struct node {
struct student data;
struct node *next;
};
struct node *InputStudent(struct node *head) {
struct node *tail;
struct node *new_node;
struct node *temp;
int found;
new_node=malloc(sizeof(struct node));

if(new_node==NULL) {
printf("Memory allocation failed.\n");
return head;
}

printf("\n_________________Student details ________________________\n");
do{
found=0;
printf("Enter student number: ");
fgets(new_node->data.student_no, sizeof(new_node->data.student_no), stdin);
new_node->data.student_no[strcspn(new_node->data.student_no, "\n")]='\0';
temp=head;
while(temp!=NULL) {
if(strcmp(temp->data.student_no, new_node->data.student_no)==0) {
found=1;
break;
}
temp=temp->next;
}
if(found) {
printf("Student number already exist.Please make use of different one.\n");
}


}while(found);

printf("Enter Full name: ");
fgets(new_node->data.full_name, sizeof(new_node->data.full_name), stdin);
new_node->data.full_name[strcspn(new_node->data.full_name, "\n")]='\0';

do{
printf("Enter Marks: ");
if(scanf("%d", &new_node->data.marks)!=1) {
printf("Invalid marks entered. Please try again.\n");
while(getchar()!='\n');
new_node->data.marks=-1;
}

}while(new_node->data.marks<0);
printf("............................................................................................................\n");
new_node->next=NULL;

if(head==NULL) {
head=new_node;
}else{
tail=head;
while(tail!=NULL && tail->next!=NULL) {
tail=tail->next;
}
tail->next=new_node;
}

printf("The student successfully added to our list.\n");

return head;
}
void PrintStudent(struct node *head) {
if(head==NULL) {
printf("No student records available.\n");
return;
}
printf("Student Number: %s\n", head->data.student_no);
printf("Full Name: %s\n", head->data.full_name);
printf("Marks: %d\n", head->data.marks);
return;
}
void DisplayStudent(struct node *head) {
if(head==NULL) {
printf("No student records available.\n");
return;
}
struct node *current=head;
int count=0;

while(current!=NULL) {
count++;
printf("\n===============Student detail %d===============\n", count);
PrintStudent(current);
printf("_____________________________________________________\n");
current=current->next;
}

printf("\nTotal number of student: %d\n", count);

return;
}
struct node *AddStudent(struct node *head) {
int extra=0, i;
do{
printf("How many student do you want to add? ");
if(scanf("%d", &extra)!=1 || extra<=0) {
printf("Invalide number of student to add. Please try again.\n");
while(getchar()!='\n');
extra=0;
continue;
}

}while(extra<=0);

for(i=0; i<extra; i++) {
while(getchar()!='\n');
head=InputStudent(head);

}

printf("\nAll student successfull add.\n");

return head;
}
void SearchStudent(struct node *head) {

if(head==NULL) {
printf("No student records available.\n");
return;
}

struct node *current=NULL;
int found=0, choice=0, attempt=0;
char num[25], name[100];

do{
found=0;
printf("\n====================================\n");
printf("Search Student by the detail you have below.\n");
printf("_________________________________________\n");
printf("1. Student Number.\n");
printf("2. Full name.\n");
printf("3. Exit.\n");
printf("....................................................................................\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0) {
printf("Invalid choice entered.Please try again.\n");
while(getchar()!='\n');
continue;
}
printf("\n<><><><><><><><><><><><><>><><><>>>>>>\n");

while(getchar()!='\n');
current=head;
switch(choice) {
case 1:found=0; 
printf("Enter Student Number: ");
fgets(num, sizeof(num), stdin);
num[strcspn(num, "\n")]='\0';
while(current!=NULL) {
if(strcmp(num, current->data.student_no)==0) {
found=1;
break;
}
current=current->next;
}
break;
case 2: found=0;
printf("Enter full name: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")]='\0';
while(current!=NULL) {
if(strcmp(name, current->data.full_name)==0) {
found=1;
break;
}
current=current->next;
}
break;
case 3: printf("Thank you for using our system.Goodbey\n"); return;
default: printf("Invalid entered. Please try again.\n"); break;
}

if(found) {
printf("\n_______Student details found__________________\n");
PrintStudent(current);
printf("............................................................................................\n");
return;
}else {
printf("Student not found. Please try again.\n");
}

attempt++;
if(attempt>=4) {
printf("You have reached maximumu attempt.\n");
return;
}

}while(choice!=3);
return;
}
void  CountStudent(struct node *head) {
if(head==NULL) {
printf("No student records available.\n");
return;
}
struct node *current=head;
int count=0;
while(current!=NULL) {
count++;
current=current->next;
}
printf("The total number of student is: %d\n", count);
return;
}
void HighestMarksStudent(struct node *head) {
if(head==NULL) {
printf("No student records is available.\n");
return;
}
struct node *current=head;
int highest;
char highest_student_no[25], highest_name[100];
highest=current->data.marks;
strcpy(highest_student_no,current->data.student_no);
strcpy(highest_name,current->data.full_name);
current=current->next;
while(current!=NULL) {
if(highest<current->data.marks) {
highest=current->data.marks;
strcpy(highest_student_no,current->data.student_no);
strcpy(highest_name,current->data.full_name);
}
current=current->next;
}
printf("\n================Highest student details===========\n");
printf("Student Number: %s\n", highest_student_no);
printf("Full Name: %s\n", highest_name);
printf("Marks: %d\n", highest);
printf("___________________________________________________\n");

return;
}
void LowestMarksStudent(struct node *head) {
if(head==NULL) {
printf("No student records available.\n");
return;
}
struct node *current=head;
int lowest_marks;
char lowest_student_no[25], lowest_name[100];
lowest_marks=current->data.marks;
strcpy(lowest_student_no,current->data.student_no);
strcpy(lowest_name, current->data.full_name);
current=current->next;
while(current!=NULL) {
if(lowest_marks>current->data.marks) {
lowest_marks=current->data.marks;
strcpy(lowest_student_no, current->data.student_no);
strcpy(lowest_name, current->data.full_name);

}
current=current->next;
}

printf("\n________________The lowest student detail ____________________\n");
printf("Student Number: %s\n", lowest_student_no);
printf("Full Name: %s\n", lowest_name);
printf("Marks: %d\n", lowest_marks);
printf("<><><><><><><><><><><><>>><><><<<<><><><<<>><><>>>><>><>>\n");
return;
}
struct node *DeleteStudent(struct node *head) {
int ch;
while((ch=getchar())!='\n' && ch!=EOF);
struct node *current=NULL;
struct node *previous=NULL;
char num[25];
char confirm;
int found, attempt=0;
if(head==NULL) {
printf("No student records available.\n");

return NULL;
}
do{
found=0;
printf("Enter student number of student you want to delete: ");
fgets(num, sizeof(num), stdin);
num[strcspn(num, "\n")]='\0';
current=head;
previous=NULL;
while(current!=NULL) {
if(strcmp(num, current->data.student_no)==0) {
found=1;
break;
}
previous=current;
current=current->next;
}
if(found) {
printf("\n============Student Found===================\n");
PrintStudent(current);
printf("________________________________________________\n");
printf("Do you really want to delete the student details\n(Y or y to delete or any key to not): ");
scanf(" %c", &confirm);
while((ch = getchar()) != '\n' && ch != EOF);
if(confirm=='Y' || confirm== 'y') {
if(previous==NULL) {
head=current->next;
}else{
previous->next=current->next;
}
printf("Student successfully deleted.\n");
free(current);
}else{
printf("No changes were made.\n");
}
return head;
}else {
printf("Student detail not found.Please try again.\n");
}
attempt++;

if(attempt>=4) {
printf("You have reached maximum attempt. Please try again in next 5 minutes.\n");
return head;
}

}while(found==0);

return head;
}
int main() {
struct node *head=NULL;
struct node *tail=NULL;
int size=0, choice=0, i;
do{
printf("How many student detail do you want to add initial? ");
if(scanf("%d", &size)!=1 || size<=0) {
printf("Invalid number of student details to add. Please try again.\n");
while(getchar()!='\n');
size=0;
continue;
}
}while(size<=0);
for(i=0; i<size; i++) {
while(getchar()!='\n');
head=InputStudent(head);
}
do{

printf("\n==========================================\n");
printf("STUDENT LINKED LIST MANAGEMENT SYSTEM.\n");
printf("=============================================\n");
printf("1. Add Student.\n");
printf("2. Display Students.\n");
printf("3. Search Student.\n");
printf("4. Count Students.\n");
printf("5. Highest Mark Student.\n");
printf("6. Lowest Mark Student.\n");
printf("7.Delete Student.\n");
printf("8. Exit\n");
printf("......................................................................................................\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice< 1 || choice>8) {
printf("Invalid choice entered.Please try again.\n");
while(getchar()!='\n');
continue;
}
printf("<<<><><><<<<><><><<<<><><><<<<><><><<>>>><><><<<<>>>>>>\n");

switch(choice) {
case 1:head=AddStudent(head); break;
case 2: DisplayStudent(head);break;
case 3:SearchStudent(head); break;
case 4: CountStudent(head); break;
case 5: HighestMarksStudent(head); break;
case 6: LowestMarksStudent(head); break;
case 7: head=DeleteStudent(head); break;
case 8: printf("Thank you for using our system. Goodbey.\n"); break;
default: printf("Invalide choice entered. Please try again.\n"); break;
}

}while(choice!=8);

tail=head;
while(tail!=NULL) {
struct node *delete=tail;
tail=tail->next;
free(delete);
}


return 0;
}