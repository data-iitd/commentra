#include <stdio.h>
#include <string.h>

char* main() {
    static char result[100]; // Assuming the maximum length of S is 100
    int K;
    char S[100];

    scanf("%d", &K);
    scanf("%s", S);

    if (strlen(S) <= K) {
        strcpy(result, S);
    } else {
        strncpy(result, S, K);
        result[K] = '\0'; // Null-terminate the string
        strcat(result, "...");
    }

    return result;
}

int main() {
    printf("%s\n", main());
    return 0;
}

// <END-OF-CODE>
