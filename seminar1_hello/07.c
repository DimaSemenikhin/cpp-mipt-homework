#include <stdio.h>

int power(int a,int i){
    int res=1;
    for (int j=0;j<i;j++){
        res*=a;
    }
    return res;
}
int main(){
    int n;
    int m;
    scanf("%i %i",&n,&m);
    int S=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            S+=(i+1)*(j+1)*power(-1,i+j+2);
        }
    }
    printf("%i\n",S);
}