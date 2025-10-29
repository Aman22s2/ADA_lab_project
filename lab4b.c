#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** alloc_matrix(int n) {
    int **mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        mat[i] = (int*)malloc(n * sizeof(int));
    return mat;
}
void fill_matrix(int **A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = rand() % 10;
}

void iterative_mult(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
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

void divide_conquer(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n/2;
    int **A11 = alloc_matrix(k), **A12 = alloc_matrix(k);
    int **A21 = alloc_matrix(k), **A22 = alloc_matrix(k);
    int **B11 = alloc_matrix(k), **B12 = alloc_matrix(k);
    int **B21 = alloc_matrix(k), **B22 = alloc_matrix(k);
    int **C11 = alloc_matrix(k), **C12 = alloc_matrix(k);
    int **C21 = alloc_matrix(k), **C22 = alloc_matrix(k);
    int **M1 = alloc_matrix(k), **M2 = alloc_matrix(k);


    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }

    divide_conquer(A11, B11, C11, k);
    divide_conquer(A12, B21, M1, k);
    add_matrix(C11, M1, C11, k);

    divide_conquer(A11, B12, C12, k);
    divide_conquer(A12, B22, M1, k);
    add_matrix(C12, M1, C12, k);

    divide_conquer(A21, B11, C21, k);
    divide_conquer(A22, B21, M1, k);
    add_matrix(C21, M1, C21, k);

    divide_conquer(A21, B12, C22, k);
    divide_conquer(A22, B22, M1, k);
    add_matrix(C22, M1, C22, k);

    
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j]       = C11[i][j];
            C[i][j+k]     = C12[i][j];
            C[i+k][j]     = C21[i][j];
            C[i+k][j+k]   = C22[i][j];
        }
}

// Strassen’s Method
void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n/2;
    int **A11 = alloc_matrix(k);
    int  **A12 = alloc_matrix(k);
    int **A21 = alloc_matrix(k);
    int **A22 = alloc_matrix(k);
    int **B11 = alloc_matrix(k);
    int **B12 = alloc_matrix(k);
    int **B21 = alloc_matrix(k);
    int **B22 = alloc_matrix(k);
    int **M1 = alloc_matrix(k);
    int **M2 = alloc_matrix(k);
    int **M3 = alloc_matrix(k);
    int **M4 = alloc_matrix(k);
    int **M5 = alloc_matrix(k);
    int **M6 = alloc_matrix(k);
    int **M7 = alloc_matrix(k);
    int **T1 = alloc_matrix(k);
    int  **T2 = alloc_matrix(k);
    int **C11 = alloc_matrix(k);
    int **C12 = alloc_matrix(k);
    int **C21 = alloc_matrix(k);
    int **C22 = alloc_matrix(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }

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
    sub_matrix(A12, A22, T1, k);
    add_matrix(B21, B22, T2, k); 
    strassen(T1, T2, M7, k);
    add_matrix(M1, M4, T1, k); 
    sub_matrix(T1, M5, T2, k); 
    add_matrix(T2, M7, C11, k);
    add_matrix(M3, M5, C12, k);
    add_matrix(M2, M4, C21, k);
    add_matrix(M1, M3, T1, k); 
    sub_matrix(T1, M2, T2, k); 
    add_matrix(T2, M6, C22, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j]       = C11[i][j];
            C[i][j+k]     = C12[i][j];
            C[i+k][j]     = C21[i][j];
            C[i+k][j+k]   = C22[i][j];
        }
}

int main() {
    srand(time(NULL));

    int sizes[] = {2, 4, 8, 16, 32, 64, 128, 256};
    int ns = sizeof(sizes)/sizeof(sizes[0]);

    printf("Matrix Size | Iterative(s) | Divide&Conquer(s) | Strassen(s)\n");
    printf("-------------------------------------------------------------\n");

    for (int t = 0; t < ns; t++) {
        int n = sizes[t];
        int **A = alloc_matrix(n), **B = alloc_matrix(n);
        int **C = alloc_matrix(n);

        fill_matrix(A, n); fill_matrix(B, n);

        clock_t start, end;
        double t_iter, t_dc, t_strassen;

        start = clock(); iterative_mult(A, B, C, n); end = clock();
        t_iter = (double)(end - start)/CLOCKS_PER_SEC;

        start = clock(); divide_conquer(A, B, C, n); end = clock();
        t_dc = (double)(end - start)/CLOCKS_PER_SEC;

        start = clock(); strassen(A, B, C, n); end = clock();
        t_strassen = (double)(end - start)/CLOCKS_PER_SEC;

        printf("%10d | %11.6f | %18.6f | %10.6f\n", n, t_iter, t_dc, t_strassen);
    }

    return 0;
}