#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, M;
    char S[100001], T[100001];
    
    // Read the values of N and M from input
    scanf("%d %d", &N, &M);
    
    // Read the strings S and T from input
    scanf("%s", S);
    scanf("%s", T);
    
    // Convert strings S and T into arrays for easier indexing
    char list_S[N + 1], list_T[M + 1];
    strcpy(list_S, S);
    strcpy(list_T, T);
    
    // Create an array of indices from 0 to N-1
    int Number_i[N];
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }
    
    // Initialize an empty array to store calculated indices
    double Number_iMN[N];
    
    // Calculate the scaled indices based on the ratio of M to N
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = i * (double)M / N;
    }
    
    // Create an array of indices from 0 to M-1
    int Number_j[M];
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }
    
    // Find the common indices between the scaled Number_iMN and Number_j
    int Kaburi_j[N];
    int Kaburi_j_size = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Number_iMN[i] == j) {
                Kaburi_j[Kaburi_j_size++] = j;
                break;
            }
        }
    }
    
    // Initialize an empty array to store the corresponding indices in the original range
    int Kaburi_i[Kaburi_j_size];
    
    // Calculate the corresponding indices in the original range based on Kaburi_j
    for (int j = 0; j < Kaburi_j_size; j++) {
        Kaburi_i[j] = (int)(Kaburi_j[j] * N / M);
    }
    
    // Initialize a counter for iteration and a flag for mismatch detection
    int counter = 0;
    int Flag = 0;
    
    // Check if the characters at the calculated indices in S and T match
    while (counter < Kaburi_j_size) {
        if (list_S[Kaburi_i[counter]] != list_T[Kaburi_j[counter]]) {
            Flag = 1;  // Set flag if a mismatch is found
            break;  // Exit the loop on mismatch
        }
        counter++;  // Move to the next index
    }
    
    // Output the result based on the flag indicating if a mismatch was found
    if (Flag == 1) {
        printf("-1\n");  // Print -1 if there was a mismatch
    } else {
        // Print the least common multiple (LCM) of N and M
        printf("%d\n", (N * M) / gcd(N, M));
    }
    
    return 0;
}
