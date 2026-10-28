#include <stdio.h>
void cube(float* px){
    float a = *px;
    *px *= a*a;
}

int main(){
    float a;
    scanf("%f", &a);
    float* px = &a;
    printf("%f\n", a);
    cube(px);
    printf("%f\n", a);
}