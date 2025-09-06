#include <stdio.h>
#include <math.h>

double f(double x){
    return x*exp(x) - 1;
}

int main(){
    double x1n, xn, xn1, fx1n, fxn, tolerance = 0.0005;
    int step = 1;
    printf("Enter the value of lower bound: ");
    scanf("%lf", &x1n);
    printf("Enter the value of upper bound: ");
    scanf("%lf", &xn);
    printf("\tStep|\tx_(n-1)|\tx_n|\tf(x_(n-1))|\tf(x_n)|\tx_(n+1)|\n");
    do{
        fx1n = f(x1n);
        fxn = f(xn);
        // Check for division by zero
        if(fabs(fxn - fx1n) < 1e-10){
            printf("Division by zero error! Function values are too close.\n");
            return 1;
        }
        xn1 = xn - ((fxn*(xn-x1n))/(fxn-fx1n));
        printf("\t%d|\t%.4lf|\t%.4lf|\t%.4lf|\t%.4lf|\t%.4lf|\n", step, x1n, xn, fx1n, fxn, xn1);
        if(fabs(xn1 - xn) < tolerance){
            break;
        }
        x1n = xn;
        xn = xn1;
        step++;

    }while (1);
    printf("\n The root of the following eqn is : %.3lf", xn1);
    
}