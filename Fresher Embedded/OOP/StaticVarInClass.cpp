#include <bits/stdc++.h>
using namespace std;

/* SV001 => SV002 => SV003
Static Var In Class: không thể khởi tạo giá trị cho nó trong Class, phải khởi tạo ở bên ngoài
Nó dùng chung cho tất cả các obj thuộc cùng Class (chung địa chỉ nếu khởi tạo nhiều Obj)
*/
class SinhVien{
    private:
        string id, name, birth;
        double gpa;
        static int cnt;
    public:
        //Constructor
        SinhVien(); 
        //Hàm nhập xuất thông tin
        void NhapThongTin();
        void InThongTin();
        //Hàm tăng biến cnt
        void tangCnt();
        int getCnt();
        int* getCntAddress();
};

// Khởi tạo giá trị cho Static Var 
int SinhVien::cnt = 0;

void SinhVien::tangCnt(){
    ++cnt;
}

int SinhVien::getCnt(){
    return cnt;
}

int* SinhVien::getCntAddress(){
    return &cnt;
}

SinhVien::SinhVien(){
    this->id =this->name = this->birth = "";
    this->gpa = 0;
}

void SinhVien::NhapThongTin(){
    ++cnt;
    this->id = "SV" + string(3-to_string(cnt).length(),'0') + to_string(cnt);

    cout << "Nhap ten:";
    getline(cin,this->name); 

    cout << "Nhap ngay sinh:"; 
    cin >> this->birth;

    cout << "Nhap diem:"; 
    cin >> this->gpa;
    cin.ignore();
}

void SinhVien::InThongTin(){
    cout << this->id << " " << this->name << " " << this->birth << " " << fixed << setprecision(2) << this->gpa << endl;
}

int main(int argc, char const *argv[])
{
    SinhVien A;
    A.NhapThongTin();
    A.InThongTin();
    SinhVien B;
    B.NhapThongTin();
    B.InThongTin();

    // SinhVien A;
    // A.tangCnt();
    // A.tangCnt();
    // SinhVien B;
    // B.tangCnt();
    // SinhVien C;
    // cout << A.getCnt() << " " << B.getCnt() << " " << C.getCnt() << endl;
    // cout << "Dia chi A: " << A.getCntAddress() << endl;
    // cout << "Dia chi B: " << B.getCntAddress() << endl;
    // cout << "Dia chi C: " << C.getCntAddress() << endl;
    return 0;
}
