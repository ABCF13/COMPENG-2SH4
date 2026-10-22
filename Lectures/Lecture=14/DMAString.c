#include <stdio.h>
#include <stdlib.h>

/* Custom string length function */
size_t my_strlen(const char *str) {
    const char *s;
    
    if (str == NULL) {
        return 0;
    }
    
    s = str;
    while (*s != '\0') {
        s++;
    }
    return (size_t)(s - str);
}

/* Custom string concatenation function using DMA */
char *my_strcat_alloc(const char *s1, const char *s2) {
    size_t len1;
    size_t len2;
    char *result;
    char *p;
    
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }
    
    len1 = my_strlen(s1);
    len2 = my_strlen(s2);
    
    /* Allocate memory for both strings plus the null terminator */
    result = (char *)malloc(len1 + len2 + 1);
    if (result == NULL) {
        return NULL; 
    }
    
    p = result;
    while (*s1 != '\0') {
        *p = *s1;
        p++;
        s1++;
    }
    while (*s2 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    
    return result;
}

int main(void) {
    const char *str1;
    const char *str2;
    char *concatenated;
    size_t len1;
    size_t len2;
    
    str1 = "Hello, ";
    str2 = "C89 World!";
    
    /* Test string length calculation */
    len1 = my_strlen(str1);
    len2 = my_strlen(str2);
    
    printf("String 1: \"%s\" (Length: %u)\n", str1, (unsigned int)len1);
    printf("String 2: \"%s\" (Length: %u)\n", str2, (unsigned int)len2);
    
    /* Test string concatenation using DMA */
    concatenated = my_strcat_alloc(str1, str2);
    if (concatenated != NULL) {
        printf("Concatenated: \"%s\" (Length: %u)\n", 
               concatenated, (unsigned int)my_strlen(concatenated));
        
        /* Free dynamically allocated memory */
        free(concatenated);
    } else {
        printf("Memory allocation failed during concatenation.\n");
        return 1;
    }
    
    return 0;
}