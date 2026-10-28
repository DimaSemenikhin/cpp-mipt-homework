#include <stdio.h>

int main(){
    int n;
    scanf("%i",&n);
    int m[n];
    int move[n];
    int cur;
    int motion=0;
    for (int i=0;i<n;i++){
        scanf("%i",&cur);
        m[i]=cur;
        if (cur<0){
            motion+=1;
        }
        move[i]=motion;
    }

    for (int i=0;i<n;i++){
        
        if (m[i]>=0){
            m[i-move[i]]=m[i];
        }
        if (i>n-motion-1){
            m[i]=-1;
        }
    }
    for (int i=0;i<n;i++){
        if (m[i]!=-1) printf("%i ", m[i]);
    }
}