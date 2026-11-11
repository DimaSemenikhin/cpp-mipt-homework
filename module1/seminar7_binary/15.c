#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define M_PI 3.14159265358

struct color
{
    unsigned char r, g, b;
};
typedef struct color Color;

const Color White = {255, 255, 255};
const Color Black = {0, 0, 0};


// Функция, которая рисует линию от (x0, y0) до (x1, y1) цвета c на холте data
void draw_line(Color* data, int width, int height, int x0, int y0, int x1, int y1, Color c)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int ysign = y1 > y0 ? 1 : -1;
    int xsign = x1 > x0 ? 1 : -1;
    int error = (dx > dy ? dx : -dy)/2;

    if (dx >= dy)
    {
        int y = y0;
        for (int x = x0 ; x != x1; x += xsign)
        {
            data[x + width * y] = c;
            error += dy;
            if (error >= dx)
            {
                y += ysign;
                error -= dx;
            }
        }
    }
    else
    {
        int x = x0;
        for (int y = y0 ; y != y1; y += ysign)
        {
            data[x + width * y] = c;
            error += dx;
            if (error >= dy)
            {
                x += xsign;
                error -= dy;
            }
        }
    }

}

int main(int argc, char *argv[])
{   
    if (argc != 2){
        printf("Ошибка входных данных");
        return 0;
    }

    int width = 500, height = 500;
    Color* data = (Color*)malloc(sizeof(Color) * width * height);

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            data[i + width * j] = Black;
        }
    }
    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++){
        Color c = {rand() % 256, rand() % 256, rand() % 256};
        int x0 = rand() % (width + 1);
        int x1 = rand() % (width + 1);
        int y0 = rand() % (height + 1);
        int y1 = rand() % (height + 1);
        draw_line(data, width, height, x0, y0, x1, y1, c);
    }

    FILE* file = fopen("randlines.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, file);
    fclose(file);
    
    free(data);
}