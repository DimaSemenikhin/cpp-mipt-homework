#include <stdio.h>

size_t count_if(const int* a, int n, int (*pred)(int b)){
    size_t count = 0;
    for (int i = 0; i < n; i++){
        if (pred(a[i])) count += 1;
    }
    return count;
}

int is_negative(int a){
    return (a < 0);
}

int is_even(int a){
    return !(a % 2);
}

int is_square(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    
    int left = 1; 
    int right = n;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        int square = mid * mid;
        
        if (square == n) return 1;
        if (square < n) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main(){
    int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};

    printf("%zu\n", count_if(a, 10, is_negative));
    printf("%zu\n", count_if(a, 10, is_even));
    printf("%zu\n", count_if(a, 10, is_square));
}