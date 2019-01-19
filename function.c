#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int function1(void);
int function2(void);

int function1(void){
    double x;
    double y;
    printf("Please enter a value for x: ");
    scanf("%lf", &x);
    printf("Please enter a value for y: ");
    scanf("%lf", &y);
    printf("The sum of x and y is %lf\n", x + y);
    return 0;
}

int function2(void){
    double angle1, angle2;
    double length_ab, length_bc; 
    double c_x, c_y;
    printf("\n\nEnter length AB: ");
    scanf("%lf", &length_ab);
    printf("Enter length BC: ");
    scanf("%lf", &length_bc);
    printf("Enter angle 1 in radians: ");
    scanf("%lf", &angle1);
    printf("Enter angle 2 in radians: ");
    scanf("%lf", &angle2);

    c_x = length_ab * cos(angle1) + length_bc * cos(angle2);
    c_y = length_ab * sin(angle1) + length_bc * sin(angle2);

    printf("The coordinate is (%lf,%lf).\n", c_x, c_y);
    return 0;
}

int main(int argc, char const *argv[])
{
    function1();
    function2();
    system("PAUSE");
    return 0;
}

 
