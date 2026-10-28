#include <stdlib.h>
#include "objPos.h"[cite: 1]

/* Function 1: Safely allocate an m by n array using distributed per-row malloc */
objPos** allocateObjPosArray(int m, int n)
{
    objPos** arr = NULL;
    int i;
    int j;

    if (m <= 0 || n <= 0)
    {
        return NULL;
    }

    /* Allocate the master array of row pointers */
    arr = (objPos**)malloc(m * sizeof(objPos*));
    if (arr == NULL)
    {
        return NULL;
    }

    /* Allocate each row independently */
    for (i = 0; i < m; i++)
    {
        arr[i] = (objPos*)malloc(n * sizeof(objPos));
        if (arr[i] == NULL)
        {
            /* Rollback: free all previously allocated rows */
            for (j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            /* Free the row pointer array itself */
            free(arr);
            return NULL;
        }
    }

    return arr;
}

/* 
 * Function 2: Safely deallocate the m by n objPos array.
 * Note: With distributed allocation, the number of rows (m) must be provided 
 * to iterate and release each row independently.
 */
void freeObjPosArray(objPos** arr, int m)
{
    int i;

    if (arr == NULL)
    {
        return;
    }

    for (i = 0; i < m; i++)
    {
        if (arr[i] != NULL)
        {
            free(arr[i]);
        }
    }

    free(arr);
}