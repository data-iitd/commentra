<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Function to get prime factors of a number

func getPrimeFactor(n int) map[int]int {
	res := make(map[int]int)
	// Initialize an empty map to store prime factors and their exponents

	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			res[i]++
			// If the number is divisible by 'i', add it to the map with its exponent incremented

			n /= i
		}
	}
	if n!= 1 {
		res[n] = 1
	}
	// If the number is not 1, add it to the map with exponent 1

	return res
}

// Function to check if a number is prime

func IsPrimeNumber(num int) bool {
	if num <= 2 {
		return true
	} else if num%2 == 0 {
		return false
	}

	sqrtNum := int(math.Sqrt(float64(num)))
	// Check if the number is prime by checking divisibility up to its square root

	for i := 3; i <= sqrtNum; i += 2 {
		if num%i == 0 {
			return false
		}
	}

	return true
}

// Function to find modular multiplicative inverse

func modinv(a, m int) int {
	b := m
	u := 1
	v := 0
	// Extended Euclidean Algorithm to find modular multiplicative inverse

	for b!= 0 {
		t := a / b
		a -= t * b
		u -= t * v
		a, b = b, a
		u, v = v, u
	}
	u %= m
	// Make the result positive and less than'm'

	if u < 0 {
		u += m
	}
	return u
}

// Function to get the distance from the start for each position

func getDist(A []int, N, K int) []int {
	dic := make([]int, N+1)
	// Initialize an array 'dic' of size 'N+1' to store the distance from the start for each position

	for i := 1; i <= N; i++ {
		dic[i] = -1
	}
	// Initialize a variable 'cur' to keep track of the current position in the array

	cur := 1
	flg := false
	// Initialize a boolean variable 'flg' to check if we need to reverse the direction of traversal

	for i := 1; i <= K; i++ {
		if dic[cur] < 0 || flg {
			dic[cur] = i
			// If the distance from the start for the current position is not yet determined or we need to reverse the direction, update the distance

			cur = A[cur]
			// Move to the next position
		} else if!flg {
			tmp := K - (dic[cur] - 1)
			tmp %= i - dic[cur]
			// Calculate the number of steps we need to take to reach the position 'i' from the current position

			i = K - tmp
			// Update 'i' to the position we need to reach

			flg = true
		}
	}

	return dic
}

// Function to get the position of the last visited node

func getPos(A []int, N, K int) int {
	dic := getDist(A, N, K)
	// Get the distance from the start for each position

	return dic[1]
}

// Main function to solve the problem

func main() {
	var N, K int
	// Declare variables for input

	fmt.Scanf("%d %d", &N, &K)
	// Read input for 'N' and 'K'

	A := make([]int, N+1)
	// Initialize an array 'A' of size 'N+1'

	for i := 1; i <= N; i++ {
		fmt.Scanf("%d", &A[i])
		// Read input for each element of the array 'A'
	}

	fmt.Println(getPos(A, N, K))
	// Print the final answer, which is the position of the last visited node
}
// Main function to solve the problem

