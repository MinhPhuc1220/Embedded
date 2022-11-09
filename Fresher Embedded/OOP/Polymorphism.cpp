#include <bits/stdc++.h>
using namespace std;
/*
Tính đa hình: Nhiều hàm có cùng tên nhưng chỉ khác input parametter, nên khi truyền vào tham số kiểu nào sẽ gọi ra hàm tương ứng để sử dụng
Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng cho từng hàm hay phương  thức với những kiểu dữ liệu khác nhau
Tính chất OOP:
- Encapsulation (đóng gói)
- Inheritance (kế thừa)
- Polymorphism (đa hình)
*/
class TinhToan
{
    public:
        void sum(int a, int b);
        void sum(int a, int b, int c);
        void sum(int a, int b, int c, int d);
};

void TinhToan::sum(int a, int b){
    cout << "Tong 2 so la: " << a + b << endl; 
}

void TinhToan::sum(int a, int b, int c){
    cout << "Tong 3 so la: " << a + b + c << endl; 
}

void TinhToan::sum(int a, int b, int c, int d){
    cout << "Tong 4 so la: " << a + b + c + d << endl; 
}

//Template
template <typename var, typename var2>
var sub(var a, var2 b){
    return var(a - b);
}

int main(int argc, char const *argv[])
{
    //Polymorphism (đa hình)
    TinhToan obj;
    obj.sum(2,3);
    obj.sum(2,3,4);
    obj.sum(2,3,4,5);

    //Template
    cout << "Hieu 2 so la: " << sub(5.5,3) << endl;
    return 0;
}
