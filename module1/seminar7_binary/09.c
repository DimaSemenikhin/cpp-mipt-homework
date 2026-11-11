#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c){
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if ((i - x0) * (i - x0) + (j - y0) * (j - y0) <= r * r)
            {
                data[i + width * j].r = c.r;
                data[i + width * j].g = c.g;
                data[i + width * j].b = c.b;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int width = 600, height = 400;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);
    memset(data, 0, sizeof(Color) * width * height);
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);    
    for (int i = 0; i < n; i++){
        int x0 = rand() % (width + 1);
        int y0 = rand() % (height + 1);
        int r = rand() % (b - a + 1) + a;
        Color c = {rand() % 255, rand() % 255, rand() % 255};
        draw_circle(data, width, height, x0, y0, r, c);
    }

    FILE* file = fopen("09.ppm", "wb");
    fprintf(file, "P6\n%i %i\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
    
    free(data);
}