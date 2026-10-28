#include <stdio.h>
#include <stddef.h>
struct cat {
    char x;
    size_t y;
};
struct dog {
    size_t y;
    char x;
};
struct mouse {
    char x;
    char y;
    size_t z;
};
struct rat {
    char x;
    size_t z;
    char y;
};
struct fox {
    char x;
    struct mouse y;
};

int main() {
    printf("1. char: size = %zu\n", sizeof(char));
    printf("2. int: size = %zu\n", sizeof(int));
    printf("3. size_t: size = %zu\n", sizeof(size_t));
    printf("4. int[10]: size = %zu\n", sizeof(int[10]));
    printf("5. int*: size = %zu\n", sizeof(int*));
    printf("6. struct cat: size = %zu\n", sizeof(struct cat));
    printf("7. struct dog: size = %zu\n", sizeof(struct dog));
    printf("8. struct mouse: size = %zu\n", sizeof(struct mouse));
    printf("9. struct rat: size = %zu\n", sizeof(struct rat));
    printf("10. struct fox: size = %zu\n", sizeof(struct fox));
    
    return 0;
}