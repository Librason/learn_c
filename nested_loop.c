#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int row = 1;
    int num_ast;
    int num_dol;
    int num_ast2;
    int num_dol2;
    int num_ast3;

    while (row <= 7){
        num_ast = (row - 1) * 2;
        num_dol = 7 - (row - 1);
        num_ast2 = 14 - (row - 1) * 2;
        num_dol2 = 7 - (row - 1);
        num_ast3 = (row - 1) * 2;

        while(num_ast > 0){
            printf("*");
            num_ast--;
        }
        sleep(1);
        while(num_dol > 0){
            printf("$");
            num_dol--;
        }
        sleep(1);
        while(num_ast2 > 0){
            printf("*");
            num_ast2--;
        }
        sleep(1);
        while(num_dol2 > 0){
            printf("$");
            num_dol2--;
        }
        sleep(1);
        while(num_ast3 > 0){
            printf("*");
            num_ast3--;
        }
        sleep(1);
        printf("\n");
        row++;
    }
    system("PAUSE");
    return 0;
}
