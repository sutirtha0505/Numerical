#include <stdio.h>
#include <math.h>

double f(double x){
    return x*x*x - 8*x -4;  //This is the eqn. f(x) = x^3 - 8x - 4
}
double df(double x){
    return 3*x*x - 8;   //This is the derivative of f(x)
}

int main(){
    double x, fx, dfx, hn, xnext;
    int step = 1;
    double tolerance = 0.00005; //For correcting upto 4 decimal places

    printf("Enter the initial guess between 3 and 4: ");
    scanf("%lf", &x);

    printf("\tStep|\tx_n|\tf(x_n)|\tf'(x_n)|\th_n|\tx_n+1|\n");
    do{
        fx=f(x);
        dfx = df(x);
        //Edge case for checking if the deviative is too close to zero
        if (fabs(dfx) < 1e-10){
            printf("The value of derivative is too close to zero");
            break;
        }

        hn = -fx/dfx;
        xnext = x + hn;
        printf("\t%4d|\t%.5lf|\t%.5lf|\t%.5lf|\t%.5lf|\t%.5lf|\n", step, x, fx, dfx, hn, xnext);
        if (fabs(hn)<tolerance)
        {
            break;
        }
        x = xnext;
        step++;
        
    } while (1);
    printf("\n The root is approximately %.4lf\n: ", xnext);
    return 0;
}