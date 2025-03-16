#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[100000];
    scanf("%s", s);
    int len = strlen(s);
    char *token = strtok(s, " ");
    int count[100000] = {0};
    while (token != NULL) {
        count[atoi(token)]++;
        token = strtok(NULL, " ");
    }
    int max_count = 0;
    char *max_value = NULL;
    for (int i = 0; i < len; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_value = s[i];
        }
    }
    printf("%s\n", max_value);
    return 0;
}
