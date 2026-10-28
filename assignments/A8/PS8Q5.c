#include <stdio.h>
#include <stdlib.h>  // required for DMA

int* merge(int v1[], int sz1, int v2[], int sz2)
{
    int* vmerged = (int*)malloc((sz1 + sz2) * sizeof(int));
    int i, i1 = 0, i2 = 0;

    for(i = 0; i < (sz1 + sz2) || i1 != sz1 || i2 != sz2; i++) {
        vmerged[i] = v1[i1] < v2[i2]? v1[i1++] : v2[i2++];                            
    }

    if(i1 < sz1) {
        for( ; i1 < sz1 ; i++, i1++) {
            vmerged[i] = v1[i1];
        }
    }
    else if(i2 < sz2) {
        for( ; i2 < sz2 ; i++, i2++) {
            vmerged[i] = v2[i2];
        }
    }    

    return vmerged;
}

int printArray(int v1[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", v1[i]);
    }
    printf("\n");
}

int main(void)
{
    int v1[5] = {3, 6, 11, 18, 25};
    int v2[4] = {4, 15, 27, 30};
    int* result;

    printArray(v1, 5);
    printArray(v2, 4);
    result = merge(v1, 5, v2, 4);
    printArray(result, 9);
    
    free(result);  // Dr Memory reported 0 leak

    return 0;
}