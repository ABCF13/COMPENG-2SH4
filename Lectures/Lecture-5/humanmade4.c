#include <stdio.h>


int main(void)
{
    int num, sum, i;
    
    do {

        printf("Enter an integer (0 to quit): ");
        if(scanf("%d", num)==1){
            break;
        }

    } while(num!=0);

    
    return 0;

}