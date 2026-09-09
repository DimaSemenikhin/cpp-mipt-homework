#include <stdio.h>

int count(int a){
    int res=0;
    while (a!=0){
        res+=a%10;
        a/=10;
    }
    return res;
}

int main(){
    int n;
    int cur;
    scanf("%i",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%i",&cur);
        a[i]=cur;
    }
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (count(a[j])>count(a[j+1])){
                cur=a[j];
                a[j]=a[1+j];
                a[1+j]=cur;
            }
        }
    }
    for (int i=0;i<n;i++){
        printf("%i ", a[i]);
    }


}