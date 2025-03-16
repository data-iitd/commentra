#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, M;
    // Read the dimensions N and M of the matrices S and T from user input
    scanf("%d %d", &N, &M);

    // Initialize variables S and T as strings
    char S[1000], T[1000];
    // Read the string S from user input
    scanf("%s", S);
    // Read the string T from user input
    scanf("%s", T);

    // Convert strings S and T into lists
    // This is not necessary in C, as we can directly work with character arrays

    // Initialize a list Number_i containing numbers from 0 to N-1
    int Number_i[N];
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }

    // Initialize an empty list Number_iMN to store the results of the division i*M/N
    int Number_iMN[N];
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (Number_i[i] * M) / N;
    }

    // Initialize a list Number_j containing numbers from 0 to M-1
    int Number_j[M];
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    // Find the common elements between Number_iMN and Number_j using set intersection
    // This is not necessary in C, as we can directly work with arrays

    // Initialize an empty list Kaburi_i to store the integer representations of the common elements
    int Kaburi_i[N];
    int Kaburi_Size = 0;

    // Iterate through each number i in the list Number_i
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Number_iMN[i] == Number_j[j]) {
                Kaburi_i[Kaburi_Size++] = i;
                break;
            }
        }
    }

    // Initialize a counter variable to keep track of the current index in Kaburi_i
    int counter = 0;

    // Initialize a flag variable to indicate whether there is a mismatch between S and T
    int Flag = 0;

    // Determine the size of Kaburi_i
    // Kaburi_Size is already calculated above

    // Iterate through each index in Kaburi_i until the end of the list
    while (counter < Kaburi_Size) {
        // Check if the corresponding elements in S and T match
        if (S[Kaburi_i[counter]] != T[counter]) {
            // Set the flag variable to 1 if there is a mismatch
            Flag = 1;
            // Break out of the loop
            break;
        }
        // Increment the counter variable
        counter++;
    }

    // Check if there is a mismatch between S and T
    if (Flag == 1) {
        // Print -1 if there is a mismatch
        printf("-1\n");
    } else {
        // Calculate and print the product of N and M divided by their greatest common divisor
        printf("%d\n", (N * M) / gcd(N, M));
    }

    return 0;
}
