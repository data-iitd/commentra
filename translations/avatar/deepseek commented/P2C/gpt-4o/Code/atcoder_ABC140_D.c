#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007  // Define a constant for modulo operation

// Function to read the next integer from input
int gi() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read the next string from input
void gw(char *str) {
    scanf("%s", str);
}

int main() {
    int N = gi();  // Read the number of elements N from the input
    int K = gi();  // Read the parameter K from the input
    char S[100001];  // Assuming the maximum length of S is 100000
    gw(S);  // Read the string S from the input

    int seg_cnt = 0;  // Initialize a counter for the number of segments
    for (int i = 0; i < N - 1; i++) {  // Loop through the string to count segments
        if (S[i] != S[i + 1]) {  // Check if the current character is different from the next
            seg_cnt++;  // Increment the segment counter if a change is found
        }
    }

    int cur_happy = N - 1 - seg_cnt;  // Calculate the initial happiness based on the number of segments

    int ans;  // Variable to store the final answer
    if (2 * K >= seg_cnt) {  // Check if the number of operations allows for maximum happiness
        ans = N - 1;  // If yes, set the answer to the maximum possible happiness
    } else {
        ans = cur_happy + 2 * K;  // Otherwise, adjust the happiness based on the number of operations
    }

    printf("%d\n", ans);  // Print the final happiness value
    return 0;  // Return success
}

// <END-OF-CODE>
