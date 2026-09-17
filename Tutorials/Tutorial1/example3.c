#include <stdio.h>

int main(void)
    {
        int arr[20];

        for (int i=0; i<20;i++)
            {
                printf("Enter number %d: ", (i+1));
                scanf("%d", &arr[i]);

                if (i>0 && arr[i]>arr[i-1]) 
                    {
                        printf("Not Sorted Decreasing");
                        return 0;
                    }
            }
        printf("This is sorted");
        return 0;

    }