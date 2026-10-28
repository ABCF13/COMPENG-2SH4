#include <stdlib.h>
#include "objPos.h"

/* 
 * Function 3: Safely resize the row dimension of the distributed objPos array.
 * Returns the new pointer to the array (which may have changed location), 
 * or NULL/original array on failure depending on the resize direction.
 */
objPos** resizeObjPosArray(objPos** arr, int m, int n, int new_m)
{
    objPos** temp_arr = NULL;
    int i;
    int j;

    if (n <= 0 || new_m <= 0)
    {
        return arr; /* Invalid dimensions; return unmodified array */
    }

    if (new_m == m)
    {
        return arr; /* No change needed */
    }

    if (new_m > m)
    {
        /* Expanding the row dimension */
        temp_arr = (objPos**)realloc(arr, new_m * sizeof(objPos*));
        if (temp_arr == NULL)
        {
            return arr; /* Realloc failed; original array remains intact */
        }
        arr = temp_arr;

        /* Allocate the new rows */
        for (i = m; i < new_m; i++)
        {
            arr[i] = (objPos*)malloc(n * sizeof(objPos));
            if (arr[i] == NULL)
            {
                /* Rollback: free any newly allocated rows in this expansion batch */
                for (j = m; j < i; j++)
                {
                    free(arr[j]);
                }
                
                /* Attempt to shrink row pointers back to original size */
                temp_arr = (objPos**)realloc(arr, m * sizeof(objPos*));
                if (temp_arr != NULL)
                {
                    arr = temp_arr;
                }
                
                return arr; /* Return original successfully sized array reference */
            }
        }
    }
    else
    {
        /* Shrinking the row dimension */
        /* Free the excess rows first */
        for (i = new_m; i < m; i++)
        {
            if (arr[i] != NULL)
            {
                free(arr[i]);
            }
        }

        /* Shrink the master row pointer array */
        temp_arr = (objPos**)realloc(arr, new_m * sizeof(objPos*));
        if (temp_arr != NULL)
        {
            arr = temp_arr;
        }
    }

    return arr;
}