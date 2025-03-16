_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000000];
    char t[100000];
    scanf("%s", s);
    scanf("%s", t);
    int ura = 0, opa = 0;
    int length = strlen(s);
    char ch, rch;
    int num, inum;
    int tmap[26];
    for (int i = 0; i < 26; i++)
        tmap[i] = 0;
    for (int i = 0; i < strlen(t); i++)
        tmap[t[i] - 'a']++;
    for (int i = 0; i < length; i++)
    {
        ch = s[i];
        num = tmap[ch - 'a'];
        if (num == 0)
            continue;
        inum = num;
        if (inum == 1)
            tmap[ch - 'a'] = 0;
        else
            tmap[ch - 'a']--;
        s[i] = 'Я';
        ura++;
    }
    for (int i = 0; i < length; i++)
    {
        ch = s[i];
        rch = ch - 32;
        if (rch < 'a' || rch > 'z')
            continue;
        num = tmap[rch - 'a'];
        if (num == 0)
            continue;
        inum = num;
        if (inum == 1)
            tmap[rch - 'a'] = 0;
        else
            tmap[rch - 'a']--;
        opa++;
    }
    printf("%d %d\n", ura, opa);
    return 0;
}
