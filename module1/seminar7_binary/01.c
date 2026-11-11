#include <stdio.h>
#include <string.h>

int main() {
    unsigned char a[16] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
                           0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};
    int i;

    for (i = 0; i < 16; i++) {
        printf("%02X ", a[i]);
    }
    printf("\n");

    for (i = 0; i < 16; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < 16; i++) {
        char ascii_char = (a[i] >= 32 && a[i] <= 126) ? (char)a[i] : '.';
        printf("Index: %02d  Hex: 0x%02X  ASCII: %c\n", i, a[i], ascii_char);
    }
    printf("\n");

    a[5] = 0xE5;

    memmove(&a[3], &a[0], 7);
    memmove(&a[0], &a[11], 5);
    memset(&a[5], 0, 6);

    for (i = 0; i < 16; i++) {
        printf("%02X ", a[i]);
    }
    printf("\n");

    return 0;
}