#include <stdio.h>

int main() {
    int li[1000]; // Assuming a maximum size of 1000 for the list
    int ind = 0;

    for (int i = 1; i < 371; i++) {
        int temp[3]; // Temporary array to hold digits (max 3 digits)
        int p = i, q = i;
        int count = 0;

        // Count the number of digits in i
        while (p != 0) {
            p /= 10;
            count++;
        }

        // If i has 1 digit, append it to the list li
        if (count == 1) {
            li[ind++] = i;
        }

        // If i has 2 digits, extract the digits and reverse them, then append to li
        if (count == 2) {
            int j = 0;
            while (q != 0) {
                temp[j++] = q % 10;
                q /= 10;
            }
            for (int k = j - 1; k >= 0; k--) {
                li[ind++] = temp[k];
            }
        }

        // If i has 3 digits, extract the digits and reverse them, then append to li
        if (count == 3) {
            int j = 0;
            while (q != 0) {
                temp[j++] = q % 10;
                q /= 10;
            }
            for (int k = j - 1; k >= 0; k--) {
                li[ind++] = temp[k];
            }
        }
    }

    // Remove the last two elements from li
    ind -= 2;

    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Print the nth element of li based on the user's input
    printf("%d\n", li[n - 1]);

    return 0;
}
