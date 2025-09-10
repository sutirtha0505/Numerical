#include <stdio.h>
#include <math.h>

void main(){
	int n, i, j, fact;
	float u, u1, x, y;
	printf("Enter the number of entries: ");
	scanf("%d", &n);
	float a[n][n];
	printf("Enter the value of x to calculate y: ");
	scanf("%f", &x);
	printf("Enter the values for x : \n");
	for (i = 0; i < n; i++) scanf("%f", &a[i][0]);
	printf("Enter the values of y: \n");
	for(i = 0; i < n ; i++) scanf("%f", &a[i][1]);
	//performing delta operation loop
	for(j = 2 ; j < n; j++){
		for(i = 0; i < n-(j-1); i++){
			a[i][j] = a[i+1][j-1] - a[i][j-1];
		}
	}
	//Printing the difference table
	printf("The difference table is: \n");
	for(i = 0; i < n; i++){
		for (j = 0; j < n-i; j++){
			printf("%f\t", a[i][j]);
		}
		printf("\n");
	}
	//newton forward interpolation
	u = (x - a[0][0])/(a[1][0] - a[0][0]);
	y = a[0][1];
	u1 = u;
	fact = 1;
	for(i = 2; i < n; i++){
		fact = fact * (i -1);
		y = y + (u1* a[0][i]/fact);
		u1 = u1 * (u - (i - 1));
		
	}
	printf("The value of y is %f for the value of x = %f", y, x);
}
