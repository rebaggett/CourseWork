#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string s = argv[1];
    if (argc == 2) //checks number of arguments
    {
        for(int i = 0, n = strlen(s); i < n; i++) //checks ints v chars
        {
            if (isdigit(s[i]) != 0)
            {
                int k = atoi(argv[1]);
                string plaintext = get_string("Enter plain text: ");
                printf("ciphertext: ");
                //checks to see if each value is a number
                for (int j = 0, o = strlen(plaintext); j < o; j++)
                {
                    if (isalpha(plaintext[j]) != 0) //only changes letters
                    {
                        if (islower(plaintext[j])) 
                            {
                                char result = ((plaintext[j] - 'a') + k) % 26 + 'a';
                                printf("%c", result);
                            }
                        else
                            {
                                char result = ((plaintext[j] - 'A') + k) % 26 + 'A';
                                printf("%c", result);
                            }
                    }
                    else
                        printf("%c", plaintext[j]); //prints non-letters as they are
                }
                printf("\n");
                return 0;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }   
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    }
