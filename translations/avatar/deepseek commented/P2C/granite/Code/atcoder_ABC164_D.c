

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc!= 2)
    {
        printf("Usage:./caesar k\n");
        return 1;
    }

    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string ciphertext = "";

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            c += k;

            if (isupper(c) && c > 'Z')
            {
                c -= 26;
            }
            else if (islower(c) && c > 'z')
            {
                c -= 26;
            }
        }

        ciphertext = ciphertext + string(&c, 1);
    }

    printf("ciphertext: %s\n", ciphertext);
}

// END-OF-CODE