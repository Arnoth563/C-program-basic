#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct budgets {
char department_name[100];
float budget_amount;

};

void PrintBudgets(struct budgets *bud, int position) {
printf("\nDepartment Name: %s\n", bud[position].department_name);
printf("Budget Amount: N$%.2f\n", bud[position].budget_amount);
}
void DisplayBudgets(struct budgets *bud, int size) {
if(bud==NULL || size<=0) {
printf("No budgets record is available.\n");

return;
}
int i;
for(i=0; i<size; i++) {
printf("\n=========Budget details %d===============\n", i+1);
PrintBudgets(bud, i);
printf(">>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

}
printf("Total budgets: %d\n", size);

return;
}
void InputBudgets(struct budgets *bud, int start, int end) {
if(start>end) {
printf("Invalid number of budget.\n");

return;
}
int i, j, found=0;
struct budgets budg;
char ch;
while(ch=(getchar()!='\n') && ch==EOF);
for(i=start; i<end; i++) {
printf("\n_____________Budgets details %d_______________\n", i+1);
do{
found=0;
printf("Department Name: ");
fgets(budg.department_name, sizeof(budg.department_name), stdin);
budg.department_name[strcspn(budg.department_name, "\n")]='\0';
for(j=0; j<i; j++) {
if(strcmp(bud[j].department_name, budg.department_name)==0) {
found=1;
break;
}

}

if(found==0) {
strcpy(bud[i].department_name, budg.department_name);
}else {
printf("Department name exist. please try to use a different name.\n");
}

}while(found==1);

printf("Enter budget amount: ");
if(scanf("%f", &bud[i].budget_amount)!=1 && bud[i].budget_amount<=0){
printf("Invalid budget amount.\n");
while(getchar()!='\n');
i--;
continue;
}

while(getchar()!='\n');
printf("........................................................\n");

}


printf("Budget details has been successful added.\n");

return;
}

struct budgets *AddMoreDepartment(struct budgets *bud, int *size) {
if(bud==NULL || *size<0) {
printf("Invalid number of department.\n");

return bud;
}
int extra;
printf("Enter the number of Deparment you want to add? ");
if(scanf("%d", &extra)!=1) {
printf("Invalid entery.\n");
while(getchar()!='\n');
return bud;
}

if(extra<=0) {
printf("Invalide number of department to add.\n ");
return bud;
}

struct budgets *temp;

temp=realloc(bud, (*size+extra)*sizeof(struct budgets));

if(temp==NULL) {
printf("Memory Allocation failed.\n");
return temp;
}

bud=temp;
InputBudgets(bud, *size, (*size+extra));
*size+=extra;

return bud;
}
void CalculateTotalBudgets(struct budgets *bud, int size) {
if(bud==NULL || size<=0) {
printf("No budgets record available.\n");
return;
}
float total_budget=0.00;
int i;
for(i=0; i<size; i++) {
total_budget+=bud[i].budget_amount;
}

printf("\n=========Total Budget =================\n");
printf("Total Budget: N$ %.2f\n", total_budget);
printf(">>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<\n");
printf("Number of Departments: %d\n", size);

return;
}

void HighestBudgetDepartment(struct budgets *bud, int size) {
if(bud==NULL || size<=0) {
printf("No budget records available.\n");

return;
}
int i, highest_position=0, j;
float highest= bud[0].budget_amount;

for(i=0; i<size; i++) {

if(highest<bud[i].budget_amount) {
highest=bud[i].budget_amount;
highest_position=i;
}

}

printf("\n=====Highest budget Department=============\n");
PrintBudgets(bud, highest_position);
printf("_______________________________________________\n");

return;
}
void UpdateBudget(struct budgets *bud, int size) {
if(bud==NULL || size<=0) {
printf("No budget records available.\n");
return;
}
char update;
struct budgets budg;
int i, j, found=0, found_position=0, update_found=0, attempt=0;
while(getchar()!='\n');

do{
found=0;
printf("\n========Search Department name======\n");
printf("Department name: ");
fgets(budg.department_name, sizeof(budg.department_name), stdin);
budg.department_name[strcspn(budg.department_name, "\n")]='\0';

for(i=0; i<size; i++) {
if(strcmp(bud[i].department_name, budg.department_name)==0) {
found=1;
found_position=i;
break;
}

}
if(found==1) {
printf("\n======Department name is found==============\n");
PrintBudgets(bud, found_position);
printf("________________________________________________\n");

printf("Do you really want to update the budget?\nEnter Y or y to update or any key to update: ");
scanf(" %c", &update);
while(getchar()!='\n');
if(update=='Y' || update=='y')  {
do{
update_found=0;
printf("\n=======Enter new budget details============\n");
printf("Department Name: ");
fgets(bud[found_position].department_name, sizeof(bud[found_position].department_name), stdin);
bud[found_position].department_name[strcspn(bud[found_position].department_name, "\n")]='\0';
for(j=0; j<size; j++) {
if(j!=found_position && strcmp(bud[j].department_name, bud[found_position].department_name)==0) {
update_found=1;
break;
}
}

if(update_found==1) {
printf("Department exist. please try again.\n");
}


}while(update_found==1);

printf("Budget Amount: ");
if(scanf("%f", &bud[found_position].budget_amount)!=1) {
printf("Invalid budget amount entered.\n");
while(getchar()!='\n');
continue;
}

printf("\n==============================\n");
printf("Department Successfull updated.\n");
printf("__________________________________\n");
PrintBudgets(bud, found_position);
}else {
printf("No changes were changed.\n");
}
return;
}else {
printf("Department name not found.\n");
}

attempt++;
if(attempt>=4) {
printf("Thanks for interacting with our interface.\n");

return;
}


}while(found==0);



return;
}
int main() {
int size, choice=0;
printf("How many department do you want to add initial? ");
if(scanf("%d", &size)!=1) {
printf("Invalid value entered.\n");

while(getchar()!='\n');
return 0;
}

if(size<=0) {
printf("Invalid number entered to add a department.\n");

return 0; 
}

struct budgets *budg;
budg=calloc(size, sizeof(struct budgets));

if(budg==NULL) {
printf("Memory allocation failed.\n");

return 0;
}

InputBudgets(budg, 0, size);

do{
printf("\n=============================================\n");
printf("Welcome to budgets department management system\n");
printf("______________________________________________________\n");
printf("\n1. Add More Departments.\n");
printf("2. Display Departments\n");
printf("3. Update Budget\n");
printf("4. Calculate Total Budget\n");
printf("5. Highest Budget Department\n");
printf("6. Exit\n");
printf("_____________________________________________________\n");
printf("Enter your Choice: ");
if(scanf("%d", &choice)!=1) {
printf("Invalid entery. please try again .\n");
while(getchar()!='\n');
continue;
}

printf(">>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");


switch(choice) {
case 1: budg=AddMoreDepartment(budg, &size); break;
case 2: DisplayBudgets(budg, size); break;
case 3: UpdateBudget(budg, size); break;
case 4: CalculateTotalBudgets(budg, size); break;
case 5: HighestBudgetDepartment(budg, size); break;
case 6: printf("Thank you for using our system.\n"); break;
default: printf("Invalid entery. please try again.\n"); break;
}

}while(choice!=6);

free(budg);



return 0;
}