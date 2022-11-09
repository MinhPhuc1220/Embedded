#include <stdio.h>
// gcc -E main.c -o main.i

/*
Macro xảy ra ở giai đoạn tiền xử lý 
Thay thế các đoạn code được định nghĩa marco vào bất cứ chỗ nào ở chương trình nơi gọi marco đó
*/
// Basic define
#define MAX 100
#define sum(a,b) a+b

// Sử dụng #if #elif #else #endif để gán giá trị
#define A 40
#if A >= 50
int a = 10;
#elif A >= 30
int a = 20;
#else
int a = 40;
#endif

// Xem thử đã define MAX chưa, nếu chưa thì thực hiện lệnh trong #ifndef ... #endif, nếu đã define MAX rồi thì bỏ qua
#ifndef MAX
int a = 10;
#endif

// Khi một marco đã được define, nếu muốn define lại cho marco đó thì cần sử dụng lệnh #undef để hủy marco trước đó
#undef MAX
#define MAX 5

// Định nghĩa marcro tạo biến, muốn định nghĩa trong nhiều dòng thì sử dụng dấu \ trước khi xuống dòng
#define INIT_VAR(type, name) type test_##name
#define TYPE_VAR(name)  \
int i_##name;           \
double d_##name;        \
char c_##name

int main(int argc, char const *argv[])
{
    int a = 5, b = 6;
    printf("MAX = %d\n",MAX);
    printf("Tong %d va %d la %d", a, b, sum(a,b));
    INIT_VAR(int,mau);

    TYPE_VAR(test);
    //lúc này không cần khai báo vì đã sử dụng macro để khai báo
    i_test = 1;
    return 0;
}
