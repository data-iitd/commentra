#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

char* scanString() {
    char* str = (char*)malloc(MAX_LEN * sizeof(char));
    scanf("%s", str);
    return str;
}

char** scanStrings(int n) {
    char** strs = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strs[i] = scanString();
    }
    return strs;
}

void debug(char* a) {
    printf("%s\n", a);
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void restore(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    char** possible_matches = (char**)malloc((len_s - len_t + 1) * sizeof(char*));
    int match_count = 0;

    for (int i = 0; i <= len_s - len_t; i++) {
        int match = 1;
        char* temp_s = (char*)malloc((len_s + 1) * sizeof(char));
        strcpy(temp_s, s);

        for (int j = 0; j < len_t; j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                match = 0;
                break;
            } else {
                temp_s[i + j] = t[j];
            }
        }

        if (match) {
            for (int k = 0; k < len_s; k++) {
                if (temp_s[k] == '?') {
                    temp_s[k] = 'a';
                }
            }
            possible_matches[match_count] = (char*)malloc((len_s + 1) * sizeof(char));
            strcpy(possible_matches[match_count], temp_s);
            match_count++;
        }
        free(temp_s);
    }

    if (match_count == 0) {
        printf("UNRESTORABLE\n");
    } else {
        // Sort the possible matches
        for (int i = 0; i < match_count - 1; i++) {
            for (int j = i + 1; j < match_count; j++) {
                if (strcmp(possible_matches[i], possible_matches[j]) > 0) {
                    char* temp = possible_matches[i];
                    possible_matches[i] = possible_matches[j];
                    possible_matches[j] = temp;
                }
            }
        }
        printf("%s\n", possible_matches[0]);
        for (int i = 0; i < match_count; i++) {
            free(possible_matches[i]);
        }
        free(possible_matches);
    }
}

int main() {
    char* s = scanString();
    char* t = scanString();

    restore(s, t);

    free(s);
    free(t);

    return 0;
}
