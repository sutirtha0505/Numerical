#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Doing lagrange interpolation for given data points
int main(){
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[10], y[10];
    //Input the values
    for(int i = 0; i < n ; i++ ){
        printf("Value for x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("Value for y[%d]: ", i);
        scanf("%f", &y[i]);
    }
    //Calculating using the formula
    float p, xp, yp;
    printf("Enter the value of desirable x : ");
    scanf("%f", &xp);
    yp = 0;
    //Summation outer loop
    for(int i = 0 ; i <= n-1 ; i++){
        p = 1;
        for(int j = 0; j <= n-1; j++){
            if(j != i){
                p = p * (xp - x[j])/(x[i] - x[j]);
            }
        }
        yp = yp + (p * y[i]); 
    }
    printf("The reuslt is : %f", yp);

}