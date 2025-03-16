
// Set the modulus value
const mod = 1e9 + 7

// Read input values for n and k
var n, k int
fmt.Scanf("%d %d\n", &n, &k)

// Initialize a list 'coef' to store coefficients
var coef []int

// Calculate coefficients for n up to its square root
for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
    // Calculate the difference between the quotient and the next quotient
    coef = append(coef, n/i-n/(i+1))
}

// Add remaining coefficients to the list
coef = append(coef, make([]int, n-len(coef))...)

// Reverse the list 'coef'
for i, j := 0, len(coef)-1; i < j; i, j = i+1, j-1 {
    coef[i], coef[j] = coef[j], coef[i]
}

// Initialize a 2D list 'dp' to store intermediate results
var dp [][]int
for i := 0; i <= k; i++ {
    dp = append(dp, make([]int, len(coef)))
}

// Initialize the first row of dp with 1 at index 0
dp[0][0] = 1

// Calculate dp[i][j] for i from 1 to k and j from nn-1 to 0
for i := 1; i <= k; i++ {
    tmp := 0
    // Iterate through the reverse list 'coef' from j = nn-1 to j = 0
    for j := len(coef) - 1; j >= 0; j-- {
        // Update 'tmp' with the sum of dp[i-1][j] and the product of coef[j] and tmp
        tmp += dp[i-1][j]
        tmp = (tmp + coef[j]) % mod
        // Update dp[i][j] with the product of coef[j] and tmp
        dp[i][j] = coef[j] * tmp
        dp[i][j] %= mod
}

// Calculate the final answer by summing up dp[k]
fmt.Printf("%d\n", dp[k][0])

