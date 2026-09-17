#include <stdio.h>
#include <stdlib.h>


long unsigned int f(long unsigned int);

long unsigned int main(void)
{
    long unsigned int value;
    printf("How big will your thing be?: ");
    scanf("%lu", &value);

    printf("Your value is %lu: ", f(value));
    return 0;
};



long unsigned int f(long unsigned int size)
{
    if (size>1)
    {
    long unsigned int* arr = (long unsigned int*)malloc(size*sizeof(long unsigned int));
    arr[0]=1;
    arr[1]=1;
    
    for(long unsigned int i=2LU;i<size;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    };

    long unsigned int final= arr[size-1];
    free(arr);

    return final;
    }
    else 
    {
       return 1;
    }
};