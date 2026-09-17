
int* f(void);

int main(void)
{
    int value;
    printf("How big will your thing be?: ");
    scanf("%d", &value);

    return f(value);
};



int* f(long unsigned int size)
{
    
    int* arr = (int*)malloc(size*sizeof(long int));
    arr[0]=1;
    arr[1]=1;
    
    for(int i=2LU;i<size;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    };
    return arr[size];

};