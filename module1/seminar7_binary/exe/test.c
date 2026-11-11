#include <stdio.h>

// Вспомогательная функция для печати памяти
void print_memory(void *ptr, size_t size) {
    unsigned char *byte_ptr = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02X ", byte_ptr[i]);
    }
    printf("\n");
}

int main() {
    int a = 0x11223344;
    int b = 1000000000;
    int c = 65535;
    int d = -1;
    int array[3] = {10, 2000, 65535};
    char str[9] = "Cat\nDog\n";
    float x = 1.0f;

    printf("a:     "); print_memory(&a, sizeof(a));
    printf("b:     "); print_memory(&b, sizeof(b));
    printf("c:     "); print_memory(&c, sizeof(c));
    printf("d:     "); print_memory(&d, sizeof(d));
    printf("array: "); print_memory(array, sizeof(array));
    printf("str:   "); print_memory(str, sizeof(str));
    printf("x:     "); print_memory(&x, sizeof(x));

    return 0;
}