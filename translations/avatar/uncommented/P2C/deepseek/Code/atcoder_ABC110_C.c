#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* count_frequencies(const char* str) {
    int* freq = (int*)calloc(26, sizeof(int));
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }
    return freq;
}

const char* run(const char* s, const char* t) {
    int* ss = count_frequencies(s);
    int* tt = count_frequencies(t);

    qsort(ss, 26, sizeof(int), compare);
    qsort(tt, 26, sizeof(int), compare);

    for (int i = 0; i < 26; i++) {
        if (ss[i] != tt[i]) {
            free(ss);
            free(tt);
            return "No";
        }
    }
    free(ss);
    free(tt);
    return "Yes";
}

void main() {
    char s[1000], t[1000];
    scanf("%s", s);
    scanf("%s", t);
    printf("%s\n", run(s, t));
}

