#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Declarations
    FILE *mcard = NULL; //Establishes file called mcard, where input will be opened
    BYTE buffer[512]; //Establishes buffer where files can be read
    int count = 0; //Makes counter which will count how many images have been found
    char filename[8]; //Creates string for name of JPEG
    FILE *image = NULL; //Where images will be opened to

    //Checks for valid input
    if (argc != 2)
        {
            printf ("Usage: ./recover image\n");
            return 1;
        }
    mcard = fopen(argv[1], "r");
    if (mcard == NULL)
    {
        return 1;
    }

    //Reads file to buffer and ensures return value is one block
    while (fread(buffer, sizeof(buffer), 1, mcard))
    {
        //Checks that file is JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Checks if image is first
            if (count == 0)
            {
                //Adds to count, so we start with JPEG 1 instead of 0
                //Names file, opens and write
                sprintf(filename, "%03i.jpg", count);
                image = fopen(filename, "w");
                fwrite (buffer, 512, 1, image);
                count++;
            }
            else
            {
                //Closes previous file then repeats above process
                fclose(image);
                sprintf(filename, "%03i.jpg", count);
                image = fopen(filename, "w");
                fwrite (buffer, 512, 1, image);
                count++;
            }
        }
        else if (count > 0)
        {
            //If not beginning of JPEG, continue writing on old JPEG
            fwrite(buffer, 512, 1, image);
        }
    }
    fclose(image);
    return 0;
}
