#include <stdio.h>

int trib_mem[39];
int trib(int a){
    if (trib_mem[a]!=-1) return trib_mem[a];
    int p_trib;
    int pp_trib;
    int ppp_trib;
    if (trib_mem[a-3]!=-1) ppp_trib=trib_mem[a-3];
    else ppp_trib=trib(a-3);
    if (trib_mem[a-2]!=-1) pp_trib=trib_mem[a-2];
    else pp_trib=trib(a-2);
    if (trib_mem[a-1]!=-1) p_trib=trib_mem[a-1];
    else p_trib=trib(a-1);
    trib_mem[a]=p_trib+pp_trib+ppp_trib;
    return trib_mem[a];
}

int main(){
    for (int i=0;i<39;i++){
        trib_mem[i]=-1;
    }
    trib_mem[0]=0;
    trib_mem[1]=0;
    trib_mem[2]=1;
    
    int a;
    scanf("%i",&a);
    printf("%i\n",trib(a));
}