#include <stdio.h>

int main() {
    union {
        int a[4];
        char str[16];
    } u;
    int temp[4] = {1819043144, 1461726319, 1684828783, 2593};
    for (int i = 0; i < 4; i++) {
        u.a[i] = temp[i];
    }
    printf("%s\n", u.str);
}