package main

import (
	"fmt"
	"math"
)

// Function to compute the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to compute the least common multiple (LCM) of two numbers
func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

// Function to get the prime factorization of a number
func getPrimeFactor(n int) map[int]int {
	res := make(map[int]int)
	// Iterate from 2 to the square root of n
	for i := 2; i*i <= n; i++ {
		// While i divides n, store i in the result map
		for n%i == 0 {
			res[i]++
			n /= i
		}
	}
	// If n is still greater than 1, it is a prime factor
	if n > 1 {
		res[n] = 1
	}
	return res
}

// Function to check if a number is prime
func isPrimeNumber(num int) bool {
	if num <= 2 {
		return true // 0, 1, and 2 are considered prime
	} else if num%2 == 0 {
		return false // Exclude even numbers
	}

	sqrtNum := int(math.Sqrt(float64(num)))
	// Check for factors from 3 to the square root of num
	for i := 3; i <= sqrtNum; i += 2 {
		if num%i == 0 {
			return false // Found a factor, not prime
		}
	}

	return true // No factors found, num is prime
}

// Function to compute modular inverse using the Extended Euclidean Algorithm
func modinv(a, m int) int {
	b, u, v := m, 1, 0
	// Loop until b becomes zero
	for b != 0 {
		t := a / b
		a, b = b, a - t*b // Swap a and b
		u, v = v, u - t*v // Update u and v
	}
	u %= m // Ensure u is within the modulo
	if u < 0 {
		u += m // Adjust if u is negative
	}
	return u // Return the modular inverse
}

func main() {
	var N, K int
	// Input the number of elements and the value of K
	fmt.Scan(&N, &K)

	A := make([]int, N+1)
	// Input the elements into the slice A
	for i := 1; i <= N; i++ {
		fmt.Scan(&A[i])
	}

	cur := 1 // Initialize current position
	dic := make([]int, N+1)
	for i := range dic {
		dic[i] = -1 // Initialize dictionary with -1
	}
	var flg bool // Flag to indicate if we have entered a cycle

	// Process the sequence based on the value of K
	for i := 1; i <= K; i++ {
		// If current index has not been seen before or we are in a cycle
		if dic[cur] < 0 || flg {
			dic[cur] = i // Record the current index
			cur = A[cur] // Move to the next index
		} else if !flg {
			// If we have seen this index before and are not in a cycle
			tmp := K - (dic[cur] - 1)
			tmp %= i - dic[cur] // Adjust steps based on the cycle length
			i = K - tmp         // Update i to skip to the end of the cycle
			flg = true          // Set the flag indicating we are in a cycle
		}
	}

	// Output the final position after K steps
	fmt.Println(cur)
}

