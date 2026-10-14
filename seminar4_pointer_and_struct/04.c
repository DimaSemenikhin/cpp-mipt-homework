#include <stdio.h>

void mult2(int* p, size_t n){
    for (int  i = 0; i < n; i++){
        *(p+i) *= 2;
    }
}

int main(){
    int numbers[5] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++){
        printf("%i ", numbers[i]);
    }
    int* p = numbers;
    printf("\n");
    mult2(p, (size_t)5);
    for (int i = 0; i < 5; i++){
        printf("%i ", numbers[i]);
    }
}