#include <stdio.h>
#include <math.h>
double f(double x){
    return x*x*x + 2*x - 2;
}

int main(){
    double a, b, hn, fa, fb, xn1, fxn1, tolerance = 0.0005;
    printf("Enter the lower limit: ");
    scanf("%lf", &a);
    printf("Enter the Higher limit: ");
    scanf("%lf", &b);    
    int step = 1;
    printf("|\tStep|\ta|\tb|\tf(a)|\tf(b)|\th_n|\tx_n+1|\tf(x_n+1)|\n");
    do{
        fa = f(a);
        fb = f(b);
        hn = (fabs(fa)*(b-a))/(fabs(fa) + fabs(fb));
        xn1 = a + hn;
        fxn1 = f(xn1);
        printf("|\t%d|\t%.4f|\t%.4f|\t%.4f|\t%.4f|\t%.4f|\t%.4f|\t%.4f|\n",step, a, b, fa, fb, hn, xn1, fxn1);
        
        if(fabs(hn) < tolerance || fabs(fxn1) < tolerance){
            break;
        }
        
        step++;
        if(fxn1 * fa > 0){
            a = xn1;
        } else{
            b = xn1;
        }
    } while (1);
    printf("\n The Root of the following eqn is : %.3lf", xn1);
    
}