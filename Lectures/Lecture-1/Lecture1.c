#include <stdio.h>

int main(void)
{
    char firstName[50];
    int birthYear;
    int age;
    const int currentYear = 2026;

    printf("Enter your first name: ");
    scanf("%49s",firstName);

    printf("Enter you birth year: ");
    scanf("id", &birthYear);


    age=currentYear-birthYear;

    printf("%s! You  are %d years old young buck.\n",firstName, age);
    return 0;
};