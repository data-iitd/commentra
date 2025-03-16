

#include <stdio.h>
#include <stdlib.h>

int main() {
    int li[370];
    int ind = 0;
    // Initialize an empty array li and a variable ind to keep track of the index

    for (int i = 1; i < 371; i++) {
        int temp[3];
        int p = i, q = i;
        int count = 0;
        // Initialize an empty temporary array temp and set p and q to the current value of i
        // Initialize a counter count to count the number of digits in i

        while (p!= 0) {
            p /= 10;
            count++;
        }
        // Count the number of digits in i by repeatedly dividing p by 10

        if (count == 1) {
            li[ind] = i;
            ind++;
        }
        // If i has 1 digit, append it to the array li

        if (count == 2) {
            for (int j = 0; j < 3; j++) {
                temp[j] = q % 10;
                q /= 10;
            }
            for (int j = 0; j < 3; j++) {
                li[ind] = temp[2 - j];
                ind++;
            }
        }
        // If i has 2 digits, extract the digits and reverse them, then append to li

        if (count == 3) {
            for (int j = 0; j < 3; j++) {
                temp[j] = q % 10;
                q /= 10;
            }
            for (int j = 0; j < 3; j++) {
                li[ind] = temp[2 - j];
                ind++;
            }
        }
        // If i has 3 digits, extract the digits and reverse them, then append to li
    }

    li[ind - 2] = 0;
    li[ind - 1] = 0;
    // Remove the last two elements from li

    int n;
    scanf("%d", &n);
    // Take an integer input n from the user

    printf("%d", li[n - 1]);
    // Print the nth element of li based on the user's input

    return 0;
}
// Translate the above C code to Java and end with comment "