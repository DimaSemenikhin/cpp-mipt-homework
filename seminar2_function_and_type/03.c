#include <stdio.h>

void print_even(int left,int right){
    for (int i=left;i<=right;i++){
        if (i%2==0) printf("%i ",i);
    }
}

int main(){
    int a;
    int b;
    scanf("%i %i", &a, &b);
    print_even(a,b);
}