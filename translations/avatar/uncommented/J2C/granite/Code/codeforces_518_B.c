
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100001];
    char t[100001];
    scanf("%s", s);
    scanf("%s", t);
    int ura = 0;
    int opa = 0;
    int tmap[256] = {0};
    for (int i = 0; i < strlen(t); i++) {
        tmap[t[i]]++;
    }
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        if (tmap[ch] == 0) {
            continue;
        }
        tmap[ch]--;
        s[i] = 'Я';
        ura++;
    }
    for (int i = 0; i < length; i++) {
        char ch = s[i];
        char rch = (ch >= 'a' && ch <= 'z')? ch - 32 : ch + 32;
        if (tmap[rch] == 0) {
            continue;
        }
        tmap[rch]--;
        opa++;
    }
    printf("%d %d\n", ura, opa);
    return 0;
}

