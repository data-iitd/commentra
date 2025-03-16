#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char s[100000];
    int num_g, num_p, score = 0;
    scanf("%s",s);
    num_g = num_p = 0;
    for(int i = 0 ; s[i]!= '\0' ; i++)
    {
        if(s[i] == 'g')
        {
            if(num_g - num_p > 0)
            {
                score += 1;
                num_p += 1;
            }
            else
            {
                score = score;
                num_g += 1;
            }
        }
        else if(s[i] == 'p')
        {
            if(num_g - num_p > 0)
            {
                score = score;
                num_p += 1;
            }
            else
            {
                score -= 1;
                num_g += 1;
            }
        }
    }
    printf("%d",score);
    return 0;
}
