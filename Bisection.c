#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - 9 * x + 1; // Example function: f(x) = x^3 - 9x + 1
}

int main()
{
    // Tolerance is 0.0005 for three significant figure
    //Tolerance for two significant figure is 0.005
    double a, b, c, c_old, tolerance = 0.0005;
    int step = 1;
    printf("Enter the value of lower bound: ");
    scanf("%lf", &a);
    printf("Enter the value of upper bound: ");
    scanf("%lf", &b);
    printf("| Step |    a    |    b    |   (a+b)/2  |    f(c)    |\n");
    printf("|------|---------|---------|------------|------------|\n");

    c_old = a;
    do
    {
        c = (a + b) / 2.0;
        printf("|  %2d  | %7.4lf | %7.4lf | %10.4lf | %10.4lf |\n", step, a, b, c, f(c));
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        step++;
        if (fabs(c - c_old) < tolerance)
            break;
        c_old = c;
    } while (1);
    printf("\nRoot is approximately %.3lf\n", c);
    return 0;
}