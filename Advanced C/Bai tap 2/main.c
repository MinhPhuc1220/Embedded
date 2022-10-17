#include <stdio.h>

/*
Nhap vao ngay thang nam sinh, In ra tuoi
*/

struct SinhNhat
{
    int ngaySinh, thangSinh, namSinh;
};

//1 la dieu kien sai,0 la dieu kien dung
int dieuKien(int ngaySinh, int thangSinh, int namSinh){
    if (ngaySinh < 0 || ngaySinh > 31)
    {
        printf("Khong ton tai ngay %d",ngaySinh);
        return 1;
    }else if (thangSinh < 0 || thangSinh > 12)
    {
        printf("Khong ton tai thang %d",thangSinh);
        return 1;
    }else if (namSinh < 0 || namSinh > 2022)
    {
        printf("Khong ton tai nam %d",namSinh);
        return 1;
    }else{
        return 0;
    }
}

int tinhTuoi(int ngaySinh, int thangSinh, int namSinh){
    int ngayHienTai = 17;
    int thangHienTai = 10;
    int namHienTai = 2022;

    int ngay = ngayHienTai - ngaySinh;
    int thang = thangHienTai - thangSinh;
    int nam = namHienTai - namSinh;
    int soTuoi = (nam*365 + thang*30 + ngay)/365;
    return soTuoi;
}

int main(int argc, char const *argv[])
{
    int ngaySinh, thangSinh, namSinh;
    do
    {
        printf("Nhap vao ngay: ");
        scanf("%d",&ngaySinh);
        printf("Nhap vao thang: ");
        scanf("%d",&thangSinh);
        printf("Nhap vao nam: ");
        scanf("%d",&namSinh);
    } while (dieuKien(ngaySinh, thangSinh, namSinh));
    
    printf("Ngay thang nam sinh da nhap: %d/%d/%d\n",ngaySinh,thangSinh,namSinh);
    printf("So tuoi cua ban la: %d",tinhTuoi(ngaySinh,thangSinh,namSinh));
    return 0;
}
