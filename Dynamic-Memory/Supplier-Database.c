#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct supplier {
char name[50];
char town[30];
char phone[20];

};
void PrintSupplier(struct supplier *supp, int position) {
printf("Full Name: %s\n", supp[position].name);
printf("Town: %s\n", supp[position].town);
printf("Phone number: %s\n", supp[position].phone);
}
void DisplaySupplier(struct supplier *supp, int size) {
if(supp==NULL || size<=0) {
printf("No supplier records available.\n");

return;
}

int i;

for(i=0; i<size; i++) {
printf("\n=======Supplier detail %d===============\n", i+1);
PrintSupplier(supp, i);
printf("__________________________________________\n");

}
printf("\n");
printf("Total supplier is: %d\n", size);

return;
}
void InputSupplier(struct supplier *supp, int start, int end) {
if(start>end) {
printf("Invalid supplier number entered.\n");

return;
}
char phone_no[20];
int i, j, found=0;
while(getchar()!='\n');
for(i=start; i<end; i++) {
printf("\n=========Supplier detail %d============\n", i+1);
printf("Full Name: ");
fgets(supp[i].name, sizeof(supp[i].name), stdin);
supp[i].name[strcspn(supp[i].name, "\n")]='\0';
printf("Town: ");
fgets(supp[i].town, sizeof(supp[i].town), stdin);
supp[i].town[strcspn(supp[i].town, "\n")]='\0';
do{
found=0;
printf("Phone number: ");
fgets(phone_no, sizeof(phone_no), stdin);
phone_no[strcspn(phone_no, "\n")]='\0';

for(j=0; j<i; j++) {
if(strcmp(supp[j].phone, phone_no)==0) {
found=1;
break;
}

}

if(found==0) {
strcpy(supp[i].phone, phone_no);
}else {
printf("Please make use of different phone number.\n");
}

}while(found==1);
printf("................................................................\n");


}

printf("Supplier successful added to the database.\n");

return;
}
//Add suppliers
struct supplier *AddSupplier(struct supplier *supp, int *size) {
int extra;
printf("How many suppliers do you want to add? ");
if(scanf("%d", &extra)!=1) {
printf("Invalid number of supplier to add entered.\n");
while(getchar()!='\n');
return supp;
}

if(extra<=0) {
printf("Invalid number of supplier to add.\n");

return supp;
}

struct supplier *sup;
sup=realloc(supp, (*size+extra)*sizeof(struct supplier));
if(sup==NULL) {
printf("Memory allocation failed.\n");
return supp;
}
supp=sup;
InputSupplier(supp, *size, (*size+extra));
*size+=extra;

return supp;
}
//Search supplier by name
void SearchSupplierByName(struct supplier *supp, int size) {
if(supp==NULL || size<=0) {
printf("No supplier records available.\n");
return;
}
int i, found=0, found_position=0, attempt=0;
char search[50];
do{
found=0;
while(getchar()!='\n');
printf("Enter name to search supplier: ");
fgets(search, sizeof(search), stdin);
search[strcspn(search, "\n")]='\0';

for(i=0; i<size; i++) {
if(strcmp(supp[i].name, search)==0) {
found=1;
found_position=i;
break;
}

} 

if(found==1) {
printf("\n=====Supplier found=========\n");
PrintSupplier(supp, found_position);
printf("__________________________\n");

return;
}

if(attempt>4) {
printf("You have been searching for a while now. Please try again in next 30 minutes.\n");

return;
}
attempt++;
printf("Supplier Not found. Please try again\n");

}while(found=0);

printf("\n");

return;
}

//Delete supplier

struct supplier *DeleteSupplier(struct supplier *supp, int *size) {
if(supp==NULL || *size<=0) {
printf("No supplier records available to delete.\n");

return supp;
}
int i, found=0, found_position=0, attempt=0, choice=0;
struct supplier sup;
char confirm;
do{
found=0;
printf("\n===============================================\n");
printf("Choice the details bellow to use it to delete supplier record.\n");
printf("________________________________________________________\n");
printf("\n1. Full Name.\n");
printf("2. Phone Number.\n");
printf("3. Exit. \n");
printf("..................................................................................................\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
continue;
}
printf("<><><><><><><><><><><><><><><><><><><>\n");
while(getchar()!='\n');
switch(choice) {
case 1: found=0;
printf("Enter full name: ");
fgets(sup.name, sizeof(sup.name), stdin);
sup.name[strcspn(sup.name, "\n")]='\0';
for(i=0; i< *size; i++) {
if(strcmp(supp[i].name, sup.name)==0) {
found=1;
found_position=i;
break;

}

}
break;
case 2:found=0;
printf("Enter Phone number: ");
fgets(sup.phone, sizeof(sup.phone), stdin);
sup.phone[strcspn(sup.phone, "\n")]='\0';
for(i=0; i< *size; i++) {
if(strcmp(supp[i].phone, sup.phone)==0) {
found=1;
found_position=i;
break;

}

}
break;
case 3: printf("Thanks for interacting with delete interface.\n"); return supp;
default: printf("Invalid entery. Please try again.\n"); continue;
}

if(found==1) {
printf("\n======Supplier found========\n");
PrintSupplier(supp, found_position);
printf("________________________________\n");
printf("\n");
printf("Do you want to delete the supplier record?\nEnter Y or y to delete or any key to not.\n");
scanf(" %c", &confirm);
if(confirm== 'Y' || confirm=='y') {
for(i=found_position; i< *size-1; i++) {
supp[i]=supp[i+1];

}
(*size)--;
if( *size==0) {
printf("Supplier deleted successful.\n");
free(supp);
return NULL;
}

struct supplier *temp;

temp=realloc(supp, *size*sizeof(struct supplier));
if(temp==NULL) {
printf("Memory Allocation failled.\n");
return supp;
}
supp=temp;
printf("Successfully deleted supplier record.\n");
return supp;
}else {
printf("No changes were made.\n");
continue;
}

}else {
printf("Student not found.Please try again.\n");
}

if(attempt>8) {
printf("You have reached maximum search attempt. Try again in next 40 minutes.\n");

return supp;
}
attempt++;

}while(choice!=3);

return supp;
}
int main() {
int size, choice=0;
printf("How many supplier do you want to add initial? ");
if(scanf("%d", &size)!=1) {
while(getchar()!='\n');

return 0;
}

if(size<=0) {
printf("Invalid number of supplier to add initial.\n");

return 0;
}
struct supplier *supp;
supp=calloc(size, sizeof(struct supplier));
if(supp==NULL) {
printf("Memory Allocation failed.\n");

return 0;
}

InputSupplier(supp, 0, size);

do{
printf("\n_____________________________________\n");
printf("Welcome to supplier management system.\n");
printf(">>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<\n");
printf("\n1. Add suppliers.\n");
printf("2. Search supplier by name.\n");
printf("3. Delete supplier.\n");
printf("4.Display suppliers.\n");
printf("5. Ext.\n");
printf("<><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
printf("Invalide entery. Please try again.\n");
while(getchar()!='\n');

continue;
}

switch(choice) {
case 1: supp=AddSupplier(supp, &size); break;
case 2: SearchSupplierByName(supp, size); break;
case 3: supp=DeleteSupplier(supp, &size); break;
case 4: DisplaySupplier(supp, size); break;
case 5: printf("Thank you for using our system.\n"); break;
default: printf("Invalid choice!\n"); break;

}


}while(choice!=5);

free(supp);


return 0; 
}
