#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

double min(double a, double b)
{
    if(a <= b) return a;
    return b;
}

void swap(BYTE *a,BYTE *b)
{
    BYTE tmp = *a;
    *a = *b;
    *b = tmp;
}
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // 灰度直接将三原色的度直接取平均值赋值到原像素点上即可
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            BYTE blue = image[i][j].rgbtBlue;
            BYTE green = image[i][j].rgbtGreen;
            BYTE red = image[i][j].rgbtRed;
            BYTE avg = (BYTE)round((blue + green + red) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j < width; j++)
        {
            double originalBlue = image[i][j].rgbtBlue;
            double originalGreen = image[i][j].rgbtGreen;
            double originalRed = image[i][j].rgbtRed;
            double sepiaRed = 0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue;
            double sepiaGreen = 0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue;
            double sepiaBlue = 0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue;
            image[i][j].rgbtBlue = (int)min(255, round(sepiaBlue));
            image[i][j].rgbtGreen = (int)min(255, round(sepiaGreen));
            image[i][j].rgbtRed = (int)min(255, round(sepiaRed));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //这里主要是swap函数的具体实现，使用指针交换
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width/2 ;j++)
        {
            swap(&image[i][j].rgbtRed, &image[i][width - 1 - j].rgbtRed);
            swap(&image[i][j].rgbtBlue, &image[i][width - 1 - j].rgbtBlue);
            swap(&image[i][j].rgbtGreen, &image[i][width - 1 - j].rgbtGreen);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //学会指针声明二维数组
    RGBTRIPLE (*copy)[width]= calloc(height, width * sizeof(RGBTRIPLE));
    memcpy(copy, image, height * width * sizeof(RGBTRIPLE));
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            double cnt=0;
            double r = 0;
            double g = 0;
            double b = 0;
            for(int k = -1; k <= 1; k++)
            {
                for(int l = -1; l <= 1; l++)
                {
                    if(i + k < 0 || i + k >= height || j + l < 0 || j + l >= width) continue;
                    cnt++;
                    r += copy[i + k][j + l].rgbtRed;
                    g += copy[i + k][j + l].rgbtGreen;
                    b += copy[i + k][j + l].rgbtBlue;

                }
            }
            image[i][j].rgbtRed = round(r/cnt);
            image[i][j].rgbtGreen = round(g/cnt);
            image[i][j].rgbtBlue = round(b/cnt);
        }
    }
    return;
}
