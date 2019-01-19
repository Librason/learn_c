#include <stdlib.h>
#include <stdio.h>
#define NUM_COLS 3

int sumDiagonal1(int a[][NUM_COLS]);
int sumDiagonal2(int a[][NUM_COLS]);

int main(void){

    int result;
    int my_matrix_1[NUM_COLS][NUM_COLS] = {{2, 7, 6},
                                           {9, 5, 1},
                                           {4, 3, 8}};
                                           
    int my_matrix_2[NUM_COLS][NUM_COLS] = {{2, 7, 6},
                                        {9, 5, 1},
                                        {4, 3, 9}};
    
    result = sumDiagonal1(my_matrix_1);
    printf("The sum fo the diagonal1 of my_matrix_1 is %d.\n", result);
    result = sumDiagonal2(my_matrix_1);
    printf("The sum fo the diagonal2 of my_matrix_1 is %d.\n", result);
    result = sumDiagonal1(my_matrix_2);
    printf("The sum of the diagonal1 of my_matrix_2 is %d.\n", result);
    result = sumDiagonal2(my_matrix_2);
    printf("The sum of the diagonal2 of my_matrix_2 is %d.\n", result);

    return 0;
}

int sumDiagonal1(int a[][NUM_COLS]){
    int row;
    int sum = 0;

    for(row = 0; row < NUM_COLS; row++){
        sum += a[row][row];
    }

    return sum;
}

int sumDiagonal2(int a[][NUM_COLS]){
    int row;
    int col = NUM_COLS - 1;
    int sum = 0;


    for(row = 0; row < NUM_COLS; row++){
        sum += a[row][col];
        col--;
    }
    return sum;
}