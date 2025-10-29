#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int *A,int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=A[i];
        int min_index=i;
        for(int j=i;j<n;j++)
        {
            if(min>A[j])
            min_index=j;
        }
        int temp=A[i];
        A[i]=A[min_index];
        A[min_index]=temp;
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
        selectionsort(arr,n);
    }
    clock_t end= clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC/1000.0;
    printf("Time taken to sort %d element : %f seconds\n",n,time_taken);
    free(arr);
}