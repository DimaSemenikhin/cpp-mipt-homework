#include <stdio.h>

int reverse(int array[], int n){
    int cur;
    for (int i = 0; i <= ( (n + 1) / 2 - 1); i++ ){
        cur = array[n - i - 1];
        array[n - i - 1] = array[i];
        array[i] = cur;
    }
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
    reverse(a, n);
    for (int i = 0; i < n; i++){
        printf("%i ", a[i]);
    }
    printf("\n");
}