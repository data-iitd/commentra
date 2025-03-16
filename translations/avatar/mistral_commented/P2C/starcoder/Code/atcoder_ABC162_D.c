#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char S[100000];
    scanf("%s", S);

    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < strlen(S); i++)
    {
        if (S[i] == 'R')
            rNum++;
        else if (S[i] == 'G')
            gNum++;
        else if (S[i] == 'B')
            bNum++;
    }

    int sum = 0;
    for (int step = 1; step <= ceil(N / 2.0); step++)
    {
        for (int i = 0; i < strlen(S) - 2; i++)
        {
            char s[3];
            strncpy(s, S + i, 3);
            if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0)
                sum++;
        }
    }

    printf("%d\n", rNum * gNum * bNum - sum);
    return 0;
}

