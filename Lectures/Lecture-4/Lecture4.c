#include <stdio.h>


int main(void) //c89 standard. Requires main to have void in parameter list if empty
{

    int grade;
    printf("Provide me you numerical grade: ");
    scanf("%d", &grade);


    if(grade>=90)
        printf("12!");
    else if (grade>=80)
        printf("10 or 11");
    else    
        printf("not trim");

    return 0;
    
    
};