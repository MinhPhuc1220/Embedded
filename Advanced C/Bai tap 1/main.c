#include <stdio.h>
#include <stdlib.h>

/*
Viet chuong trinh nhap cac so ngau nhien, roi luu vao mang arr[]
Nhan 1: Sap xep theo thu tu be den lon
Nhan 2: Sap xep theo thu tu lon den be
Nhan 3: Tim so lon nhat
*/ 

typedef struct typeArr
{
    int *arr;
    int size;
} tArr;

void beDenLon(tArr *value){
    int temp = 0;
    for (int i = 0; i < value->size; i++)
    {
        for (int j = i + 1; j < value->size; j++)
        {
            if (value->arr[i] > value->arr[j])
            {       
                temp = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = temp;
            }
        }
    }
}

void lonDenBe(tArr *value){
    int temp = 0;
    for (int i = 0; i < value->size; i++)
    {
        for (int j = i + 1; j < value->size; j++)
        {
            if (value->arr[i] < value->arr[j])
            {       
                temp = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = temp;
            }
        }
    }
}

int timSoLonNhat(tArr *value){
    int max = -1e9;
    for (int i = 0; i < value->size; i++)
    {
        if (max < value->arr[i])
        {
            max = value->arr[i];
        }
    }
    return max;
}

struct typeArr *nhapThongTin(){
    //Khai bao bien a kieu du lieu typeArr
    static tArr a; 
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &a.size);
    //Cap phat dong cho con tro arr
    a.arr = (int*)malloc(a.size*sizeof(int));
    for (int i = 0; i < a.size; i++)
    {
        printf("Nhap phan tu arr[%d]: ",i);
        // a.arr + i = &a.arr[i]: Tinh chat trong mang
        // scanf("%d",&a.arr[i]);
        scanf("%d",(a.arr+i));
    }    
    return &a;
}

int main(int argc, char const *argv[])
{
    //Khai bao con tro (de chua dia chi) kieu typeArr
    tArr *test;
    test = nhapThongTin();
    printf("So phan tu trong mang: %d\n",test->size);
    printf("Mang da nhap la: ");
    for (int i = 0; i < test->size; i++)
    {
        // test->arr[i]) = *(test->arr + i)): Tinh chat trong mang
        printf("%d  ",*(test->arr + i));
    }
    

    int opt;
    do
    {
        printf("\nNhap che do: ");
        scanf("%d",&opt);
    } while (opt < 0 || opt > 3);
    
    if (opt == 1)
    {
        beDenLon(test);
        printf("Mang da sap xep tu be den lon la: ");
        for (int i = 0; i < test->size; i++){
            printf("%d  ",*(test->arr + i));
        }
    }else if (opt == 2)
    {
        lonDenBe(test);
        printf("Mang da sap xep tu lon den be la: ");
        for (int i = 0; i < test->size; i++){
            printf("%d  ",*(test->arr + i));
        }
    }else{
        timSoLonNhat(test);
        printf("So lon nhat trong mang la: %d\n",timSoLonNhat(test));
    }
    return 0;
}
