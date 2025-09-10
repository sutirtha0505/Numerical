#include <stdio.h>
#include <math.h>

float f(float x, float y){
    return ((y-x)/(y+x));
}

void main(){
    float h, x, y, q;
    printf("Enter the step length: ");
    scanf("%f", &h);
    printf("Enter the starting value of x: ");
    scanf("%f", &x);
    printf("Enter the starting value of y: ");
    scanf("%f", &y);
    printf("Enter the val of x for which y should be calculated: ");
    scanf("%f", &q);
    for(; x+h < q; x = x+h){
        y = y + h * f(x, y);
        printf("y(%f) = %f\n", x+h, y);
    }
    printf(" y = %f for x = %f", y, q);
}