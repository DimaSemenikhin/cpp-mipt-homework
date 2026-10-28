#include <stdio.h>

int main(){
    int n;
    int m;
    int cur=0;
    int a[m];
    scanf("%i %i",&n,&m);
    for (int i=0;i<m;i++){
        a[i]=0;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%i",&cur);
            a[j]+=cur;
        }
    }

    for (int i=0;i<m;i++){
        printf("%i ",a[i]);
    }
}