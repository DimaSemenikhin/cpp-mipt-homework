#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

void draw_func(Color* data, int width, int height, float f(float x, float y)){
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            data[i + width * j].r = f((float)(i - width / 2) / width, (float)(j - width / 2) / height);
            data[i + width * j].g = f((float)(i - width / 2) / width, (float)(j - width / 2) / height);
            data[i + width * j].b = f((float)(i - width / 2) / width, (float)(j - width / 2) / height);
        }
    }
}

float f1(float x, float y){
    return 255 * fabs(x * y);
}

float f2(float x, float y){
    return 255 * fabs(sin(10 * (x * x + y * y)));
}
float f3(float x, float y){
    return 255 * fabs(sin(5000 * (x * x + y * y)));
}
float f4(float x, float y){
    return 255 * fabs(cos(10 * x) * sin(10 * y));
}
float f5(float x, float y){
    return 255 * fabs(sin(3 / (0.1 + fabs(x))) + sin(3 / (0.1 + fabs(y))));
}

int main(){
    
    int width = 500, height = 500;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);
    memset(data, 0, sizeof(Color) * width * height);

    draw_func(data, width, height, f5);
    
    FILE* file = fopen("10_5.ppm", "wb");
    fprintf(file, "P6\n%i %i\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
    
    free(data);
}