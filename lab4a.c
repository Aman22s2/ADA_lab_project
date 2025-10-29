#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int **allocate_matrix(int n)
 {
    int **mat=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        mat[i]=(int*)malloc(n*sizeof(int));
    }
    return mat;
 }
 void initialize_matrix(int **A,int n)
 {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=rand()%10;
        }
    }
 }
 void display_matrix(int **A,int n)
 {
    printf("Matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
 }
int**mutlipyiterative(int **A, int **B,int n)
{
    int **result=allocate_matrix(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][j]=0;
            for(int k=0;k<n;k++)
            {
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return result;
}
int main()
{
    int n;
    printf("Enter size of matrix");
    scanf("%d",&n);
    int **A=allocate_matrix(n);
    int **B=allocate_matrix(n);
    initialize_matrix(A,n);
    initialize_matrix(B,n);
    int **C=mutlipyiterative(A,B,n);
    display_matrix(A,n);
    display_matrix(B,n);
    display_matrix(C,n);
}