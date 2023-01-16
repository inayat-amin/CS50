#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

void swapPixels(RGBTRIPLE *pixelRight, RGBTRIPLE *pixelLeft)
{
    RGBTRIPLE temp = *pixelRight;
    *pixelRight = *pixelLeft;
    *pixelLeft = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            swapPixels(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rows[3] = {i - 1, i, i + 1};
            int cols[3] = {j - 1, j, j + 1};
            int counter = 0;
            float red = 0;
            float green = 0;
            float blue = 0;
            
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    int pixel_row = rows[row];
                    int pixel_col = cols[col];
                    
                    if (pixel_row >= 0 && pixel_row < height && pixel_col >= 0 && pixel_col < width)
                    {
                        RGBTRIPLE pixel = image[pixel_row][pixel_col];
                        
                        red = red + pixel.rgbtRed;
                        green = green + pixel.rgbtGreen;
                        blue  = blue + pixel.rgbtBlue;
                        
                        counter++;
                    }
                }
            }
            
            temp[i][j].rgbtRed = round(red/counter);
            temp[i][j].rgbtGreen = round(green/counter);
            temp[i][j].rgbtBlue = round(blue/counter);
            
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rows[3] = {i - 1, i, i + 1};
            int cols[3] = {j - 1, j, j + 1};
            
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            float Gy_red = 0, Gy_green = 0, Gy_blue = 0;
            
            for ( int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    int pixel_row = rows[row];
                    int pixel_col = cols[col];
                    
                    if (pixel_row >= 0 && pixel_row < height && pixel_col >=0 && pixel_col < width)
                    {
                        RGBTRIPLE pixel = image[pixel_row][pixel_col];
                        
                        Gx_red = Gx_red + (Gx[row][col] * pixel.rgbtRed);
                        Gx_green = Gx_green + (Gx[row][col] * pixel.rgbtGreen);
                        Gx_blue = Gx_blue + (Gx[row][col] * pixel.rgbtBlue);
                        
                        Gy_red = Gy_red + (Gy[row][col] * pixel.rgbtRed);
                        Gy_green = Gy_green + (Gy[row][col] * pixel.rgbtGreen);
                        Gy_blue = Gy_blue + (Gy[row][col] * pixel.rgbtBlue);
                    }
                }
            }
            
            int red = round(sqrt((Gx_red*Gx_red) + (Gy_red*Gy_red)));
            int green = round(sqrt((Gx_green*Gx_green) + (Gy_green*Gy_green)));
            int blue = round(sqrt((Gx_blue*Gx_blue) + (Gy_blue*Gy_blue)));
        
            temp[i][j].rgbtRed = red > 255 ? 255: red;
            temp[i][j].rgbtGreen = green > 255 ? 255: green;
            temp[i][j].rgbtBlue = blue > 255 ? 255: blue;
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    
    return;
}
