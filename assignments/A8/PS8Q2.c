#include <stdio.h>

int main(void)
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int *ptr1 = &data[1];
    int *ptr2 = &data[6];
    int *ptr3 = &data[13];

    printf("data[4] by ptr1: AI)%d PO)%d\n", ptr1[3], *(ptr1 + 3));
    printf("data[0] by ptr2: AI)%d PO)%d\n", ptr2[-6], *(ptr2 -6));
    printf("data[12] by ptr3: AI)%d PO)%d\n", ptr3[-1], *(ptr3 - 1));
    printf("data[10] by ptr1: AI)%d PO)%d\n", ptr1[9], *(ptr1 + 9));
    printf("data[7] by ptr3: AI)%d PO)%d\n", ptr3[-6], *(ptr3 - 6));
    printf("data[9] by ptr2: AI)%d PO)%d\n", ptr2[3], *(ptr2 + 3));

    return 0;
}



/*
Access data[4] using ptr1:
*(ptr+3), ptr1[3];

Access data[0] using ptr2
*(ptr2-6), ptr2[-6];

Access data[12] using ptr3
*(ptr3-1), ptr3[-1];

Access data[10] using ptr1
*(ptr1+9), ptr1[9];

Access data[7] using ptr3
*(ptr3-5), ptr3[-5];

Access data[9] using ptr2
*(ptr2+3), ptr2[3];



*/