#include <stdio.h>
#include <stdbool.h>

int main() {
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);  // Read the dimensions of the grid and the number of movements
    int s_r, s_c;
    scanf("%d %d", &s_r, &s_c);  // Read the starting position of the robot
    char S[N + 1], T[N + 1];  // Arrays to hold the movement strings
    scanf("%s", S);  // Read the string of movements for S
    scanf("%s", T);  // Read the string of movements for T

    bool Judge = false;  // Initialize a flag to check if the robot is out of bounds
    int S_L = 0, S_R = 0, S_U = 0, S_D = 0;  // Initialize counters for movements in each direction for S
    int T_L = 0, T_R = 0, T_U = 0, T_D = 0;  // Initialize counters for movements in each direction for T

    // Iterate through each movement in S
    for (int x = 0; x < N; x++) {
        if (S[x] == 'L') {
            S_L++;
            if (S_L - T_R - s_c == 0) {  // Check if S is about to hit the left boundary
                Judge = true;
            }
        } else if (S[x] == 'R') {
            S_R++;
            if (s_c + (S_R - T_L) == W + 1) {  // Check if S is about to hit the right boundary
                Judge = true;
            }
        } else if (S[x] == 'U') {
            S_U++;
            if (S_U - T_D - s_r == 0) {  // Check if S is about to hit the upper boundary
                Judge = true;
            }
        } else if (S[x] == 'D') {
            S_D++;
            if (s_r + (S_D - T_U) == H + 1) {  // Check if S is about to hit the lower boundary
                Judge = true;
            }
        }

        // Update the counters for T based on its movements
        if (T[x] == 'L') {
            if (S_R - T_L + s_c != 1) {  // Check if T is about to move left
                T_L++;
            }
        }
        if (T[x] == 'R') {
            if (s_c + (T_R - S_L) != W) {  // Check if T is about to move right
                T_R++;
            }
        }
        if (T[x] == 'U') {
            if (S_D - T_U + s_r != 1) {  // Check if T is about to move up
                T_U++;
            }
        }
        if (T[x] == 'D') {
            if (s_r + (T_D - S_U) != H) {  // Check if T is about to move down
                T_D++;
            }
        }
    }

    // Check the flag and print the result
    if (Judge) {
        printf("NO\n");  // Print 'NO' if the robot is out of bounds
    } else {
        printf("YES\n");  // Print 'YES' if the robot is within bounds
    }

    return 0;
}
