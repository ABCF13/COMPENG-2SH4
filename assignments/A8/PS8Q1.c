#include <stdio.h>

int main(void)
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int *ptr1 = &data[1];
    int *ptr2 = &data[6];
    int *ptr3 = &data[13];

    printf("ptr1: %p\nptr2: %p\nptr3: %p\n", ptr1, ptr2, ptr3);

    printf("ptr2 - ptr1 = %p\n", ptr2-ptr1);
    printf("*ptr2 - *ptr1 = %d\n", *ptr2-*ptr1);
    printf("ptr3 - ptr1 = %p\n", ptr3-ptr1);
    printf("*ptr3 - *ptr1 = %d\n", *ptr3-*ptr1);

    printf("Bytes between ptr1 and ptr2: %d\n", (ptr2-ptr1) * sizeof(int));
    printf("Bytes between ptr2 and ptr3: %d\n", (ptr3-ptr2) * sizeof(int));

    return 0;
    
}

/*

7-2=5

each index is 4 bytes apart.

Each integr address references a 4byte allocation

indices (6-1)*4/4 is equal to 5 

14-2=12

(13-1)*4/4 is equal to 5




*/