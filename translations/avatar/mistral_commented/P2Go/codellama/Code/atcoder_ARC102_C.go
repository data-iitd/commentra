// Define K and N as integers read from the standard input
K, N := readInt(), readInt()

// Define a helper function to print arguments with a space between them
func dprint(x ...interface{}) {
	fmt.Println(x...)
}

// Define a function to compute the number of combinations of r items chosen from a set of n items, modulo a given modulus
func cmb(n, r, mod int) int {
	// Check if r is out of range
	if r < 0 || r > n {
		return 0
	}
	// Adjust r to be between 0 and n
	r = min(r, n - r)
	// Compute the combination using the formula
	return g1[n] * g2[r] * g2[n - r] % mod
}

// Set the modulus to 998244353
mod := 998244353

// Define a constant N for the size of the arrays
const __N = 8000

// Initialize g1 and g2 with the first two elements
g1 := []int{1, 1}
g2 := []int{1, 1}

// Initialize inverse with the first two elements and the identity list
inverse := []int{0, 1}
for i := 2; i <= __N + 1; i++ {
	// Compute g1[i] using the previous value and the current i
	g1 = append(g1, (g1[len(g1) - 1] * i) % mod)
	// Compute inverse[i] using the formula
	inverse = append(inverse, (-inverse[mod % i] * (mod / i)) % mod)
	// Compute g2[i] using the previous values of g1 and inverse
	g2 = append(g2, (g2[len(g2) - 1] * inverse[len(inverse) - 1]) % mod)
}

// Define a function to compute the value of a combinatorial sum
func kumiawase(p, q int) int {
	// Compute the combination using the cmb function
	return cmb(p + q - 1, q - 1, mod)
}

// Define a function to compute the answer for a given value of n
func solve(n int) int {
	// Check if n is out of range
	assert(n <= K + 1)
	// Initialize the answer as 0
	ans := 0
	// Compute the number of pairs (p, q) such that p <= N and q <= K - p
	kumi := (n - 1) / 2
	// Compute the answer using the kumiawase function and the precomputed values
	for p := 0; p <= kumi + 1; p++ {
		if p > N {
			break
		}
		ans += 2**p * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi*2 - int(n%2 == 0)))
		if n%2 == 0 && N - p - 1 >= 0 {
			ans += 2**p * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi*2 - int(n%2 == 0)))
		}
	}
	// Return the answer
	return ans
}

// Initialize an empty list to store the answers
ans := []int{}

// Compute the answers for all integers from 2 to 2K+1
for i := 2; i <= 2*K + 1; i++ {
	// Compute the answer for the current integer using the solve function
	tmp := solve(i) % mod
	// Store the answer in the ans list
	ans = append(ans, tmp)
	// Print the answer
	dprint(tmp)
}

// Print the answers for the negative integers by reprinting the results from the ans list
for i := 2; i <= 2*K + 1; i++ {
	if i <= K + 1 {
		dprint(ans[i - K])
	} else {
		dprint(ans[-i + K])
	}
}

