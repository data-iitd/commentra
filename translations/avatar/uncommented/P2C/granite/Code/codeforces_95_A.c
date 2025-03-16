
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int pya = atoi(argv[1]);
    char *arre[pya];
    for (int i = 0; i < pya; i++)
    {
        arre[i] = malloc(strlen(argv[i + 2]) + 1);
        strcpy(arre[i], argv[i + 2]);
    }
    string oString = get_string("Text: ");
    string lowString = oString;
    transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);
    char letter1 = argv[pya + 2][0];
    char letter2 = 'a';
    if (letter1 == 'a')
    {
        letter2 = 'b';
    }
    int valid[oString.length()];
    for (int i = 0; i < oString.length(); i++)
    {
        valid[i] = 0;
    }
    set<int> setcito;
    for (int i = 0; i < pya; i++)
    {
        int wat = 0;
        while (true)
        {
            int index = lowString.find(arre[i], wat);
            if (index < 0)
            {
                break;
            }
            for (int j = index; j < index + strlen(arre[i]); j++)
            {
                setcito.insert(j);
            }
            wat = index + 1;
        }
    }
    for (auto it = setcito.begin(); it!= setcito.end(); it++)
    {
        int index = *it;
        char letter = letter1;
        if (lowString[index]!= letter1)
        {
            letter = letter2;
        }
        if (islower(oString[index]))
        {
            oString[index] = letter;
        }
        else
        {
            oString[index] = toupper(letter);
        }
    }
    printf("%s\n", oString.c_str());
    return 0;
}
