#include <stdio.h>

int count_even(int array[], int n){
    int res = 0;
    for (int i = 0; i < n; i++ ){
        if (array[i] % 2 == 0) res += 1;
    }
    return res;
}

int main(){
    int n;
    int cur;
    int a[100];
    scanf("%i", &n);
    for (int i = 0; i < n; i++ ){
        scanf("%i", &cur);
        a[i] = cur;
    }
    printf("%i\n", count_even(a, n));
}