// Read input values K and N from user
var K, N int
fmt.Scanf("%d %d", &K, &N)

// Define a debug print function (currently does nothing)
func dprint(x...interface{}) {}

// Function to compute combinations modulo'mod'
func cmb(n, r, mod int) int {
	// Return 0 if r is out of bounds
	if r < 0 || r > n {
		return 0
	}
	// Use symmetry property of combinations
	r = min(r, n-r)
	// Calculate combination using precomputed factorials and inverses
	return g1[n] * g2[r] * g2[n-r] % mod
}

// Set modulo value and maximum value for precomputation
const mod = 998244353
const __N = 8000

// Precompute factorials and inverse factorials
var g1 = []int{1, 1} // g1 will hold factorials
var g2 = []int{1, 1} // g2 will hold inverse factorials
var inverse = []int{0, 1} // inverse will hold modular inverses

// Fill g1, g2, and inverse arrays
for i := 2; i <= __N; i++ {
	g1 = append(g1, (g1[i-1]*i)%mod) // Compute factorial
	inverse = append(inverse, (-inverse[mod%i]*(mod/i))%mod) // Compute modular inverse using Fermat's Little Theorem
	g2 = append(g2, (g2[i-1]*inverse[i])%mod) // Compute inverse factorial
}

// Function to compute kumiawase (combinations with repetition)
func kumiawase(p, q int) int {
	return cmb(p+q-1, q-1, mod)
}

// Function to solve the main problem for a given n
func solve(n int) int {
	// Ensure n is within valid range
	if n > K+1 {
		panic("n is out of range")
	}
	ans := 0 // Initialize answer
	kumi := (n-1)/2 // Calculate half of n-1

	// Iterate over possible values of p
	for p := 0; p <= kumi; p++ {
		if p > N { // Break if p exceeds N
			break
		}
		// Update answer with contributions from current p
		ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p, p+(K-(kumi*2)-(n%2==0)))

		// If n is even, consider the case where p is used one less
		if n%2 == 0 && N-p-1 >= 0 {
			ans += 1 << uint(p) * cmb(kumi, p, mod) * kumiawase(N-p-1, p+(K-(kumi*2)-(n%2==0)))
	}

	return ans // Return the computed answer
}

// List to store answers for each i
var ans []int

// Iterate over the range to compute results for each i
for i := 2; i <= 2*K+1; i++ {
	if i <= K+1 {
		// Solve for i and store the result
		tmp := solve(i) % 998244353
		ans = append(ans, tmp) // Append result to answers list
		fmt.Println(tmp) // Print the result
	} else {
		// For i greater than K+1, use previously computed results
		fmt.Println(ans[i-K-1]) // Print the corresponding result from the answers list
	}
}

