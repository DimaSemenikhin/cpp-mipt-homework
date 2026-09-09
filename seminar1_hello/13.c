#include <stdio.h>

/*int element(int num,int n, int* a, int* b){
    int i=num/n;
    int j=num%n;
    int res_cur=0;
    for (int k=0;k<n;k++){
        res_cur+=a[i*n+k-1]*b[k*n+j-1];
    }
    return res;
}*/
int main(){
    int n;
    scanf("%i",&n);
    int len=n*n;
    int a[len];
    int b[len];
    int cur;
    int res[len];
    for (int j=0;j<len;j++){
        scanf("%i",&cur);
        a[j]=cur;

    }
    scanf("%i",&n);
    for (int j=0;j<len;j++){
        scanf("%i",&cur);
        b[j]=cur;

    }   
    for (int num=0;num<len;num++){
        int i=num/n;
        int j=num%n;
        int res_cur=0;
        for (int k=0;k<n;k++){
            res_cur+=a[i*n+k]*b[k*n+j];
        }
        res[num]=res_cur;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%i ",res[i*n+j]);
        }
        printf("\n");
    }
}