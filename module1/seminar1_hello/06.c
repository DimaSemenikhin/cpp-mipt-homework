#include <stdio.h>


int f(int a){
    if (a%2==0) return a/2;
    else return 3*a+1;
}
int main(){
    int n;
    int len=1;
    scanf("%i",&n);
    int max=n;
    printf("%i ",n);
    while (n!=1){
        n=f(n);
        printf("%i ",n);
        len+=1;
        if (n>max) max=n;
        
    }
    printf("\nLength = %i; Max = %i",len,max);
}