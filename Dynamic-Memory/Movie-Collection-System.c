#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct movie {
char movie_title[100];
int year;
float rating;

};
void PrintMovie(struct movie *movi, int position) {
printf("Movie Title: %s\n", movi[position].movie_title);
printf("Year: %d\n", movi[position].year);
printf("Rating: %.1f\n", movi[position].rating);
}
void InputMovie(struct movie *movi, int start, int end) {
if(start>end) {
printf("Invalide number of movies.\n");
return;
}
int ch;
while((ch=getchar())!='\n' && ch!=EOF);
int i, j, found=0;
struct movie mov;
for(i=start; i<end; i++) {
printf("\n=======Movie details %d==============\n", i+1);
do{
found=0;
printf("Movie Title: ");
fgets(mov.movie_title, sizeof(mov.movie_title), stdin);
mov.movie_title[strcspn(mov.movie_title, "\n")]='\0';
for(j=0; j<i; j++) {
if( strcmp(movi[j].movie_title, mov.movie_title)==0) {
found=1;
break;
}
}
if(found==0) {
    strcpy(movi[i].movie_title, mov.movie_title);
}else {
    printf("Movie exist. Please make use of different title.\n");
}


}while(found==1);

printf("Year: ");
if(scanf("%d", &movi[i].year)!=1 || movi[i].year<=0) {
printf("Invalide year entered.");
while(getchar()!='\n');
i--;
continue;
}

printf("Rating: ");
if(scanf("%f", &movi[i].rating)!=1 || movi[i].rating<0 || movi[i].rating>10) {
printf("Invalid rating value.\n");
while(getchar()!='\n');
i--;
continue;
}

while(getchar()!='\n');
printf("................................................................\n");

}
if(end>1) {
printf("Movies successful added.\n");
}else {
printf("Movie successful added.\n");
}

return; 
}

void DisplayMovies(struct movie *movi, int size) {
if(movi==NULL || size<=0) {
printf("No movie records available.\n");

return;
}
int i;

for(i=0; i<size; i++) {
printf("\n=======Movie detail %d============\n", i+1);
PrintMovie(movi, i);
printf("______________________________________\n");

}
if(size>1) {
printf("Total movies: %d\n", size);
}else {
printf("The is only one movie available.\n");
}

return;
}

struct movie *AddMoreMovies(struct movie *movi, int *size) {
if(movi==NULL || *size<0) {
printf("Invalid number movie directory.\n");

return movi;
}
int extra;
printf("How many movies do you want to add? ");
if(scanf("%d", &extra)!=1 || extra<=0) {
printf("Invali Number entred to add movie.\n");
while(getchar()!='\n');
return movi;
}

struct movie *mov;
mov=realloc(movi, (*size+extra)*sizeof(struct movie));
if(mov==NULL) {
printf("Memory allocation failed.\n");

return movi;
}

movi=mov;
InputMovie(movi, *size, (*size+extra));
*size+=extra;

return movi;
}

void SearchMovie(struct movie *movi, int size) {
if(movi==NULL || size<=0) {
printf("No movie records available.\n");

return;
}
int i, found=0, found_position=0, attempt=0;
char search[100];
while(getchar()!='\n');

do{
found=0; 
printf("\n-------Search movie by it's title--------------------\n");
printf("Enter movie's title: ");
fgets(search, sizeof(search), stdin);
search[strcspn(search, "\n")]='\0';
for(i=0; i<size; i++) {
if(strcmp(movi[i].movie_title, search)==0) {
found=1;
found_position=i;
break;
}
}
if(found==1) {
printf("\n______Movie Found__________\n");
PrintMovie(movi, found_position);
printf("_______________________________\n");
}else {
printf("Movie Not Found. Please try again.\n");
}
attempt++;

if(attempt>=4) {
printf("You have reached maximum search attempt. please try again in next 2 minutes.\n");
return;
}

}while(found==0);

return;
}

struct movie *DeleteMovie(struct movie *movi, int *size) {
if(movi==NULL || *size<=0) {
printf("No movie records available.\n");
return movi;
}
int i, found=0, found_position=0, attempt=0;
char confirm;
char search[100];
while(getchar()!='\n');
do{
found=0;
printf("\n______ Search movie by it's title to delete____________\n");
printf("Movie title: ");
fgets(search, sizeof(search), stdin);
search[strcspn(search, "\n")]='\0';
for(i=0; i< *size; i++) {
if(strcmp(search, movi[i].movie_title)==0) {
found=1;
found_position=i;
break;
}

}

if(found==1) {
printf("\n______Movie Found__________\n");
PrintMovie(movi, found_position);
printf("............................................................\n");
printf("Do you really want to delete the movie? \nEnter y or Y to delete or any key to not\n");
scanf(" %c", &confirm);

if(confirm=='Y' || confirm=='y') {
for(i=found_position; i< *size-1; i++) {
movi[i]=movi[i+1];

}


(*size)--;

if(*size==0) {
printf("Movie successfully deleted.\n");
free(movi);
return NULL;
}
struct movie *mov; 
mov=realloc(movi, *size*sizeof(struct movie));

if(mov==NULL) {
printf("Memory Allocation failed.\n");
return movi;
}
movi=mov;
printf("Movie successfully deleted");

return movi;
}else {
printf("No changes were made.\n");
}


}else {
printf("Movie Title not found. Please try  search again.\n");
}

attempt++;
if(attempt>=4) {
printf("You have reached maximum search attempt. \nplease try searching again in next 5 minutes.\n");
return movi;
}

}while(found==0);

return movi;
}
int main() {
int size, choice=0;
printf("How many movie do you want to add initial.\n");
if(scanf("%d", &size)!=1 || size<=0) {
printf("Invalid entery of movies to add\n");
while(getchar()!='\n');
return 0;
}
struct movie *mov;
mov=calloc(size, sizeof(struct movie));
if(mov==NULL) {
printf("Memory allocation failed.\n");

return 0;
}

InputMovie(mov, 0, size);

do{
printf("\n====================================\n");
printf("Welcome to our movie management system.\n");
printf("__________________________________________\n");
printf("\n1. Add Movie.\n");
printf("2. Display Movies.\n");
printf("3. Search Movie.\n");
printf("4. Delete Movie.\n");
printf("5. Exit.\n");
printf("<<>>>>>>>>><<<<<>>>>>\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
printf("Invalid entery of choice.\n");
while(getchar()!='\n');
continue;
}

switch(choice) {
case 1: mov=AddMoreMovies(mov, &size); break;
case 2: DisplayMovies(mov, size); break;
case 3: SearchMovie(mov, size); break;
case 4: mov=DeleteMovie(mov, &size); break;
case 5: printf("Thank for using our system. Goodbey!\n"); break;
default: printf("Invalid choice. please try again.\n"); break;

}

}while(choice!=5);

free(mov);

return 0;
}
