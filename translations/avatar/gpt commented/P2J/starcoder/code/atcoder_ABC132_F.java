// Define the modulus value for calculations to prevent overflow
int mod = 1000000007;

// Read input values for n and k
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int k = sc.nextInt();

// Initialize a list to store coefficients
List<Integer> coef = new ArrayList<>();

// Calculate coefficients based on the divisors of n
for (int i = 1; i <= Math.sqrt(n); i++) {
    // Append the count of divisors in the range
    coef.add((n / i) - (n / (i + 1)));
}

// Fill the remaining coefficients with 1s to ensure the length matches n
while (coef.size() < n) {
    coef.add(1);
}

// Reverse the coefficients list for further processing
Collections.reverse(coef);

// Get the length of the coefficients list
int nn = coef.size();

// Initialize a 2D list for dynamic programming
// dp[i][j] will store the result for i selections and j coefficients
int[][] dp = new int[k + 1][nn];

// Base case: there's one way to select 0 items (select nothing)
dp[0][0] = 1;

// Fill the dp table for k selections
for (int i = 1; i <= k; i++) {
    int tmp = 0;  // Temporary variable to accumulate values
    // Iterate through the coefficients in reverse order
    for (int j = nn - 1; j >= 0; j--) {
        // Accumulate the number of ways to select items
        tmp += dp[i - 1][j];
        tmp %= mod;  // Ensure the value stays within modulus
        // Calculate the number of ways to select i items using the j-th coefficient
        dp[i][j] = coef.get(j) * tmp;
        dp[i][j] %= mod;  // Again, ensure the value stays within modulus
}

// Output the total number of ways to select k items, taking modulus
System.out.println(Arrays.stream(dp[k]).sum() % mod);

