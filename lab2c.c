#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionsort(int *A,int n)
{
    int temp,j;
    for(int i=1;i<n;i++)
    {
        temp=A[i];
        for(j=i-1;j>-1&&temp<A[j];j--)
        {
            A[j+1]=A[j];
        }
        A[j+1]=temp;
    }
}
void generateRandomArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%n;
    }
}
int main()
{
    int n;
    printf("Enter number of elements (n): ");
    scanf("%d", &n);
    int *arr=(int *)malloc(n*sizeof(int));;
    if(arr==NULL)
    {
        printf("Memory allocation fail");
    }
    generateRandomArray(arr,n);
    clock_t start=clock();
    for(int i=0;i<1000;i++)
    {
        insertionsort(arr,n);
    }
    clock_t end= clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC/1000.0;
    printf("Time taken to sort %d element : %f seconds\n",n,time_taken);
    free(arr);
    return 0;
}