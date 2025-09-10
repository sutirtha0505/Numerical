#include <stdio.h>
#include <math.h>

void main(){
    int n;
    printf("Enter the number of equations : ");
    scanf("%d", &n);
    float a[n][n+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            printf("a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    //Upper triangular matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j){
                float ratio = a[j][i]/a[i][i];
                for (int k = 0; k < n + 1; k++){
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
                printf("The matrix after row operation will be : \n");
                for(int x = 0; x < n; x++){
                    for(int y = 0; y < n + 1; y++){
                        printf("%f\t", a[x][y]);
                    }
                    printf("\n");
                }
            }
        }
    }
    //Back substitution
    float value[n];
    value[n-1] = a[n-1][n] / a[n-1][n-1];
    for(int i = n-2; i >= 0; i--){
        float sum = 0;
        for(int j = i+1; j < n; j++){
            sum = sum + a[i][j] * value[j];
        }
        value[i] = (a[i][n]-sum)/a[i][i];
    }
    for(int i = 0 ; i < n; i++){
        printf("value[%d] = %f\n", i, value[i]);
    }
}