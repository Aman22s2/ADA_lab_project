#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** alloc_matrix(int n) {
    int **mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        mat[i] = (int*)malloc(n * sizeof(int));
    return mat;
}
void add_matrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}
void sub_matrix(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}
void normal_mult(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}
void strassen(int **A, int **B, int **C, int n) 
{
    if (n <= 2) 
    {
        normal_mult(A, B, C, n);
        return;
    }
    int k = n / 2;
    int **A11 = alloc_matrix(k), **A12 = alloc_matrix(k);
    int **A21 = alloc_matrix(k), **A22 = alloc_matrix(k);
    int **B11 = alloc_matrix(k), **B12 = alloc_matrix(k);
    int **B21 = alloc_matrix(k), **B22 = alloc_matrix(k);
    int **C11 = alloc_matrix(k), **C12 = alloc_matrix(k);
    int **C21 = alloc_matrix(k), **C22 = alloc_matrix(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }
    int **M1 = alloc_matrix(k), **M2 = alloc_matrix(k), **M3 = alloc_matrix(k);
    int **M4 = alloc_matrix(k), **M5 = alloc_matrix(k), **M6 = alloc_matrix(k);
    int **M7 = alloc_matrix(k);
    int **T1 = alloc_matrix(k), **T2 = alloc_matrix(k);
    add_matrix(A11, A22, T1, k);
    add_matrix(B11, B22, T2, k);
    strassen(T1, T2, M1, k);
    add_matrix(A21, A22, T1, k);
    strassen(T1, B11, M2, k);
    sub_matrix(B12, B22, T2, k);
    strassen(A11, T2, M3, k);
    sub_matrix(B21, B11, T2, k);
    strassen(A22, T2, M4, k);
    add_matrix(A11, A12, T1, k);
    strassen(T1, B22, M5, k);
    sub_matrix(A21, A11, T1, k);
    add_matrix(B11, B12, T2, k);
    strassen(T1, T2, M6, k);
    sub_matrix(A12, A22, T1, k);
    add_matrix(B21, B22, T2, k);
    strassen(T1, T2, M7, k);
    add_matrix(M1, M4, T1, k);
    sub_matrix(T1, M5, T2, k);
    add_matrix(T2, M7, C11, k);
    add_matrix(M3, M5, C12, k);
    add_matrix(M2, M4, C21, k);
    sub_matrix(M1, M2, T1, k);
    add_matrix(T1, M3, T2, k);
    add_matrix(T2, M6, C22, k);
    for (int i = 0; i < k; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            C[i][j]         = C11[i][j];
            C[i][j + k]     = C12[i][j];
            C[i + k][j]     = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}
int main() {
    int n;
    printf("Enter matrix size (power of 2): ");
    scanf("%d", &n);
    int **A = alloc_matrix(n);
    int **B = alloc_matrix(n);
    int **C = alloc_matrix(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
    clock_t start = clock();
    strassen(A, B, C, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time for %d x %d matrices: %f seconds\n", n, n, time_taken);
    return 0;
}