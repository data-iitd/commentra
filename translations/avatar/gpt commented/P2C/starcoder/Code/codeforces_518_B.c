#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000], t[100000];
    scanf("%s", s);
    scanf("%s", t);

    int freqs[26] = {0};
    int freqt[26] = {0};

    int yay = 0, whoops = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        freqs[s[i] - 'a']++;
    }

    for (int i = 0; i < strlen(t); i++)
    {
        freqt[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        while (freqs[i] > 0 && freqt[i] > 0)
        {
            yay++;
            freqs[i]--;
            freqt[i]--;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        while (freqs[i] > 0)
        {
            if (i >= 0 && i <= 25)
            {
                if (freqt[i] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i]--;
                }
            }
            else if (i >= 26 && i <= 51)
            {
                if (freqt[i - 26] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 26]--;
                }
            }
            else if (i >= 52 && i <= 77)
            {
                if (freqt[i - 52] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 52]--;
                }
            }
            else if (i >= 78 && i <= 103)
            {
                if (freqt[i - 78] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 78]--;
                }
            }
            else if (i >= 104 && i <= 129)
            {
                if (freqt[i - 104] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 104]--;
                }
            }
            else if (i >= 130 && i <= 155)
            {
                if (freqt[i - 130] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 130]--;
                }
            }
            else if (i >= 156 && i <= 181)
            {
                if (freqt[i - 156] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 156]--;
                }
            }
            else if (i >= 182 && i <= 207)
            {
                if (freqt[i - 182] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 182]--;
                }
            }
            else if (i >= 208 && i <= 233)
            {
                if (freqt[i - 208] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 208]--;
                }
            }
            else if (i >= 234 && i <= 259)
            {
                if (freqt[i - 234] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 234]--;
                }
            }
            else if (i >= 260 && i <= 285)
            {
                if (freqt[i - 260] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 260]--;
                }
            }
            else if (i >= 286 && i <= 311)
            {
                if (freqt[i - 286] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 286]--;
                }
            }
            else if (i >= 312 && i <= 337)
            {
                if (freqt[i - 312] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 312]--;
                }
            }
            else if (i >= 338 && i <= 363)
            {
                if (freqt[i - 338] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 338]--;
                }
            }
            else if (i >= 364 && i <= 389)
            {
                if (freqt[i - 364] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 364]--;
                }
            }
            else if (i >= 390 && i <= 415)
            {
                if (freqt[i - 390] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 390]--;
                }
            }
            else if (i >= 416 && i <= 441)
            {
                if (freqt[i - 416] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 416]--;
                }
            }
            else if (i >= 442 && i <= 467)
            {
                if (freqt[i - 442] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 442]--;
                }
            }
            else if (i >= 468 && i <= 493)
            {
                if (freqt[i - 468] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 468]--;
                }
            }
            else if (i >= 494 && i <= 519)
            {
                if (freqt[i - 494] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 494]--;
                }
            }
            else if (i >= 520 && i <= 545)
            {
                if (freqt[i - 520] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 520]--;
                }
            }
            else if (i >= 546 && i <= 571)
            {
                if (freqt[i - 546] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 546]--;
                }
            }
            else if (i >= 572 && i <= 597)
            {
                if (freqt[i - 572] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 572]--;
                }
            }
            else if (i >= 598 && i <= 623)
            {
                if (freqt[i - 598] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 598]--;
                }
            }
            else if (i >= 624 && i <= 649)
            {
                if (freqt[i - 624] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 624]--;
                }
            }
            else if (i >= 650 && i <= 675)
            {
                if (freqt[i - 650] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 650]--;
                }
            }
            else if (i >= 676 && i <= 701)
            {
                if (freqt[i - 676] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 676]--;
                }
            }
            else if (i >= 702 && i <= 727)
            {
                if (freqt[i - 702] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 702]--;
                }
            }
            else if (i >= 728 && i <= 753)
            {
                if (freqt[i - 728] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 728]--;
                }
            }
            else if (i >= 754 && i <= 779)
            {
                if (freqt[i - 754] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 754]--;
                }
            }
            else if (i >= 780 && i <= 805)
            {
                if (freqt[i - 780] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 780]--;
                }
            }
            else if (i >= 806 && i <= 831)
            {
                if (freqt[i - 806] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 806]--;
                }
            }
            else if (i >= 832 && i <= 857)
            {
                if (freqt[i - 832] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 832]--;
                }
            }
            else if (i >= 858 && i <= 883)
            {
                if (freqt[i - 858] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 858]--;
                }
            }
            else if (i >= 884 && i <= 909)
            {
                if (freqt[i - 884] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 884]--;
                }
            }
            else if (i >= 910 && i <= 935)
            {
                if (freqt[i - 910] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 910]--;
                }
            }
            else if (i >= 936 && i <= 961)
            {
                if (freqt[i - 936] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 936]--;
                }
            }
            else if (i >= 962 && i <= 987)
            {
                if (freqt[i - 962] > 0)
                {
                    whoops++;
                    freqs[i]--;
                    freqt[i - 962]--;
                }
            }