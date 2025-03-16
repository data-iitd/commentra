#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char S[100], T[100];
    fgets(S, sizeof(S), stdin);
    fgets(T, sizeof(T), stdin);

    // Remove newline characters from the input strings
    S[strcspn(S, "\n")] = 0;
    T[strcspn(T, "\n")] = 0;

    char A[] = "abcdefghijklmnopqrstuvwxyz";
    bool res = true;

    for (int i = 0; i < 26; i++) {
        char s = A[i];
        char t = T[strcspn(S, (char[]){s, '\0'})]; // Get the corresponding character in T

        if (strchr(S, s) == NULL) continue; // If s is not in S, continue

        int idx = 0;
        while (idx < strlen(S)) {
            char *s_pos = strchr(S + idx, s);
            char *t_pos = strchr(T + idx, t);

            if (s_pos != NULL) {
                if (t_pos == NULL || (s_pos - S) != (t_pos - T)) {
                    res = false;
                    break;
                } else {
                    idx = s_pos - S + 1; // Move to the next character in S
                }
            } else if (t_pos != NULL) {
                res = false;
                break;
            } else {
                break;
            }
        }

        if (!res) break;
    }

    if (res) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
