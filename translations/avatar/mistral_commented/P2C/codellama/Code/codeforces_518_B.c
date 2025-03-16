#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    // We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
    char *freqs [26] = {NULL};
    char *freqt [26] = {NULL};

    // We read the two strings s and t from the user input
    char s [100], t [100];
    scanf ("%s %s", s, t);

    // We iterate through each character in the string s and update the frequency count in the freqs dictionary
    for (int i = 0; i < strlen (s); i++)
    {
        if (freqs [s [i] - 'a'] == NULL)
        {
            freqs [s [i] - 'a'] = (char *) malloc (sizeof (char));
            *freqs [s [i] - 'a'] = 1;
        }
        else
        {
            *freqs [s [i] - 'a'] += 1;
        }
    }

    // We iterate through each character in the string t and update the frequency count in the freqt dictionary
    for (int i = 0; i < strlen (t); i++)
    {
        if (freqt [t [i] - 'a'] == NULL)
        {
            freqt [t [i] - 'a'] = (char *) malloc (sizeof (char));
            *freqt [t [i] - 'a'] = 1;
        }
        else
        {
            *freqt [t [i] - 'a'] += 1;
        }
    }

    // We initialize two counters, yay and whoops, to zero
    int yay = 0, whoops = 0;

    // We iterate through each character in the freqs dictionary and check if its frequency is greater than zero and if it is present in the freqt dictionary with a frequency greater than zero. If both conditions are true, we increment the yay counter
    for (int i = 0; i < 26; i++)
    {
        if (freqs [i] != NULL && freqt [i] != NULL && *freqs [i] > 0 && *freqt [i] > 0)
        {
            yay += 1;
            *freqs [i] -= 1;
            *freqt [i] -= 1;
        }
    }

    // We iterate through each character in the freqs dictionary again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt dictionary with a frequency greater than zero or if its uppercase version is present in the freqt dictionary with a frequency greater than zero. If either condition is true, we increment the whoops counter
    for (int i = 0; i < 26; i++)
    {
        if (freqs [i] != NULL && *freqs [i] > 0)
        {
            if (freqt [i] != NULL && *freqt [i] > 0)
            {
                whoops += 1;
                *freqs [i] -= 1;
                *freqt [i] -= 1;
            }
            else if (freqt [i + 32] != NULL && *freqt [i + 32] > 0)
            {
                whoops += 1;
                *freqs [i] -= 1;
                *freqt [i + 32] -= 1;
            }
            else if (freqt [i - 32] != NULL && *freqt [i - 32] > 0)
            {
                whoops += 1;
                *freqs [i] -= 1;
                *freqt [i - 32] -= 1;
            }
        }
    }

    // Finally, we print the values of yay and whoops
    printf ("%d %d", yay, whoops);

    return 0;
}

