#include <stdio.h>

#define swimbim 9 


int ** arr;

int main(int* arr){
    
    int** scan = arr;
   //arbitrary

    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
       *(scan+i);
        
    };



    return 1;


}