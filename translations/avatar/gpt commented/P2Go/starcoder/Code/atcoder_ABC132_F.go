// Define the modulus value for calculations to prevent overflow
const mod = 1e9 + 7

// Read input values for n and k
var n, k int
fmt.Scanf("%d %d", &n, &k)

// Initialize a list to store coefficients
coef := make([]int, n)

// Calculate coefficients based on the divisors of n
for i := 1; i < int(math.Sqrt(float64(n)))+1; i++ {
    // Append the count of divisors in the range
    coef = append(coef, (n/i)-(n/(i+1)))
}

// Fill the remaining coefficients with 1s to ensure the length matches n
for i := len(coef); i < n; i++ {
    coef = append(coef, 1)
}

// Reverse the coefficients list for further processing
for i, j := 0, len(coef)-1; i < j; i, j = i+1, j-1 {
    coef[i], coef[j] = coef[j], coef[i]
}

// Get the length of the coefficients list
nn := len(coef)

// Initialize a 2D list for dynamic programming
// dp[i][j] will store the result for i selections and j coefficients
dp := make([][]int, k+1)
for i := range dp {
    dp[i] = make([]int, nn)
}

// Base case: there's one way to select 0 items (select nothing)
dp[0][0] = 1

// Fill the dp table for k selections
for i := 1; i <= k; i++ {
    tmp := 0  // Temporary variable to accumulate values
    // Iterate through the coefficients in reverse order
    for j := nn-1; j >= 0; j-- {
        // Accumulate the number of ways to select items
        tmp += dp[i-1][nn-1-j]
        tmp %= mod  // Ensure the value stays within modulus
        // Calculate the number of ways to select i items using the j-th coefficient
        dp[i][j] = coef[j]*tmp
        dp[i][j] %= mod  // Again, ensure the value stays within modulus
}

// Output the total number of ways to select k items, taking modulus
fmt.Println(sum(dp[k]) % mod)

