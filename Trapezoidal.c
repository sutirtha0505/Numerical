#include <stdio.h>
#include <math.h>
double f(double x){
    return 4*x - 3*x*x;
}
int main(){
    double a, b, h, xi, yi, y0 = 0, y1 = 0, y2 = 0;
    int  n, step = 0;
    printf("Enter the lower limit of the integration: ");
    scanf("%lf", &a);
    printf("Enter the Upper limit of the integration: ");
    scanf("%lf", &b);
    printf("Enter the number of iteration: ");
    scanf("%d", &n);
    h = (b-a)/n;
    y0 = f(a)+f(b);
    for (int i = 1; i < n; i++)
    {
        xi = xi + h;
        yi = f(xi);
        if (i%2 == 0)
        {
            y2 = y2 + yi;
        } else {
            y1 = y1 + yi;
        }
        
    }
    
    double trapezoidal = (h/2)*(y0 + 2*(y1+y2));
    double simpson = (h/3)*(y0+4*y1+2*y2);
    printf("Trapizoidal: %lf\n", trapezoidal);
    printf("Simpson 1/3: %lf", simpson);
}