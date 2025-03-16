
#include <stdio.h>
#include <stdlib.h>

// Function to find the binary index of a number in the list
int bis(int x, int y) {
    // Base case: if y is one more than x, return y
    if (y == x + 1) {
        return y;
    }

    // Recursively finding the binary index of x and y using the is_possible function
    if (is_possible((x + y) / 2)) {
        return bis(x, (x + y) / 2);
    }

    // If is_possible returns False for (x + y) / 2 and y, return the binary index of y
    else {
        return bis((x + y) / 2, y);
    }
}

// Function to check if it's possible to add a certain number of elements to the list while maintaining the condition that the previous element is smaller than the current one
int is_possible(int K) {
    // Initializing an empty list to store the indices and values of the elements in the list
    int dp[K][2];
    dp[0][0] = A[0];
    dp[0][1] = 0;

    // Iterating through the list starting from the second element
    for (int i = 1; i < N; i++) {
        // If the current element is smaller than the last element in the dp list,
        // we need to cut the list at the previous index and add the current element
        if (A[i] <= dp[K - 1][0]) {
            int j = 0;
            while (j < K && dp[j][0] < A[i]) {
                j++;
            }
            for (int k = j - 1; k >= 0; k--) {
                dp[k + 1][0] = dp[k][0];
                dp[k + 1][1] = dp[k][1];
            }
            dp[0][0] = A[i];
            dp[0][1] = 0;
        }

        // Adding the current element to the dp list
        dp[0][1]++;

        // Initializing a flag to check if we need to add an element to the dp list
        int is_added = 0;

        // Iterating through the dp list from the end to the beginning
        for (int j = K - 1; j >= 0; j--) {
            // If the previous element has a smaller value and enough space to add the current element,
            // we need to cut the list at the previous index and add the current element
            if (dp[j][1] < K - 1) {
                int k = 0;
                while (k < K && dp[k][0] < dp[j][0] - 1) {
                    k++;
                }
                for (int l = k - 1; l >= 0; l--) {
                    dp[l + 1][0] = dp[l][0];
                    dp[l + 1][1] = dp[l][1];
                }
                dp[0][0] = dp[j][0] - 1;
                dp[0][1] = dp[j][1] + 1;
                is_added = 1;
                break;
            }
        }

        // If we didn't add an element to the dp list, the current number can't be added
        if (!is_added) {
            return 0;
        }
    }

    // If we made it to the end of the loop, it means we were able to add all the numbers in the list
    return 1;
}

// Main function to take input from user and print the result of the binary index function
int main() {
    // Taking input from user and converting it into a list of integers
    char input[1000];
    fgets(input, 1000, stdin);
    int A[N];
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i]!='') {
            A[j] = A[j] * 10 + (input[i] - '0');
        }
        else {
            j++;
        }
    }

    // Adding the first element of the list to the beginning of the list
    // to make the first index 0 based instead of 1 based
    A[0] = A[j];
    j++;
    for (int i = 0; i < j; i++) {
        A[i] = A[j];
        j++;
    }

    // Printing the result of the binary index function
    printf("%d\n", bis(0, N));

    return 0;
}

END-OF-CODE