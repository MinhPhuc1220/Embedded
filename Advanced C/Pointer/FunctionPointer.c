#include <stdio.h>


void tinhTong(int a, int b){
    printf("Tong %d va %d la: %d\n", a, b, a + b);
}

void tinhHieu(int a, int b){
    printf("Hieu %d va %d la: %d\n", a, b, a - b);
}

int tinhLuyThua(int a){
    return a*a;
}

void tinhToan(void (*phepToan)(int,int), int a, int b){
    phepToan(a,b);
}

int main(int argc, char const *argv[])
{
    // Khai báo con trỏ hàm
    void (*ptrPhepTinh) (int, int);
    ptrPhepTinh = &tinhTong;
    ptrPhepTinh(5,7);

    int (*ptrLuyThua) (int);
    ptrLuyThua = &tinhLuyThua;
    printf("Luy thua cua 5 la %d\n",ptrLuyThua(5));

    //Hàm có input parametter là con trỏ hàm
    tinhToan(&tinhTong, 5, 5);
    tinhToan(tinhHieu, 5, 5); // có thể ko có dấu &
    return 0;
}
