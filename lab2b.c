#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int *A,int s,int e)
{
    int pivot=A[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(A[i]<=pivot)
        count++;
    }
    int pivotId=count+s;
    int temp=A[pivotId];
    A[pivotId]=A[s];
    A[s]=temp;
    int i=s,j=e;
    while(i<pivotId && j>pivotId)
    {
        while(A[i]<=pivot)
        {
            i++;
        }
        while(A[j]>=pivot)
        {
            j--;
        }
        if(i<pivotId && j>pivotId)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;
            j--;
        }
    }
    return pivotId;
}
void quicksort(int *A,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int pi=partition(A,s,e);
    quicksort(A,s,pi-1);
    quicksort(A,pi+1,e);
}
void generateRandomArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%n;
    }
}
int main() {
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
    quicksort(arr,0,n-1);
    clock_t end= clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC/1000.0;
    printf("Time taken to sort %d element : %f seconds\n",n,time_taken);
    free(arr);
    return 0;
}