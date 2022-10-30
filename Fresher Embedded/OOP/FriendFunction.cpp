#include <bits/stdc++.h>
using namespace std;

/* 
Friend Function: là hàm không phải là member trong class NHƯNG có thể truy cập các attribute, method private public trong class đó
Friend Class: class A là friend class của class B, do đó A có quyền truy cập đến các attribute, method private public trong class B đó
*/
class SinhVien{
    //Lớp bạn
    friend class GiaoVien;
    private:
        string id, name, birth;
        double gpa;
    public:
        //Constructor
        SinhVien(); 
        //Hàm nhập xuất thông tin
        void NhapThongTin();
        //Hàm bạn
        friend void inThongTin(SinhVien);
};

// Hàm bạn của class SinhVien
void inThongTin(SinhVien a){
    cout << a.id << " " << a.name << " " << a.birth << " " << fixed << setprecision(2) << a.gpa << endl;
}

SinhVien::SinhVien(){
    this->id = "18151223";
    this->name = this->birth = "";
    this->gpa = 0;
}

void SinhVien::NhapThongTin(){

    cout << "Nhap ten:";
    getline(cin,this->name); 

    cout << "Nhap ngay sinh:"; 
    cin >> this->birth;

    cout << "Nhap diem:"; 
    cin >> this->gpa;
    cin.ignore();
}

class GiaoVien{
    private:
        string khoa;
    public:
        void update(SinhVien &);
};

void GiaoVien::update(SinhVien &a){
    a.gpa = 4.0;
}

int main(int argc, char const *argv[])
{
    SinhVien A;
    A.NhapThongTin();
    GiaoVien B;
    B.update(A);
    inThongTin(A);
    return 0;
}
