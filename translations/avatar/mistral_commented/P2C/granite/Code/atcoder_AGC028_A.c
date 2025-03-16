
###
# Code
###

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define input variables N and M as integers
    int N, M;
    scanf("%d %d", &N, &M);

    // Comments: Get the dimensions N and M of the matrices S and T from user input

    // Initialize variables S and T as strings
    char S[N], T[M];
    scanf("%s", S);
    scanf("%s", T);

    // Initialize a list Number_i containing numbers from 0 to N-1
    int Number_i[N];
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }

    // Initialize an empty list Number_iMN to store the results of the division i*M/N
    int Number_iMN[N];
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (int)(i * M / N);
    }

    // Initialize a list Number_j containing numbers from 0 to M-1
    int Number_j[M];
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    // Find the common elements between Number_iMN and Number_j using set intersection
    int Kaburi_j[N];
    int Kaburi_Size = 0;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (Number_iMN[i] == Number_j[j]) {
                Kaburi_j[Kaburi_Size] = Number_j[j];
                Kaburi_Size++;
                break;
            }
        }
    }

    // Initialize an empty list Kaburi_i to store the integer representations of the common elements
    int Kaburi_i[N];
    for (int i = 0; i < N; i++) {
        Kaburi_i[i] = (int)(Kaburi_j[i] * N / M);
    }

    // Initialize a counter variable to keep track of the current index in Kaburi_i
    int counter = 0;

    // Initialize a flag variable to indicate whether there is a mismatch between S and T
    int Flag = 0;

    // Iterate through each index in Kaburi_i until the end of the list
    while (counter <= Kaburi_Size - 1) {
        // Check if the corresponding elements in S and T match
        if (S[Kaburi_i[counter]]!= T[Kaburi_j[counter]]) {
            // Set the flag variable to 1 if there is a mismatch
            Flag = 1;
            // Break out of the loop
            break;
        }
        // Increment the counter variable
        counter++;
    }

    // Define a function gcd(a, b) to calculate the greatest common divisor of two integers
    int gcd(int a, int b) {
        // While b is not equal to 0, keep updating a and b using the modulo operator
        while (b > 0) {
            a = b;
            b = a % b;
        }
        // Return the final value of a as the greatest common divisor
        return a;
    }

    // Check if there is a mismatch between S and T
    if (Flag == 1) {
        // Print -1 if there is a mismatch
        printf("-1\n");
    } else {
        // Calculate and print the product of N and M divided by their greatest common divisor
        printf("%d\n", (int)(N * M / gcd(N, M)));
    }

    return 0;
}
