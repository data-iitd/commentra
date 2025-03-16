package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const mod = 1000000007

// Function to calculate power of x raised to n modulo mod
func power(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	val := power(x, n/2)
	if n%2 == 1 {
		val = (val * x) % mod
	}
	return val
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Reading the first line of input
	line, _ := reader.ReadString('\n')
	var n int
	fmt.Sscanf(line, "%d", &n)

	// Reading the second line of input
	line, _ = reader.ReadString('\n')
	c := make([]int64, n)

	// Initializing the array c with the input values
	for i := 0; i < n; i++ {
		fmt.Sscanf(line, "%d", &c[i])
		line = line[len(fmt.Sprintf("%d", c[i]))+1:] // Move to the next number
	}

	// Special case when the size of the array is 1
	if n == 1 {
		fmt.Println(c[0]*2%mod)
		return
	}

	// Sorting the array c
	sort.Slice(c, func(i, j int) bool {
		return c[i] < c[j]
	})

	// Calculating the values of b and a
	b := power(2, int64(n))
	a := power(2, int64(n-2))

	// Initializing the variable ans to 0
	var ans int64 = 0

	// Iterating through the array from index 2 to n+1
	for i := 2; i <= n+1; i++ {
		// Calculating the value of val using the current index i and the previously calculated value a
		val := (a * int64(i)) % mod
		val = (val * c[n+1-i]) % mod

		// Adding the value of val to the variable ans
		ans = (ans + val) % mod
	}

	// Multiplying the value of ans with the value of b
	ans = (ans * b) % mod

	// Printing the final result
	fmt.Println(ans)
}

// <END-OF-CODE>
