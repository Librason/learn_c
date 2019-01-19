/* Purpose: to find out the biggest number entered by the user */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int value;
    int nextval;
    int biggest_val;

    printf("Please enter a value:\n");
    scanf("%d", &value);

    if (value != -1)
    {
        scanf("%d", &nextval);
        if (nextval != -1)
        {
            if (nextval > value){
                biggest_val = nextval;
            }
            else{
                biggest_val = value;
            }
            scanf("%d", &nextval);

            while (nextval != -1){
                if (nextval > biggest_val){
                    biggest_val = nextval;
                }              
                else
                {
                    biggest_val = biggest_val;
                }
                scanf("%d", &nextval);               
            }
            sleep(2);
            printf("The biggest value is %d.\n", biggest_val);

        }
        else{
            biggest_val = value;
            printf("The biggest value is %d.\n", biggest_val);
        }


    }
    else
    {
        printf("Error: No data input!\n");
    }

    
    system("PAUSE");
    return 0;
}
