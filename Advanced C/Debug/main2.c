#include <assert.h>

void thuong (int a, int b){
    assert(b != 0 && "ERROR! Mau so bang 0");
    printf("Thuong a/b = %f\n", (double)a/b);
}