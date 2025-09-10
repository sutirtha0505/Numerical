#include <stdio.h>
#include <math.h>

#define MAX 20
#define TOL 0.001

// Function for checking if strictly diagonally dominant
int isDiagonallyDominant(int n, float a[MAX][MAX+1]) {
    int i, j;
	for (i = 0; i < n; i++) {
        float sum = 0;
        for (j = 0; j < n; j++) {
            if (i != j) sum += fabs(a[i][j]);
        }
        if (fabs(a[i][i]) <= sum) {
            printf("Not Strictly Diagonally Dominant. Exiting...\n");
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i, j, iter = 0;
    float a[MAX][MAX+1], sol[MAX], sol_new[MAX];

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix row by row:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    if (!isDiagonallyDominant(n, a)) return 0;

    // Initial guess = 0
    for (i = 0; i < n; i++) sol[i] = 0;

    while (1) {
        float maxDiff = 0;

        printf("\nIteration %d: ", iter + 1);

        for (i = 0; i < n; i++) {
            float sum = a[i][n]; // RHS
            for (j = 0; j < n; j++) {
                if (i != j) sum -= a[i][j] * sol[j];
            }
            sol_new[i] = sum / a[i][i];

            if (fabs(sol_new[i] - sol[i]) > maxDiff)
                maxDiff = fabs(sol_new[i] - sol[i]);
        }

        // Print current iteration values
        for (i = 0; i < n; i++) {
            printf(" x[%d] = %.4f", i+1, sol_new[i]);
        }

        // Update
        for (i = 0; i < n; i++) sol[i] = sol_new[i];

        iter++;
        if (maxDiff < TOL) break;
    }

    printf("\n\nFinal Solution after %d iterations:\n", iter);
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i+1, sol[i]);
    }

    return 0;
}

