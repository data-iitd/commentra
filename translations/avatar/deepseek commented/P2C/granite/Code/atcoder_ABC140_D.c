
#include <stdio.h>  // Include the standard input/output library

int main() {  // Define the main function
    int N, K;  // Declare variables for the number of elements and the parameter K
    char S[100001];  // Declare a character array to store the string S

    scanf("%d %d", &N, &K);  // Read the number of elements N and the parameter K from the input
    scanf("%s", S);  // Read the string S from the input

    int seg_cnt = 0;  // Initialize a counter for the number of segments
    for (int i = 0; i < N - 1; i++) {  // Loop through the string to count segments
        if (S[i]!= S[i + 1]) {  // Check if the current character is different from the next
            seg_cnt++;  // Increment the segment counter if a change is found
        }
    }

    int cur_happy = N - 1 - seg_cnt;  // Calculate the initial happiness based on the number of segments

    if (2 * K >= seg_cnt) {  // Check if the number of operations allows for maximum happiness
        int ans = N - 1;  // If yes, set the answer to the maximum possible happiness
    } else {
        int ans = cur_happy + 2 * K;  // Otherwise, adjust the happiness based on the number of operations
    }

    printf("%d\n", ans);  // Print the final happiness value

    return 0;  // Return 0 to indicate successful execution
}

