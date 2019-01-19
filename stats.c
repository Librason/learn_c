/*
 * Author: Paul Carter; revised: Farshid Aghareb 
 * Date revised : June 03, 2010
 * Purpose: Driver program to test stats functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function prototypes */
double average( double data[], int numEntries );
double minimum( double data[], int numEntries );
double variance( double data[], double avr, int numEntries );
double standardDeviation( double data[], double avr, int numEntries);

int main( void ) {
	/* NOTE: Seven different test data sets are used here. Each data  
	 * set is a one-dimensional array and an int value, numEntries. 
	 * 
	 * Try choosing different test cases by uncommenting them -
	 * be sure that only one set of test values is uncommented at
	 * a time.
	 */

    double test[] = { 1.0 };
    int numEntries = 1;


    /* double test[] = { 1.0, 3.0, 5.0 }; */
    /* int numEntries = 3; */

    /* double test[] = { -1.0, -3.0, -5.0 }; */
    /* int numEntries = 3; */

    /* double test[] = { 3.0, 1.0, 5.0 }; */
    /* int numEntries = 3; */

    /* double test[] = { 1.1, -5.4, 4.2, 6.5, -8.7, 9.1 }; */
    /* int numEntries = 6; */
    
    /* double test[] = { 1.1, -5.4, 4.2, 6.5, -8.7, 9.1 }; */
    /* int numEntries = 1; */
    
    /* double test[] = { 1.1, -5.4, 4.2, 6.5, -8.7, 9.1 }; */
    /* int numEntries = 3; */

    double avr;
    double var;
    double stdDev;
    double min;
    
    avr = average( test, numEntries );
    min = minimum( test, numEntries );

    printf( "Average = %f\n", avr );
    printf( "Minimum = %f\n", min );

    if( numEntries > 1 ) {
        var = variance( test, avr, numEntries );
        stdDev = standardDeviation( test, avr, numEntries );
        printf( "Variance = %f\n", var );
        printf( "Standard Deviation = %f\n", stdDev );
    }

    system( "PAUSE" );
    return 0;
}


/*
 * Computes and returns the average of the values in the first numEntries slots
 * of an array.
 *
 * Param: data - the array containing the data
 * Param: numEntries - average of first numEntries slots will be computed
 */
double average( double data[], int numEntries ) {
    int index;
    double sum = 0.0;

    for( index = 0; index < numEntries; index++ ) {
        sum += data[ index ];
    }

    return( sum / numEntries );
}


/*
 * Computes and returns the minimum value stored in slots 0 to (numEntries - 1) of
 * the array data.
 *
 * Param: data - the array containing the data
 * Param: numEntries - average of first numEntries slots will be computed
 */
double minimum( double data[], int numEntries ) {
    int index;
    double min = data[ 0 ];  /* assume minimum is first entry in array */

    for( index = 1; index < numEntries; index++ ) {
        if( data[ index ] < min )
            min = data[ index ];
    }

    return min;
}


/*
 * Computes and returns the variance of the values stored in slots 0 to (numEntries - 1)
 * of the array data.
 *
 * Param: data - the array containing the data
 * Param: avr - the average of the entries in first numEntries slots of array
 * Param: numEntries - variance of first numEntries slots will be computed
 *
 * Assumption: numEntries is at least 2.
 */
double variance( double data[], double avr, int numEntries ) {
    int index;
    double sumSqrs = 0.0;

    for( index = 0; index < numEntries; index++ ) {
        sumSqrs += ( data[ index ] - avr ) * ( data[ index ] - avr );
    }

    return( sumSqrs / ( numEntries - 1 ) );
}


/*
 * Computes and returns the standard deviation of the values stored in slots 0
 * to (numEntries - 1) of the array data.
 *
 * Param: data - the array containing the data
 * Param: avr - the average of the entries in first numEntries slots of array
 * Param: numEntries - std deviation of first numEntries slots will be computed 
 *
 * Assumption: numEntries is at least 2.
 */
double standardDeviation( double data[], double avr, int numEntries ) {
    return( sqrt( variance( data, avr, numEntries ) ) );  
}
