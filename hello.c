#include <stdio.h>
#include <stdlib.h>
#define PLACE_LENGTH 10
#define NAME_LENGHT 10
int main(void){
    char name[NAME_LENGHT];
    char place[PLACE_LENGTH];
    int age;


    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter the place you come from: ");
    scanf("%s", place);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Hello, %s.\nYou are %d years old, and you come from %s.\n",name, age, place);

    printf("------------\n");
    system("PAUSE");
    return 0;
}