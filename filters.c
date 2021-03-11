#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Work across every row
    for (int i = 0; i < height; i++)
    {
        //Work across every column
        for (int j = 0; j < width; j++)
        {
            //Identify each color value
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;
            float average = (red + green + blue)/3;
            average = round(average);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Work across every row
    for (int i = 0; i < height; i++)
    {
        //Work across every column
        for (int j = 0; j < width; j++)
        {
            //Identify each color value
            float red1 = image[i][j].rgbtRed;
            float green1 = image[i][j].rgbtGreen;
            float blue1 = image[i][j].rgbtBlue;
            //Change red
            float sred = (red1 *.393) + (.769 * green1) + (.189 * blue1);
            if (sred > 255)
            {
                sred = 255;
            }
            //Change green
            float sgreen = (red1 *.349) + (.686 * green1) + (.168 * blue1);
            if (sgreen > 255)
            {
                sgreen = 255;
            }
            //Change blue
            float sblue = (red1 *.272) + (.534 * green1) + (.131 * blue1);
            if (sblue > 255)
            {
                sblue = 255;
            }
            image[i][j].rgbtRed = round(sred);
            image[i][j].rgbtGreen = round(sgreen);
            image[i][j].rgbtBlue = round(sblue);
        }
    }      
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflection[height][width];
    //Work across every row
    for (int i = 0; i < height; i++)
    {
        //Work across every column
        for (int j = 0; j < width; j++)
        {
            //Set reflection image
            reflection[i][j] = image[i][width - 1 - j];
        }
    }
    //Accross every row and column, sets image to reflection
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = reflection [k][l];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Sets copy image
    RGBTRIPLE blurry[height][width];
    //Sets values for average red, green, blue, and number to divide by
    int count;
    float red;
    float green;
    float blue;
    //Copy image
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            blurry[a][b] = image [a][b];
        }
    }
    //Start blurring over rows
    for (int i = 0; i < height; i++)
    {
        // Then columns
        for (int j = 0; j < width; j++)
        {
            count = 0;
            red = 0;
            green = 0;
            blue = 0;
            //Starting mini grid rows
            for (int x = -1; x <= 1; x++)
            {
                //Starting mini grid columns
                for (int y = -1; y <= 1; y++)
                {
                    //If pixel is within grid, take average and add to count
                    if (i + x >= 0 && i + x < height && j + y >= 0 && j + y < width)
                    {
                        red += image[i + x][j + y].rgbtRed;
                        green += image[i + x][j + y].rgbtGreen;
                        blue += image[i + x][j + y].rgbtBlue;
                        count++;
                    }
                }
            }
            //Set pixel as average
            red = round(red / count);
            green = round(green / count);
            blue = round(blue / count);
            blurry[i][j].rgbtRed = red;
            blurry[i][j].rgbtGreen = green;
            blurry[i][j].rgbtBlue = blue;
        }
    }
    //Copy blurry
    for (int c = 0; c < height; c++)
    {
        for (int d = 0; d < width; d++)
        {
            image[c][d] = blurry[c][d];
        }
    }
    return;
}
