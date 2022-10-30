#include <stdio.h>
#include <stdlib.h>

int n = 10;
void nhapMang(int **ptr){
    *ptr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        // (*ptr)[i] = i;
        *(*ptr+i) = i;
    }
    printf("Dia chi ptr: %p\n", &*ptr);
}

void hienThiMang(int *ptr){
    for (int i = 0; i < n; i++){
        printf("a[%d] = %d\n", i, ptr[i]);
    }
}

int main(int argc, char const *argv[])
{
    //Khoi tao mang
    int *arr;
    //In ra mang ban dau
    nhapMang(&arr);
    printf("Dia chi arr: %p\n", &arr);
    hienThiMang(arr);
    return 0;
}