
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string txt = get_string("Text: ");
    int cu = 0;
    int cl = 0;
    for (int i = 0; i < strlen(txt); i++)
    {
        if (islower(txt[i]))
        {
            cl++;
        }
        else
        {
            cu++;
        }
    }
    string out;
    if (cu > cl)
    {
        out = txt;
        for (int i = 0; i < strlen(txt); i++)
        {
            out[i] = toupper(txt[i]);
        }
    }
    else
    {
        out = txt;
        for (int i = 0; i < strlen(txt); i++)
        {
            out[i] = tolower(txt[i]);
        }
    }
    printf("%s\n", out);
    return 0;
}
