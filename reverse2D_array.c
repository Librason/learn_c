#include <stdio.h>
#include <stdlib.h>
#define ROW 4
#define COLUMN 3

void reverse(int a[][COLUMN], int r[][COLUMN], int row, int column);
void print_array(int a[][COLUMN], int row, int column);

int main(void){
    int array[][COLUMN] = {{1, 2, 3}, 
                            {4, 5, 6}, 
                            {7, 8, 9}, 
                            {10, 11, 12}};
    
    int reverse_array[][COLUMN] = {0};

    print_array(array, ROW, COLUMN);
    printf("\n");
    print_array(reverse_array, ROW, COLUMN);
    printf("\n");
    reverse(array, reverse_array, ROW, COLUMN);
    print_array(reverse_array, ROW, COLUMN);
    printf("\n");

    return 0;
}

void print_array(int a[][COLUMN], int row, int column){
    int num_row;
    int num_col;

    for(num_row = 0; num_row < row; num_row++){
        printf("{ ");
        for(num_col = 0; num_col < column; num_col++){
            printf("%d ", a[num_row][num_col]);
        }
        printf("}\n");
    }
}

void reverse(int a[][COLUMN], int r[][COLUMN], int row, int column){
    int num_row;
    int num_col;
    int r_row = ROW - 1;
    int r_col;

    for(num_row = 0; num_row < row; num_row++){
        r_col = COLUMN - 1;
        for(num_col = 0; num_col < column; num_col++){
            r[r_row][r_col] = a[num_row][num_col];
            r_col--;
        }
        r_row--;
    }
}