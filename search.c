#include <stdio.h>
#include <string.h>
struct customer {
char identity[20];
char full_name[60];
char password[15];

};
int main() {
struct customer b;
char search[20];
int found, attempts=1, choice;
FILE*fg;
do{
found=0;
printf("Enter identity number to search customer: ");
fgets(search, sizeof(search), stdin);
search[strcspn(search, "\n")]='\0';// remove newline character
fg=fopen("login.dat","rb");
if(fg==NULL){
    printf("Error opening file.\n");
    return 0;
}
    while(fread(&b,sizeof(struct customer), 1, fg)==1) {
if(strcmp(search, b.identity)==0){
found=1;
printf("Customer found:\n");
printf("Identity: %s\n", b.identity);
printf("Full name: %s\n", b.full_name);
printf("Password: %s\n", b.password);
break;
}

    }

fclose(fg);
if(found==0){
    printf("Customer not found. Please try again.\n");
    printf("Enter 0 to search again or 1 to exit: ");
    scanf("%d", &choice);
    while (getchar() != '\n'); // Clear the input buffer
}
 attempts++;
 if(attempts==5) {
printf("Maximum attempts reached. Exiting.\n");
return 0;
 }

}while(found==0 && choice==0);

    return 0;
}

