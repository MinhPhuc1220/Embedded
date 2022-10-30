#include <stdio.h>

int a = 10;
float f = 10.5;
char c = 'A';
//Con trỏ void là 1 con trỏ đặc biệt nên có thể trỏ đến mọi địa chỉ. 
//Nên để có thể lấy giá trị của địa chỉ đó ra cần phải ép kiểu cho nó về kiểu dữ liệu nào đó.
void *ptr;

int main(int argc, char const *argv[])
{
    ptr = &a;
    printf("Dia chi a: %p\n",ptr);
    printf("Gia tri a: %d\n",*(int *)ptr);

    ptr = &f;
    printf("Dia chi f: %p\n",ptr);
    printf("Gia tri f: %d\n",*(float *)ptr);

    ptr = &c;
    printf("Dia chi c: %p\n",ptr);
    printf("Gia tri c: %c\n",*(char *)ptr);
    return 0;
}

