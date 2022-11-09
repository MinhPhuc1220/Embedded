#include <stdio.h>
#include <assert.h>

//Không sử dụng debug nữa thì phải #define NDEBUG
#define NDEBUG


#include "main2.c"
/*
Dùng hàm assert để debug trong chương trình 
*/



int main(int argc, char const *argv[])
{
    //thử assert
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("i = %d\n",i);
    //     assert(i != 5);
    // }

    // lúc này chương trình sẽ báo lỗi, xảy ra ở dòng bao nhiêu
    thuong(4,0);
    return 0;
}
