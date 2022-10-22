#include <stdio.h>

/*Tìm kiếm một chuỗi con trong một chuỗi và đếm xem chuỗi con đó xuất hiện bao nhiêu lần.*/
int doDaiChuoi(char c[]){
    int cnt = 0;
    while(c[cnt] != '\0'){
        cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    char s1[100] = "Hom nay toi di hoc, di lam, di choi, di an, di uong";
    char s2[100] = "hoc";
    // printf("Do dai chuoi 2: %d\n",doDaiChuoi(s2));
    int n = 0, m = 0, cnt = 0;

    while(s1[n] != '\0'){
        if(s1[n] == s2[m]){
            while(s1[n] == s2[m]  && s1[n] !='\0'){
                n++;
                m++;
            }
            if(m == doDaiChuoi(s2) && (s1[n] == ' ' || s1[n] == '\0') || s1[n] == ',' || s1[n] == '.'){
                cnt++;
            }
        }else{
            while(s1[n] != ' '){
                n++;
                if(s1[n] == '\0')
                    break;
            }
        }
        n++;
        m = 0;
    }

    printf("Chuoi ban dau: %s", s1);
    if(cnt > 0){
        printf("\nChuoi '%s' xuat hien %d lan\n", s2, cnt);
    }else{
        printf("\nChuoi '%s' khong xuat hien trong cau.\n", s2);
    }
    return 0;
}
