#include <stdio.h>

int main(){
    int n;
    int cur;
    scanf("%i",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%i",&cur);
        printf("%i ",cur);
        a[i]=cur;
    }
    for (int i=0;i<n;i++){
        printf("%i ",a[i]);
    }
}