#include <stdio.h>
#include <stdlib.h>

int main(void){
    char A = 65; //A//
    int value = 65;

    printf("char is interchangable with int based on ASCII.\n");

    for(A; A <= 90; A++){
        printf("%c", A); //print uppercase char
        printf("-%d ", A); // print the number of upper char according to ASCII
        printf("%c", A + ' '); //print lowercase char
        printf("-%d\n", A + ' '); //print the number of lower char according to ASCII

    }
    printf("\n");

    for(value;value <= 90; value++){
        printf("%c ", value);
    }

    system("PAUSE");
    return 0;
}