#include <stdio.h>

unsigned long long A(int n, int k){
    unsigned long long result = 1;
    for (int i = (n - k + 1); i <= n; i++ ){
        result *= i;
    }
    return result;
}

int main(){
    int n;
    int k;
    scanf("%i %i", &n, &k);
    printf("%llu\n", A(n, k));
}

