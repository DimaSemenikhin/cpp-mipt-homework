#include <stdio.h>

int main(){
    int l;
    int r;
    int c;
    scanf("%i %i %i",&l,&r,&c);
    int cur=l+c-l%c;
    
    while (cur<=r){
        
        printf("%i ",cur);
        cur+=c;
    }

}