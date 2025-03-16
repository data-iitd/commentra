#include <stdio.h>
#include <string.h>

// Function to read a string from standard input
char* readString() {
    char buffer[100];
    if (scanf("%s", buffer) != 1) {
        perror("Failed to read string");
        exit(EXIT_FAILURE);
    }
    char* result = (char*)malloc(strlen(buffer) + 1);
    if (result == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(result, buffer);
    return result;
}

// Function to calculate the number of characters in T that do not match with S
int calculateMismatches(const char* S, const char* T) {
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
    return lenT - max;
}

int main() {
    char* S = readString();
    char* T = readString();
    int mismatches = calculateMismatches(S, T);
    printf("%d\n", mismatches);
    free(S);
    free(T);
    return 0;
}

