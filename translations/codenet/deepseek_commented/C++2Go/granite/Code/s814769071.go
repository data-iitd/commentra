
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	// Step 2: Read input values
	n, k := readInt(), readInt()
	MOD := 1e9 + 7

	// Step 3: Calculate the maximum and minimum sums
	mx := n*(n+1)/2 - (n-k)*(n-k+1)/2
	mn := k * (k - 1) / 2

	// Step 4: Initialize variables
	res := 0

	// Step 5: Loop through possible lengths
	for i := k; i <= n+1; i++ {
		// Update res, mx, and mn in each iteration
		res += mx - mn + 1
		mx += n - i
		mn += i
		res %= MOD
	}

	// Step 6: Output the result
	fmt.Fprintln(w, res)
	w.Flush()
}

func readInt() int {
	i, _ := fmt.Fscanf(r, "%d")
	return i
}

