// Define the modulus value for calculations to prevent overflow
int mod = 10 ** 9 + 7;

// Read the input string
String l = scanner.next();

// Get the length of the input string
int n = l.length();

// Initialize a 2D list (dp) to store the number of ways to form valid sequences
// dp[i][0] will store the count of sequences ending with '0'
// dp[i][1] will store the count of sequences ending with '1'
int[][] dp = new int[n + 1][2];

// Base case: there's one way to have an empty sequence
dp[0][0] = 1;

// Iterate through each character in the input string
for (int i = 0; i < n; i++) {
    char c = l.charAt(i);
    if (c == '0') {
        // If the current character is '0', update the counts for sequences ending with '0'
        dp[i + 1][0] += dp[i][0]; // Continue sequences ending with '0'
        // Update counts for sequences ending with '1' (can be formed by adding '0' to previous '1' sequences)
        dp[i + 1][1] += dp[i][1] * 3; // Three ways to extend previous '1' sequences
    } else {
        // If the current character is '1', update the counts for sequences ending with '0'
        dp[i + 1][0] += dp[i][0] * 2; // Two ways to extend previous '0' sequences
        // Update counts for sequences ending with '1'
        dp[i + 1][1] += dp[i][0]; // One way to form a new '1' from previous '0'
        dp[i + 1][1] += dp[i][1] * 3; // Three ways to extend previous '1' sequences
    }

    // Apply modulus to keep values manageable and prevent overflow
    dp[i + 1][0] %= mod;
    dp[i + 1][1] %= mod;
}

// Calculate the total number of valid sequences by summing both counts for the last character
// and apply modulus again
System.out.println((dp[n][0] + dp[n][1]) % mod);

