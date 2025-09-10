#include <stdio.h>
void main(){
    float a, b, x[100], y[100];
    float sum_xy = 0, sum_x = 0, sum_y = 0, sum_x2 = 0;
    int i, n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the values of x:\n");
    for(i = 0; i < n; i++){
        printf("x[%d] : ", i+1);
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y:\n");
    for(i = 0; i < n; i++){
        printf("y[%d] : ", i+1);
        scanf("%f", &y[i]);
    }
    for(i = 0; i < n; i++){
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_xy = sum_xy + (x[i] * y[i]);
        sum_x2 = sum_x2 + (x[i] * x[i]);
    }
    b = ((n * sum_xy - sum_x*sum_y)/ (n*sum_x2 - sum_x*sum_x));
    a = (sum_y - b * sum_x)/n;
    printf("The required equation is y = %f + %fx\n", a, b);
}