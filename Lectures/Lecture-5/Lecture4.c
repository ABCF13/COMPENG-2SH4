#include <stdio.h>

int main(void)
{
    int num, sum, i;
  
    while(1){


        printf("Enter an integer (0 to quit)");

        if (scanf("%d", &num) !=1){
            break;
        }

        if (num==0){
            break;
        }


        sum=0;
        if (num>0)
        {
            for (i=1; i<= num; i++)
            {
                sum+=i;
        
            }
            printf("Sum from 1 to %d: %d\n\n", num, sum);

        } else 
        {
            printf("Please provide a positive integer input");
        }


    }


}