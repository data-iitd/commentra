
#####
# Code
#####

# Include necessary libraries
#include <iostream>
#include <string>

// Define main function
int main() {
    // Initialize variables
    int H, W, N;
    std::cin >> H >> W >> N;
    int s_r, s_c;
    std::cin >> s_r >> s_c;
    std::string S, T;
    std::cin >> S >> T;
    bool Judge = false;

    // Initialize variables for string S
    int S_L = 0, S_R = 0, S_U = 0, S_D = 0;

    // Iterate through string S
    for (int x = 0; x < N; x++) {
        // Check current character in S
        if (S[x] == 'L') {
            S_L++;
            // Check condition for 'L'
            if (S_L - T_R - s_c == 0) {
                Judge = true;
            }
        } else if (S[x] == 'R') {
            S_R++;
            // Check condition for 'R'
            if (s_c + (S_R - T_L) == W + 1) {
                Judge = true;
            }
        } else if (S[x] == 'U') {
            S_U++;
            // Check condition for 'U'
            if (S_U - T_D - s_r == 0) {
                Judge = true;
            }
        } else if (S[x] == 'D') {
            S_D++;
            // Check condition for 'D'
            if (s_r + (S_D - T_U) == H + 1) {
                Judge = true;
            }
        }
    }

    // Initialize variables for string T
    int T_L = 0, T_R = 0, T_U = 0, T_D = 0;

    // Iterate through string T and adjust variables accordingly
    for (int x = 0; x < N; x++) {
        // Check current character in T
        if (T[x] == 'L') {
            // Adjust T_L variable
            if (S_R - T_L + s_c!= 1) {
                T_L++;
            }
        } else if (T[x] == 'R') {
            // Adjust T_R variable
            if (s_c + (T_R - S_L)!= W) {
                T_R++;
            }
        } else if (T[x] == 'U') {
            // Adjust T_U variable
            if (S_D - T_U + s_r!= 1) {
                T_U++;
            }
        } else if (T[x] == 'D') {
            // Adjust T_D variable
            if (s_r + (T_D - S_U)!= H) {
                T_D++;
            }
        }
    }

    // Check final condition
    if (Judge) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
