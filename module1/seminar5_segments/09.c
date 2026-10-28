#include <stdio.h>

int adder(int a){
    static int res = 0;
    res += a;
    return res;
}

int main(){
    printf("%i\n", adder(10));
    printf("%i\n", adder(15));
    printf("%i\n", adder(70));
}