#include <stdio.h>

// Fibonacci Sequence
// Term #   1  2  3  4  5  6  7  8  9 10
// Value    1  1  2  3  5  8 13 21 34 55

int findFibo(int N)
{
    int prevTerm = 1;
    int currTerm = 1;
    int temp = 0, i;

    for(i = 0; i <= N; i++)
    {
        temp = currTerm;
        currTerm += prevTerm;
        prevTerm = temp;
    }

    return currTerm;
}

int main(void)
{
    int input;
    printf("Which Fibo term? >> ");
    scanf("%d", &input);
    printf("Fibo Term %d = %d\n", input, findFibo(input));
    return 0;
}
