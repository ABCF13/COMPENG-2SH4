#include <stdio.h>
#include <stdlib.h>  // required for DMA

char* my_strcat(char s1[], char s2[])
{
    char* ss;
    int size1, size2, i;
    for(size1 = 0; s1[size1] != '\0'; size1++);
    for(size2 = 0; s2[size2] != '\0'; size2++);

    ss = (char*)malloc((size1 + size2 + 1) * sizeof(char));

    for(i = 0; i < size1; i++) {
        ss[i] = s1[i];
    }

    for(i = 0; i < size2; i++) { 
        ss[size1 + i] = s2[i];
    }

    ss[size1 + size2] = '\0';  // insert the period to the last element

    return ss;
}

int main(void)
{
    char str1[] = "McMaster ";
    char str2[] = "COE2SH4";
    char* str;

    str = my_strcat(str1, str2);
    printf("%s\n", str);

    free(str);  // Dr Memory reported 0 leak

    return 0;
}