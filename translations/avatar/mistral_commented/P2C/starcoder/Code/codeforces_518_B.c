#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char s [1000], t [1000];
    int freqs [26], freqt [26], yay, whoops;
    scanf ("%s %s", s, t);
    for (int i = 0; i < strlen (s); i++)
    {
        freqs [s [i] - 'a']++;
    }
    for (int i = 0; i < strlen (t); i++)
    {
        freqt [t [i] - 'a']++;
    }
    yay = whoops = 0;
    for (int i = 0; i < 26; i++)
    {
        while (freqs [i] > 0 && freqt [i] > 0)
        {
            yay++;
            freqs [i]--;
            freqt [i]--;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        while (freqs [i] > 0)
        {
            if (i >= 97 && i <= 122 && freqt [i - 32] > 0)
            {
                whoops++;
                freqs [i]--;
                freqt [i - 32]--;
            }
            else if (i >= 65 && i <= 90 && freqt [i + 32] > 0)
            {
                whoops++;
                freqs [i]--;
                freqt [i + 32]--;
            }
            else
            {
                break;
            }
        }
    }
    printf ("%d %d", yay, whoops);
    return 0;
}

