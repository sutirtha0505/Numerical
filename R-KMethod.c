#include<stdio.h>
#include<math.h>
float f(float x, float y){
    return x - y;
}
void main(){
    float h, x, y, q, k1, k2, k3, k4;
    printf("Enter the step length: ");
    scanf("%f", &h);
    printf("Enter the starting val of x: ");
    scanf("%f", &x);
    printf("Enter the starting val of y: ");
    scanf("%f", &y);
    printf("Enter the value of x for which you want to find the val of y: ");
    scanf("%f", &q);

    for(;x < q; x = x + h){
        k1 = h * f(x, y);
        k2 = h * f(x + h/2.0, y + k1/2.0);
        k3 = h * f(x + h/2.0, y + k2/2.0);
        k4 = h * f(x + h, y + k3);
        y = y + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);
        printf("\n For x = %f", x+h);
        printf("\n k1 = %f\n k2 = %f\n k3 = %f\n k4 = %f\n y = %f\n", k1, k2, k3, k4, y);
    }
    printf("f(%f) = %f", q, y);
}
