#include <stdio.h>
#include <cmath>
int main()
{
    printf ("Hello World!\n");

    // Determine the number of seconds in December
    int seconds;
    seconds = 31 * 24 * 60;
    printf ("There are %i seconds in December!\n", seconds);

    // Calculate the area of a circle
    double radius = 6.2f;
    float pi = 3.14159f;
    float area = pi * pow(radius, 2);
    printf ("The area of a circle with radius of 6.2 is %f\n", area);

    int a = 13;
    int b = 7;
    int c = a / b;
    printf("Interger division results in rounding down. EX: 13/7 = %i", c);
}
