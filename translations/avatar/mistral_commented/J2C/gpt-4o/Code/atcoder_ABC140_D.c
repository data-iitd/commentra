#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K); // Reading the first two integers N and K
    char S[N + 1]; // Creating a character array for the string S
    scanf("%s", S); // Reading the string S

    char c1[N + 1]; // Character array c1
    char c3[N + 1]; // Character array c3
    strcpy(c1, S); // Copying S to c1
    strcpy(c3, S); // Copying S to c3

    int count1 = 0; // Counter for 'R' after 'L'
    int flag1 = 0; // Flag for 'L' found

    // Processing c1
    for (int i = 0; i < N; i++) {
        if (flag1 && c1[i] == 'R') {
            flag1 = 0;
            count1++;
        }
        if (count1 == K) {
            break;
        }
        if (c1[i] == 'L') {
            flag1 = 1;
        }
    }

    int count3 = 0; // Counter for 'L' after 'R'
    int flag3 = 0; // Flag for 'R' found

    // Processing c3
    for (int i = 0; i < N; i++) {
        if (flag3 && c3[i] == 'L') {
            flag3 = 0;
            count3++;
        }
        if (count3 == K) {
            break;
        }
        if (c3[i] == 'R') {
            flag3 = 1;
        }
    }

    int count2 = 1; // Counter for consecutive characters in c1
    int sum1 = 0; // Sum for c1
    char bef1 = c1[0]; // Previous character in c1

    // Finding longest consecutive identical characters in c1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef1) {
            count2++;
        } else {
            sum1 += count2 - 1;
            count2 = 1;
            bef1 = c1[i];
        }
    }
    sum1 += count2 - 1; // Adding last count

    int count4 = 1; // Counter for consecutive characters in c3
    int sum3 = 0; // Sum for c3
    char bef3 = c3[0]; // Previous character in c3

    // Finding longest consecutive identical characters in c3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef3) {
            count4++;
        } else {
            sum3 += count4 - 1;
            count4 = 1;
            bef3 = c3[i];
        }
    }
    sum3 += count4 - 1; // Adding last count

    // Printing the maximum of sum1 and sum3
    printf("%d\n", (sum1 > sum3) ? sum1 : sum3);

    return 0;
}

// <END-OF-CODE>
