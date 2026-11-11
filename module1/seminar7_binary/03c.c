#include <stdio.h>
#include <string.h>


int main() {
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};
    char str[17];
    memcpy(str, a, 16);
    printf("%s\n", str);
}