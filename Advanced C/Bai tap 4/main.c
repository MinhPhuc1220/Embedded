#include <stdio.h>
#include <stdlib.h>

/*
Chia một mảng các số từ 0 tới 9 thành hai mảng chẵn và mảng lẻ
*/

int n = 10;
void nhapMang(int *ptr){
    for (int i = 0; i < n; i++){
        *(ptr+i) = i;
    }
}

void hienThiMang(int *ptr){
    printf("arr = ");
    for (int i = 0; i < n; i++){
        printf("%d  ",ptr[i]);
    }
}

void mangEven(int *ptr){
    int *even = (int*)malloc(n/2*sizeof(int));
    printf("\neven = ");
    for (int i = 0; i < 10; i++){
        if (ptr[i] % 2 == 0){
            even[i/2] = ptr[i];
            printf("%d  ",even[i/2]);
        }
    } 
}

void mangOdd(int *ptr){
    int *odd = (int*)malloc(n/2*sizeof(int));
    printf("\nodd = ");
    for (int i = 0; i < 10; i++){
        if (ptr[i] % 2 == 1){
            odd[i/2] = ptr[i];
            printf("%d  ",odd[i/2]);
        }
    } 
}

int main(int argc, char const *argv[])
{
    
    //Khoi tao mang
    int *arr;
    arr = (int*)malloc(n*sizeof(int));
    //In ra mang ban dau
    nhapMang(arr);
    hienThiMang(arr);
    //In ra mang chan
    mangEven(arr);
    //In ra mang le
    mangOdd(arr);
    free(arr);
    return 0;
}
