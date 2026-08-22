#include <stdio.h>
#include <string.h>
struct customer {
char identity[20];
char full_name[50];
char password[15];

};
int main() {
struct customer c;
struct customer b;
char confirm[15];
int i, found, size, count;
printf("Enter the number of customers: ");
scanf("%d", &size);
while (getchar() != '\n'); // Clear the input buffer

FILE *fp;
    for(i=0; i<size; i++){
        found = 0;
        do{
            printf("-------Customer Registration %d-------\n", i+1);
printf("Enter identity number: ");
fgets(c.identity, sizeof(c.identity), stdin);
c.identity[strcspn(c.identity, "\n")] = '\0'; // Remove newline
fp=fopen("longin.dat","rb");
if(fp!=NULL){
while(fread(&b,sizeof(struct customer),1,fp)==1){
    if(strcmp(c.identity,b.identity)==0){
       
        found=1;
        break;
    }
}   

}
fclose(fp);
if(found==1) {
    printf("Identity number already exists. Please enter a different identity number.\n");
}

        }while(found==1);

printf("Enter full name: ");
fgets(c.full_name, sizeof(c.full_name), stdin); 
c.full_name[strcspn(c.full_name, "\n")] = 0; // Remove newline
printf("Enter password: ");
fgets(c.password, sizeof(c.password), stdin);
c.password[strcspn(c.password, "\n")] = 0; // Remove newline
do{
    printf("Confirm password: ");
    fgets(confirm, sizeof(confirm), stdin);
    confirm[strcspn(confirm, "\n")] = 0; // Remove newline
    if(strcmp(c.password, confirm) != 0){
        printf("Passwords do not match. Please try again.\n");
    }
    
}while(strcmp(c.password, confirm) != 0);
fp=fopen("login.dat","ab");
    if(fp==NULL){
        printf("Error opening file for writing.\n");
        return 0;
    }
    fwrite(&c,sizeof(struct customer),1,fp);
    fclose(fp);
printf("Registration successful!\n");

    }
    
    fp=fopen("login.dat","rb");
    if(fp==NULL){ 
        
        printf("Error opening file for reading.\n");
        return 0;
    }

    while (fread(&c,sizeof(struct customer), 1, fp)==1)
    {
        count=1;
       printf("Customer %d:\n", count);
       printf("Identity: %s\n", c.identity);
       printf("Full Name: %s\n", c.full_name);
       printf("Password: %s\n", c.password);
       printf("-----------------------\n");
       count++; 
    }
          fclose(fp);
    

 return 0;
}