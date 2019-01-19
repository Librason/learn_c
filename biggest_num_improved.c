/* Purpose: to find out the biggest number entered by the user */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int value;
    int biggest_val = -1;

    printf("Please enter a value:\n");
    scanf("%d", &value);

    if (value == -1)
    {
       printf("Error: No data input!\n"); 
    }
    else
    {
        biggest_val = value;
        while(value != -1){
            scanf("%d", &value);
            if(value > biggest_val){
                biggest_val = value;
            }
        }
        printf("The biggest value is %d.\n", biggest_val);
    }
    system("PAUSE");
    return 0;
}
