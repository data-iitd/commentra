#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100], t[100];
    scanf("%s", s);
    t[0] = s[0];
    char size_str[10];
    sprintf(size_str, "%lu", strlen(s) - 2);
    strcat(t, size_str);
    t[strlen(t)] = s[strlen(s) - 1];
    t[strlen(t) + 1] = '\0';
    printf("%s\n", t);
    return 0;
}

