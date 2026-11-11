#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "rb");
    fseek(file, -3, SEEK_END);

    unsigned char buffer[3];
    size_t bytes_read = fread(buffer, 1, 3, file);

    for (size_t i = 0; i < bytes_read; i++) {
        printf("%zu: 0x%02X\n", i + 1, buffer[i]);
    }

    fclose(file);
}