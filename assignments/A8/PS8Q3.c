#include <stdio.h>

void selectionSort(int* array, int size)
{
    int i, j, min, temp;
    for(i = 0; i < size - 1; i++) { 
        min = i;		
        for(j = i + 1; j < size; j++) {
            if(*(array + min) > *(array + j)) 
                min = j;
        }
        temp = *(array + min);
        *(array + min) = *(array + i);
        *(array + i) = temp;
    }
}

void printArray(int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

int main(void)
{
    int a[15] = {11, 5, 23, 1, 6, 15, 2, 7, 28, 3, 4, 15, 9, 8, 0};

    printArray(a, 15);
    selectionSort(a, 15);
    printArray(a, 15);

    return 0;
}