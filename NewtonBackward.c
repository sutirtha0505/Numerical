#include <stdio.h>
#include <math.h>

void main(){
    float x, y, u, u1;
    int n, i, j, factorial = 1;
    printf("Enter the number of entries: ");
    scanf("%d", &n);
    printf("Enter the desired value for x : ");
    scanf("%f", &x);
    float a[n][n];
    printf("Enter the values of x: \n");
    for(i = 0; i < n; i++) scanf("%f", &a[i][0]);
    printf("Enter the values of y: \n");
    for(i = 0; i < n; i++) scanf("%f",&a[i][1]);
    //Calculating the values for delta operators
    for(j = 2; j < n; j++){
        for(i = n-1; i > (j - 1); i--){
            a[i][j] = a[i][j-1] - a[i-1][j-1];
        }
    }
    //Printing the table
    printf("The difference table:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }
    u = (x - a[n-1][0])/(a[1][0] - a[0][0]);
    y = a[n-1][1];
    u1 = u;
    for(j = 2; j < n; j++){
        factorial = factorial * (j-1);
        y = y + (u1 * a[n-1][j]/factorial);
        u1 = u1 * (u1 + (j-1));
    }
    printf("The value of y is %f for val of x = %f", y, x);

}