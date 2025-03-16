
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N := readInt()
	// Ask the user for an integer `N` and store it in a variable called `N`

	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = readInt()*N + i
	}
	// Create a slice `A` with `N` elements. Each element is the product of an integer input by the user and `N`,
	// plus an index `i` that goes from `0` to `N-1`.

	sort.Ints(A)
	// Sort the slice `A` in ascending order.

	cnt := 0
	// Initialize a counter `cnt` to zero.

	for i := 0; i < N; i++ {
		// Iterate through each index `i` in the slice `A`.
		d := (A[i] % N) % 2
		// Calculate the remainder of `A[i]` divided by `N` and modulo 2.
		// Store this result in a variable called `d`.

		if d%2!= i%2 {
			// Check if the remainder of `d` divided by 2 is different from the remainder of `i` divided by 2.
			// If they are different, increment the counter `cnt` by 1.
			cnt++
		}
	}

	fmt.Println(cnt / 2)
	// After the loop finishes, print the result of the counter `cnt` divided by 2.
}

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, err := strconv.Atoi(scanner.Text())
	if err!= nil {
		panic(err)
	}
	return num
}

