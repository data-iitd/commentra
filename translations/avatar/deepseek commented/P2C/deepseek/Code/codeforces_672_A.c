#include <stdio.h>
#include <stdlib.h>

int main() {
    int li[370];
    int ind = 0;
    // Initialize an array and a variable to keep track of the index

    for (int i = 1; i <= 370; i++) {
        int temp[10];
        int p = i, q = i;
        int count = 0;
        // Initialize an empty temporary array and set p and q to the current value of i
        // Initialize a counter to count the number of digits in i

        while (p != 0) {
            p /= 10;
            count++;
        }
        // Count the number of digits in i by repeatedly dividing p by 10

        if (count == 1) {
            li[ind++] = i;
        }
        // If i has 1 digit, append it to the array li

        if (count == 2) {
            int temp_index = 0;
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[temp_index++] = x;
            }
            for (int j = temp_index - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
        // If i has 2 digits, extract the digits and reverse them, then append to li

        if (count == 3) {
            int temp_index = 0;
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[temp_index++] = x;
            }
            for (int j = temp_index - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
        // If i has 3 digits, extract the digits and reverse them, then append to li
    }

    li[ind - 1] = 0;
    li[ind - 2] = 0;
    // Remove the last two elements from li

    int n;
    scanf("%d", &n);
    // Take an integer input from the user

    printf("%d\n", li[n - 1]);
    // Print the nth element of li based on the user's input

    return 0;
}
