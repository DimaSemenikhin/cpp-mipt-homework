#include <stdio.h>

void alice(int a);

void bob(int a){
    while ( a % 2 == 0) {
        a /= 2;
        printf("Bob: %i\n", a);
    }
    if (a == 1) return;
    alice(a);
}

void alice(int a){
    a = 3 * a + 1;
    printf("Alice: %i\n", a);
    bob(a);
}

int main(){
    int n;
    scanf("%i", &n);
    if (n % 2 == 0) bob(n);
    else alice(n);
}
