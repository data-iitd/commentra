#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000], t[1000];
    int ura = 0, opa = 0;
    scanf("%s", s);
    scanf("%s", t);
    int tmap[256] = {0};
    for (int i = 0; i < strlen(t); i++) {
        char ch = t[i];
        tmap[(unsigned char)ch]++;
    }
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        int num = tmap[(unsigned char)ch];
        if (num == 0) continue;
        int inum = num;
        if (inum == 1) tmap[(unsigned char)ch] = 0;
        else tmap[(unsigned char)ch] = inum - 1;
        s[i] = 'Я';
        ura++;
    }
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = tolower(ch) == ch ? toupper(ch) : tolower(ch);
        int num = tmap[(unsigned char)rch];
        if (num == 0) continue;
        int inum = num;
        if (inum == 1) tmap[(unsigned char)rch] = 0;
        else tmap[(unsigned char)rch] = inum - 1;
        opa++;
    }
    printf("%d %d\n", ura, opa);
    return 0;
}

