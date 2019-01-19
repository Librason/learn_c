/* This program writes a certain number of rows of Pascal's 
   Triangle to the screen, as specified by the user.  
   We assume the number of rows is 12 or less.
  
   Author:      Paul Carter
   Date:        Oct. 6, 2006
   Modified by: Ed Knorr, Oct. 9, 2007
   Modified by: Paul Carter, Feb 2, 2010
*/

#include <stdio.h>
#include <stdlib.h>

#define MINROWS 1
#define MAXROWS 12

/* function prototypes */
int getInputInRange( int, int );
void printRow( int );
int n_choose_r( int, int );
int factorial( int );

int main( void ) {
    int row = 0;
    int numRows;

    numRows = getInputInRange( MINROWS, MAXROWS ); 
    
    while( row < numRows ) {
        printRow( row );
        printf( "\n" );
            
        row++;
    }
      
    system("PAUSE");
    return 0;
}

/*
 * Prompts user to enter an integer value 
 * between min and max, inclusive.  Prints an
 * error message and repeatedly prompts for 
 * input, if input it outside required range.
 *
 * Param: min - minimum acceptable input
 * Param: max - maximum acceptable input
 * Returns: number between min and max, inclusive,
 * entered by user.
 */
int getInputInRange( int min, int max ) {
    int userInput;

    printf( "Please enter integer value "
        "between %d and %d.\n", min, max );
    scanf( "%d", &userInput );

    while( userInput < min || userInput > max ) {
        printf( "Error: input not in expected range!\n\n" );
        printf( "Please enter integer value "
            "between %d and %d.\n", min, max );
        scanf( "%d", &userInput );
    }

    return userInput;
}

/*
 * Function to print the specified row
 * of Pascal's triangle.
 * Param: rowNum the row number to print
 */
void printRow( int rowNum ) {
    int position = 0;
    int coefficient;
       
    while( position <= rowNum ) {
         coefficient = n_choose_r( rowNum, position );
         printf( "%4i", coefficient );
         position++;      
    }
}

/*  
 * Function to compute C(n, r) = n! / (r! * (n - r)!)
 * 
 * Param: n 
 * Param: r
 * Returns: C(n, r)
 * Assume: n and r are positive integers
 */
int n_choose_r( int n, int r ) {   
    return factorial( n ) / ( factorial( r ) * factorial( n - r ) );
}

/*  
 * Function to compute n! (i.e., n factorial)
 *
 * Param: num - the number whose factorial we wish to compute
 * Returns: num!
 * Assume:  num is not negative; since n! grows very quickly, n should
 *           be <= 12 for most systems (else n! can't be stored
 *           in an int variable) 
 */
int factorial( int num ) {
    int fact = 1;
    
    while( num > 1 ) {
        fact *= num;
        num--;          
    }
    
    return fact;
}

