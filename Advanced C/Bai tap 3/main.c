#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Cho mot cai thung, no chua ngau nhien so vo do vang xanh, dem xem co bao nhieu doi vo cung mau
*/
typedef enum VO{
    VO_DO,
    VO_VANG,
    VO_XANH,
} VO;

typedef struct typeBox{
    VO *arr;
    int size;
} typeBox;

int dieuKien(char name[7]){
    if (strcmp((char *)"VO_DO",name) != 0 && strcmp((char *)"VO_VANG",name) != 0 && strcmp((char *)"VO_XANH",name) != 0){
        printf("Ban da nhap sai !! Nhap lai\n");
        return 1;
    }else return 0;
}

// ->: ra gia tri
void nhapThongTin(typeBox *a){
    char name[10];
    printf("Nhap so luong vo trong hop: ");
    scanf("%d",&(a->size));
    a->arr = (VO*)malloc(a->size * sizeof(VO));
    for (int i = 0; i < a->size; i++){
        label:
        printf("Nhap gia tri tai arr[%d] = ", i);
        scanf("%s",name);
        // Viet ham kiem tra 2 mang ki tu
        if (strcmp((char *)"VO_DO",name) == 0){
            a->arr[i] = VO_DO;
        }else if (strcmp((char *)"VO_VANG",name) == 0){
            a->arr[i] = VO_VANG;
        }else if (strcmp((char *)"VO_XANH",name) == 0){
            a->arr[i] = VO_XANH;
        }else{
            printf("Nhap sai thong tin!\n");
            goto label;
        }
    }
}

int demSoDoiVo(typeBox a){
    int voDO = 0, voVANG = 0, voXANH = 0;
    for (int i = 0; i < a.size; i++){
        if (a.arr[i] == VO_DO){
            voDO++;
        }else if (a.arr[i] == VO_VANG){
            voVANG++;
        }else if (a.arr[i] == VO_XANH){
            voXANH++;
        }  
    }
    int soDoiVo = voDO/2 + voVANG/2 + voXANH/2;
    return soDoiVo;
}

void inThongTin(typeBox a){
    printf("Mang da nhap la: ");
    for (int i = 0; i < a.size; i++){
        printf("%d  ",a.arr[i]);
    } 
}

int main(int argc, char const *argv[]){
    VO vo;
    typeBox box;
    nhapThongTin(&box);
    inThongTin(box);
    printf("\nSo doi vo trong box la %d",demSoDoiVo(box));
    return 0;
}
