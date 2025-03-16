#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Define input variables N and M as integers
    int N, M;
    scanf("%d %d", &N, &M);

    // Comments: Get the dimensions N and M of the matrices S and T from user input

    // Initialize variables S and T as strings
    char S[N + 1], T[M + 1];
    scanf("%s", S);
    scanf("%s", T);

    // Initialize an array Number_i containing numbers from 0 to N-1
    int Number_i[N];
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }

    // Initialize an array Number_iMN to store the results of the division i*M/N
    int Number_iMN[N];
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = (int)(i * M / N);
    }

    // Initialize an array Number_j containing numbers from 0 to M-1
    int Number_j[M];
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }

    // Find the common elements between Number_iMN and Number_j
    int Kaburi_j[M];
    int Kaburi_j_size = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Number_iMN[i] == Number_j[j]) {
                Kaburi_j[Kaburi_j_size++] = Number_j[j];
                break; // Avoid duplicates
            }
        }
    }

    // Initialize an array Kaburi_i to store the integer representations of the common elements
    int Kaburi_i[Kaburi_j_size];
    for (int j = 0; j < Kaburi_j_size; j++) {
        Kaburi_i[j] = (int)(Kaburi_j[j] * N / M);
    }

    // Initialize a counter variable to keep track of the current index in Kaburi_i
    int counter = 0;
    // Initialize a flag variable to indicate whether there is a mismatch between S and T
    int Flag = 0;

    // Determine the size of Kaburi_i
    int Kaburi_Size = Kaburi_j_size;

    // Iterate through each index in Kaburi_i until the end of the list
    while (counter < Kaburi_Size) {
        // Check if the corresponding elements in S and T match
        if (S[Kaburi_i[counter]] != T[Kaburi_j[counter]]) {
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
