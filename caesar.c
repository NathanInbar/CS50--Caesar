#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void cipher(int key, string input);

int main(int argsc, string argv[])
{
    //first command-line argument is the cipher key
    if (argsc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;//return error 1
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;//return error 1
        }
    }

    int key = atoi(argv[1]);

    key %= 26;
    string input = get_string("plaintext: ");

    cipher(key, input);
}

void cipher(int key, string input)
{
    int inpLen = strlen(input);
    char c = 'a';

    printf("ciphertext: ");

    for (int i = 0; i < inpLen; i++)
    {
        c = input[i];

        //if c is alpha, add key and loop. else print
        if (isalpha(c))
        {
            c = (input[i] + key);

            if (!isalpha(c)) //if c is no longer alpha, loop back into the alpha chars
            {
                c -= 26;
            }
        }
        printf("%c", c);
    }

    printf("\n");
}
