#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check for command line argument
    if (argc != 2)
    {
        printf("Enter the key in command-line argument and try again.\n");
        exit(1);
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("The key is not 26 charachters\n");
        exit(1);
    }
    for (int i = 1; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Invalid key\n");
            exit(1);
        }
    }
    string plainText = get_string("plaintext: ");

    //sub ascii-65 to get position in the key
    int len = strlen(plainText);
    char cipherText[len];

    for (int i = 0; plainText[i] != '\0'; i++)
    {
        if (isupper(plainText[i]))
        {
            cipherText[i] = argv [1] [((int) plainText[i]) - 65];
            cipherText[i] = toupper(cipherText[i]);
        }

        else if (islower(plainText[i]))
        {
            cipherText[i] = argv [1] [((int) plainText[i]) - 97];
            cipherText[i] = tolower(cipherText[i]);
        }

        else
        {
            cipherText[i] = plainText[i];
        }
    }

    //print cipher text
    printf("ciphertext: ");
    for(int i = 0; i < len; i++)
    {
        printf("%c",cipherText[i]);
    }
    printf("\n");

}
