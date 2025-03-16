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
    // Read the values of N and M from input
    int N, M;
    scanf("%d %d", &N, &M);

    // Read the strings S and T from input
    char S[N + 1], T[M + 1];
    scanf("%s", S);
    scanf("%s", T);

    // Create an array to store the scaled indices
    double Number_iMN[N];
    
    // Calculate the scaled indices based on the ratio of M to N
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = i * (double)M / N;
    }

    // Initialize an array to store the common indices
    int Kaburi_i[N];
    int Kaburi_j[M];
    int Kaburi_Size = 0;

    // Find the common indices between the scaled Number_iMN and Number_j
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if ((int)Number_iMN[i] == j) {
                Kaburi_i[Kaburi_Size] = (int)(j * N / M);
                Kaburi_j[Kaburi_Size] = j;
                Kaburi_Size++;
            }
        }
    }

    // Initialize a flag for mismatch detection
    int Flag = 0;

    // Check if the characters at the calculated indices in S and T match
    for (int counter = 0; counter < Kaburi_Size; counter++) {
        if (S[Kaburi_i[counter]] != T[Kaburi_j[counter]]) {
            Flag = 1;  // Set flag if a mismatch is found
            break;  // Exit the loop on mismatch
        }
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
