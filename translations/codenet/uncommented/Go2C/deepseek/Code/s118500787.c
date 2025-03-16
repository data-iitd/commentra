#include <stdio.h>
#include <string.h>

char* readString() {
    char buffer[100001];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char* newline = strchr(buffer, '\n');
        if (newline) {
            *newline = '\0';
        }
        char* str = (char*)malloc(strlen(buffer) + 1);
        strcpy(str, buffer);
        return str;
    }
    return NULL;
}

int main() {
    char* S = readString();
    char* T = readString();
    int max = 0;
    int lenS = strlen(S);
    int lenT = strlen(T);

    for (int i = 0; i <= lenS - lenT; i++) {
        int c = 0;
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] == T[j]) {
                c++;
            }
        }
        if (max < c) {
            max = c;
        }
    }
    printf("%d\n", lenT - max);

    free(S);
    free(T);
    return 0;
}
