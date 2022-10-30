#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *ptr;
    int size;
}Array;


void CreateArray(Array *value){

    srand(time(NULL));
    value->size = 10 + rand() % (30 +1 - 10);
    int temp;
    printf("Kich thuoc cua array: %d\n", value->size);

    value->ptr = (int *)malloc(value->size * sizeof(int));

    for(int i = 0; i < value->size; i++){
        temp = rand() % 4;
        value->ptr[i] = temp;
    }
}

void CountArray(Array value){
    int cnt0 = 0;
    for (int i = 0; i < value.size; i++)
    {
        if (value.ptr[i] == 0)
        {
            cnt0++;
        }
    }
    printf("%d", cnt0);
}

int main(int argc, char const *argv[])
{
    /* code */

    Array value;

    CreateArray(&value);

    for (int i = 0; i < value.size; i++)
    {
        printf("arr[%d] = %d\n",i, value.ptr[i]);
    }
    
    CountArray(value);
    return 0;
}
