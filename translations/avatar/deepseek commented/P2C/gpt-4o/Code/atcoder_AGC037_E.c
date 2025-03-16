#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100000

int check_normal_dict(char *u, int pointer1, int pointer2, int N) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return 1; // pointer1 is greater
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return 0; // pointer2 is greater
        }
    }
    return 0; // equal
}

char* get_last_dict(char *s_str, int N) {
    char *U = (char *)malloc(2 * N + 1);
    strcpy(U, s_str);
    strcat(U, strrev(strdup(s_str))); // Concatenate the string with its reverse
    char c = s_str[0];
    int p = 0;
    while (U[p] != c) p++; // Find the index of the minimum character in the concatenated string
    int minindex = p;
    p++;
    while (p <= 2 * N) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p, N)) {
                minindex = p;
            }
        }
        p++;
    }
    char *result = (char *)malloc(N + 1);
    strncpy(result, U + minindex, N);
    result[N] = '\0'; // Null-terminate the string
    free(U);
    return result;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[MAX_LEN];
    scanf("%s", S);
    
    int aaaa = 0; // Initialize a flag to check special conditions
    if (K >= 15) {
        aaaa = 1; // If K is 15 or more, set the flag to True
    } else if ((1 << K) >= N) {
        aaaa = 1; // If 2 to the power of K is greater than or equal to N, set the flag to True
    }
    
    if (aaaa) {
        char min_char = S[0];
        for (int i = 1; i < N; i++) {
            if (S[i] < min_char) {
                min_char = S[i];
            }
        }
        for (int i = 0; i < N; i++) {
            putchar(min_char);
        }
        putchar('\n');
        return 0; // Exit
    }
    
    char *transformed_S = get_last_dict(S, N);
    
    if (K == 1) {
        printf("%s\n", transformed_S); // If K is 1, print the transformed S
    } else {
        int count = 0;
        while (transformed_S[count] == transformed_S[0]) {
            count++;
        }
        
        if (count * (1 << (K - 1)) >= N) {
            for (int i = 0; i < N; i++) {
                putchar(transformed_S[0]);
            }
            putchar('\n');
        } else {
            int new_length = count * ((1 << (K - 1)) - 1) + N;
            char *result = (char *)malloc(new_length + 1);
            for (int i = 0; i < count * ((1 << (K - 1)) - 1); i++) {
                result[i] = transformed_S[0];
            }
            strcpy(result + count * ((1 << (K - 1)) - 1), transformed_S);
            result[new_length] = '\0'; // Null-terminate the string
            printf("%.*s\n", N, result); // Print the first N characters of the new string
            free(result);
        }
    }
    
    free(transformed_S);
    return 0;
}

// <END-OF-CODE>
