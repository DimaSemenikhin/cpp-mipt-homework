#include <stdio.h>

int sum_of_digits(int a){
    int res=0;
    while (a!=0){
        res+=a%10;
        a/=10;
    }
    return res;
}

int sum_of_digits_rec(int a){
    if (a==0) return 0;
    return a%10+sum_of_digits_rec(a/10);
}
int main(){
    int a;
    scanf("%i",&a);
    printf("%i %i",sum_of_digits(a),sum_of_digits_rec(a));
}