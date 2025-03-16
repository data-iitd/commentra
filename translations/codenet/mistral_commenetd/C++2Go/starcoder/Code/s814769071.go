
<<<<<<< HEAD

import "fmt"
=======
package main

import (
	"fmt"
	"math"
)
>>>>>>> 98c87cb78a (data updated)

func main() {
	// Initialize variables
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
<<<<<<< HEAD
	MOD := 1e9 + 7
=======
	MOD := int(math.Pow(10, 9) + 7)
>>>>>>> 98c87cb78a (data updated)

	// Calculate the maximum number of unique elements in a subset of size k from 1 to n
	mx := n * (n + 1) / 2 - (n - k)*(n - k + 1) / 2

	// Calculate the minimum number of unique elements in a subset of size k from 1 to n
	mn := k * (k - 1) / 2

	// Initialize result variable
	res := 0

	// Iterate through all possible subset sizes from k to n+1
	for i := k; i <= n+1; i++ {
		// Calculate the number of unique elements in the current subset
		res += mx - mn + 1

		// Update the maximum and minimum number of unique elements for the next iteration
		mx += n - i
		mn += i

		// Update the result variable
		res %= MOD
	}

	// Print the final result
	fmt.Println(res)
}

