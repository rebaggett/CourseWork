#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    string s = argv[1];
    if (argc == 2) //checks number of arguments
    {
        for(int i = 0, n = strlen(s); i < n; i++) //checks ints v chars
        {
            int x = 0;
            if (isalpha(s[i]) == 0) //if a number return error
            {
                x += 1;
            }
            if (x >= 1)
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        string plaintext = get_string("Enter plain text: ");
        printf("ciphertext: ");
        for(int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int key = shift(s[i%strlen(s)]);
            //checks to see if each value is a number
            if (isalpha(plaintext[i]) != 0) //only changes letters
            {
                if (isupper(plaintext[i]))
                {
                   char result = (((plaintext[i] - 'A') + key)%26) + 'A';
                   printf("%c", result);
                }
                else
                {
                   char result = (((plaintext[i] - 'a') + key)%26) + 'a';
                   printf("%c", result); 
                }
                
            }
            else
                printf("%c", plaintext[i]); //prints non-letters as they are
               
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}
int shift (char c)
{
    int result;
    if isupper(c)
    {
        result = (c - 65);
    }
    else
    {
        result = (c - 97);
    }
    return result;
}
