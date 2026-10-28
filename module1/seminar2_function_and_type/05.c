#include <stdio.h>

void print_binary(int a){
    if (a==0) return;
    print_binary(a/2);
    printf("%i",a%2);
}

int main(){
    int a;
    scanf("%i",&a);
    print_binary(a);
}
/*10=1010_2
10/2=5(0)
5/2=2(1)
2/2=1(0)
1/2=0(1)
*/