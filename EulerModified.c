#include <stdio.h>
#include <math.h>

float f(float x, float y){
    return x + y;
}
int main(){
    float h, x, y, q;
    printf("Enter the step length: ");
    scanf("%f", &h);
    printf("Enter the starting value for x : ");
    scanf("%f", &x);
    printf("Enter the starting value for y : ");
    scanf("%f", &y);
    printf("Enter the value of x to be calculated: ");
    scanf("%f", &q);

    printf("Step\t x\t y\t y_predict\t y_correct\n");
    int step = 1;
    for(; x < q; x = x+h){
        float y_predict = y + h * f(x, y); // Euler's prediction
        float y_correct = y + (h/2.0) * (f(x, y) + f(x + h, y_predict)); // Modified Euler
        printf("%d\t %.4f\t %.4f\t %.4f\t %.4f\n", step, x, y, y_predict, y_correct);
        y = y_correct;
        step++;
    }
    printf("Final result y(%.4f) = %.4f\n", q, y);
}