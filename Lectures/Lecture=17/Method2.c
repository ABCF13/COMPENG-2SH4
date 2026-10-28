#include <stdlib.h>
#include "objPos.h"

/* Function 1: Safely allocate an m by n rectangular array of objPos instances */
objPos** allocateObjPosArray(int m, int n)
{
    objPos** arr = NULL;
    int i;

    if (m <= 0 || n <= 0)
    {
        return NULL;
    }

    /* 
     * Allocate space for m row pointers plus the m * n objPos structs 
     * in a single contiguous block of memory.
     */
    arr = (objPos**)malloc((m * sizeof(objPos*)) + (m * n * sizeof(objPos)));
    if (arr == NULL)
    {
        return NULL; /* Allocation failed; nothing to release */
    }

    /* Point the first row pointer to the beginning of the data block */
    arr[0] = (objPos*)((char*)arr + (m * sizeof(objPos*)));

    /* Set up the remaining row pointers */
    for (i = 1; i < m; i++)
    {
        arr[i] = arr[i - 1] + n;
    }

    return arr;
}

/* Function 2: Safely deallocate the m by n objPos array */
void freeObjPosArray(objPos** arr)
{
    if (arr != NULL)
    {
        /* Since it was allocated as a single block, a single free() releases everything */
        free(arr);
    }
}