#include <stdio.h>
#include <limits.h>
int main(){
    int n;
    int c=0;
    scanf("%i",&n);
    int max = INT_MIN;
    for (int i=0;i<n;i++){
        int a;
        scanf("%i",&a);
        if (a==max) c+=1;
        if (a>max){
            c=1;
            max=a;
        } 
    }
    printf("%i %i",max,c);
}