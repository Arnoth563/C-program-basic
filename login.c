#include <stdio.h>
#include <string.h>
struct customer {
char identity[20];
char full_name[60];
char password[15];

};
int main() {
struct customer v;
struct customer b;
int found=0, attempts=0, choice;
FILE*bv;
do{
printf("Welocome to the loginsystem.\n");
printf("Enter your user name: ");
fgets(v.identity, sizeof(v.identity), stdin);
v.identity[strcspn(v.identity, "\n")]='\0';
printf("Enter your password: ");
fgets(v.password, sizeof(v.password), stdin);
v.password[strcspn(v.password, "\n")]='\0';
bv=fopen("longin.dat", "rb");
if(bv==NULL) {
    printf("Erro opening file.\n");
    return 0;
}
while(fread(&b, sizeof(struct customer), 1, bv)==1) {
    if(strcmp(v.identity, b.identity)==0 && strcmp(v.password, b.password)==0){
        found=1;
        break;
    }
}
fclose(bv);
if(found==1){
    printf("Login successful.\n Welcome, %s!\n", b.full_name);
return 0;
}

if(attempts==3){
printf("Too many failed login attempts. Please try again later.\n");
return 0;
}
attempts++;
printf("Invalid username or password. Please try again.\n");
printf("Enter 0 to try again or 1 to exit: ");
scanf("%d", &choice);
while (getchar() != '\n'); // Clear the input buffer

}while(found==0 && choice==0);




    return 0;
}