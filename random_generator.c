#include <stdio.h>
 #include <stdlib.h>

int main (void) {
    
    int seed;
    int x, y, z;
    printf("Enter the seed value: ");
    /*Given the interface for the function srand is:
    void srand(unsigned int seed)
    This function initializes random number generator used by the function rand with the seed given
    And the interface for the function rand is:
    int rand(void)
    Returns a pseudo-random number in the range of 0 to RAND_MAX. */
    scanf("%d", &seed);
    srand (seed);
    x = rand ();
    y = rand ();
    z = rand ();
    
    printf("Seed value is: %d\n", seed);
       
    
    printf("random numbers are:\n%d\n%d\n%d\n", x, y, z);
    system("PAUSE");
    return 0;
}