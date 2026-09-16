#include <stdio.h>

int one_pow(int n){
    if (n % 2 == 0) return 1;
    return -1;
}

long double pi(int n){
    long double res = 0;
    for (int i = 1; i <= n; i++){
        res += (long double)one_pow(i + 1)/(2 * i - 1);
    }
    return 4 * res;
}

int main(){
    int n;
    scanf("%i", &n);
    printf("%Lf\n", pi(n));
}