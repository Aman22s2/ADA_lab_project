// iterative method of matrix multiplication#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[4][4];
    int B[4][4];
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void multiplyIterative(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}
int main() {
    int sizes[] = {100, 200, 300, 400, 500}; // sizes to test
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    srand(time(NULL));
    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        int (*A)[n] = malloc(sizeof(int[n][n]));
        int (*B)[n] = malloc(sizeof(int[n][n]));
        int (*C)[n] = malloc(sizeof(int[n][n]));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }
        }
        clock_t start = clock();
        multiplyIterative(n, A, B, C);
        clock_t end = clock();
        printf("Iterative %d x %d: %.6f seconds\n", n, n, ((double)(end - start)) / CLOCKS_PER_SEC);
        free(A); 
        free(B); 
        free(C);
    }
    return 0;
}
