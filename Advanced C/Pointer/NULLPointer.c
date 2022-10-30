#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Khi khai báo con trỏ mà chưa gán cho bất kì giá trị nào thì phải gán cho NULL
    int *ptr;
    ptr = NULL;
    printf("Dia chi con tro NULL: %p",ptr);
    return 0;
}
