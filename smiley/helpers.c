#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    RGBTRIPLE rgb;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue /= 2;
            image[i][j].rgbtGreen /= 2;
            image[i][j].rgbtRed /= 2;
        }
    }
}
