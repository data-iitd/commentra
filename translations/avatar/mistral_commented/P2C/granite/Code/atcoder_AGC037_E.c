
###
# Code
###

#include <stdio.h>
#include <string.h>

int main() {
    // Define input variables
    int N, K;
    char S[100001];

    // Read input variables from standard input
    scanf("%d %d", &N, &K);
    scanf("%s", S);

    // Initialize a flag variable
    int aaaa = 0;

    // Check if K is greater than or equal to 15
    if (K >= 15) {
        // If so, set the flag variable to 1
        aaaa = 1;
    }

    // Else, check if 2^K is greater than or equal to N
    else if ((1 << K) >= N) {
        // If so, set the flag variable to 1
        aaaa = 1;
    }

    // If the flag variable is 1, print the result and exit the function
    if (aaaa) {
        printf("%d\n", N * (int)S[0]);
        return 0;
    }

    // Define a function to get the last dictionary of the string S
    void get_last_dict(char *s_str) {
        // Create a new string U by concatenating S with its reverse
        char U[200001];
        strcpy(U, s_str);
        strcat(U, s_str);

        // Find the minimum character in S
        char c = *min(s_str, s_str + N);

        // Find the index of the first occurrence of the minimum character in U
        int p = 0;
        while (U[p]!= c) {
            p++;
        }

        // Initialize a variable minindex to store the index of the first occurrence of the minimum character in S
        int minindex = p;

        // Move the pointer p to the next character in U
        p++;

        // Check if the substring starting from the current pointer and of length N is a normal dictionary
        while (p <= N) {
            // If the character at the current pointer in U is the same as the minimum character,
            // and if the substring starting from the current pointer and of length N is a normal dictionary,
            // update the index minindex
            if (U[p] == c && check_normal_dict(U, minindex, p)) {
                minindex = p;
            }
            // Move the pointer p to the next character in U
            p++;
        }

        // Copy the substring starting from minindex and of length N to the original string S
        strncpy(S, U + minindex, N);
    }

    // Define a function to check if a substring is a normal dictionary
    int check_normal_dict(char *u, int pointer1, int pointer2) {
        // Iterate through each character in the substring of length N
        for (int i = 0; i < N; i++) {
            // If the character at pointer1+i in U is greater than the character at pointer2+i,
            // return 1 (indicating that the substring is a normal dictionary)
            if (u[pointer1 + i] > u[pointer2 + i]) {
                return 1;
            }
            // Else, if the character at pointer1+i is less than the character at pointer2+i,
            // return 0 (indicating that the substring is not a normal dictionary)
            else if (u[pointer1 + i] < u[pointer2 + i]) {
                return 0;
            }
        }
        // If none of the above conditions are met, return 0
        return 0;
    }

    // Get the last dictionary of the string S
    get_last_dict(S);

    // If K is equal to 1, print the string S
    if (K == 1) {
        printf("%s\n", S);
    }
    // Else, check if the number of occurrences of the first character in S is greater than or equal to N/2^(K-1)
    else {
        int count = 0;
        for (int i = 0; i < N; i++) {
            // If the current character is the same as the first character, increment the count
            if (S[i] == S[0]) {
                count++;
            }
            // Else, break the loop
            else {
                break;
            }
        }
        // If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
        if (count * (1 << (K - 1)) >= N) {
            printf("%c", S[0]);
            for (int i = 1; i < N; i++) {
                printf("%c", S[0]);
            }
            printf("\n");
        }
        // Else, construct the string S by concatenating N-1 instances of the first character with the original string S
        else {
            for (int i = 0; i < N - 1; i++) {
                S[i] = S[0];
            }
            S[N - 1] = '\0';
            // Print the first N characters of the constructed string S
            printf("%s\n", S);
        }
    }

    return 0;
}

