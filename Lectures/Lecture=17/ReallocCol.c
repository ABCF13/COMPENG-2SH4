#include <stdlib.h>
#include "objPos.h"

/* 
 * Function 4: Safely resize the column dimension for all rows in the distributed objPos array.
 * Iterates through each row and uses realloc() to adjust its column capacity.
 */
objPos** resizeObjPosColumns(objPos** arr, int m, int n, int new_n)
{
    int i;
    int j;
    objPos* temp_row = NULL;

    if (arr == NULL || m <= 0 || n <= 0 || new_n <= 0)
    {
        return arr; /* Invalid parameters; return array unmodified */
    }

    if (new_n == n)
    {
        return arr; /* No change needed */
    }

    for (i = 0; i < m; i++)
    {
        temp_row = (objPos*)realloc(arr[i], new_n * sizeof(objPos));
        if (temp_row == NULL)
        {
            /* Rollback: restore previously resized rows back to the original size n */
            for (j = 0; j < i; j++)
            {
                (void)realloc(arr[j], n * sizeof(objPos));
            }
            
            return arr; /* Realloc failed; return original array configuration */
        }
        arr[i] = temp_row;
    }

    return arr;
}