
#include <stdio.h>
#include <string.h>

typedef long long ll;

int main() {
    // Create an instance of Main and run the main logic
    Main main;
    main.run();
    return 0;
}

// Define a constant for the modulo operation
const ll MOD = (ll) 1e9 + 7;

class Main {
public:
    void run() {
        // Initialize a character array to store the input string
        char cs[100001];
        // Read the input string and store it in the character array
        scanf("%s", cs);
        
        // Initialize a 2D array for dynamic programming to store results
        ll dp[100001][13];
        // Initialize all elements of the dp array to 0
        memset(dp, 0, sizeof(dp));
        
        // Variable to keep track of the base value for calculations
        int base = 1;
        
        // Iterate through the characters of the input from the last to the first
        for (int i = 0; cs[i]!= '\0'; ++i) {
            // Check if the current character is a '?', which can be any digit
            if (cs[strlen(cs) - 1 - i] == '?') {
                // Loop through all possible previous remainders
                for (int pre = 0; pre < 13; ++pre) {
                    // Loop through all possible next digits (0-9)
                    for (int next = 0; next < 10; ++next) {
                        // Update the dp array for the current position and remainder
                        dp[i + 1][(base * next + pre) % 13] += dp[i][pre];
                        // Ensure the result stays within the MOD limit
                        dp[i + 1][(base * next + pre) % 13] %= MOD;
                    }
                }
            } else {
                // If the character is a digit, convert it to an integer
                int next = cs[strlen(cs) - 1 - i] - '0';
                // Loop through all possible previous remainders
                for (int pre = 0; pre < 13; ++pre) {
                    // Update the dp array for the current position and remainder
                    dp[i + 1][(base * next + pre) % 13] += dp[i][pre];
                    // Ensure the result stays within the MOD limit
                    dp[i + 1][(base * next + pre) % 13] %= MOD;
                }
            }
            // Update the base value for the next iteration (moving to the next digit)
            base = base * 10 % 13;
        }
        
        // Output the result, which is the number of ways to form a number divisible by 13
        printf("%lld\n", dp[strlen(cs)][5]);
    }
};

// Utility function to print debug information
void tr(char *format,...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}