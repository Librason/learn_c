#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char array[10] = "APSC160";
    char array2[100];
    char array3[20] = "computer science.";
    char alphabet;
   
    sprintf(array2, "%s %s %s", array, "is about", array3);
    printf("%s", array2);

    printf("\nlength: %d\n", strlen(array2));

    for(int i = 0; i < strlen(array2); i++){
        alphabet = array2[i];
        if(alphabet != ' ')
            printf("%c ", alphabet);
        else
            printf("\n");
    }
        
    printf("\n");
    // convert to uppercase
    for(int i = 0; i < strlen(array2); i++){
        if(array2[i] >= 'a' && array2[i] <= 'z')
            array2[i] -= 32;
        printf("%c", array2[i]);
    }
    
    printf("\n");
    system("pause");
    return 0;
}