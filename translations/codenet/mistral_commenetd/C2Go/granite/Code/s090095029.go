

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize variables
	var n, m int

	// Read input values for n and m
	reader := bufio.NewReader(os.Stdin)
	n64, _ := reader.ReadString('\n')
	m64, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(n64)
	m, _ = strconv.Atoi(m64)

	// Initialize boolean array r0 with all elements set to false
	r0 := make([]bool, n)

	// Initialize integer array r1 and counter for its size
	r1 := make([]int, n)
	var nr1 int

	// Process each of the m input pairs
	for i := 0; i < m; i++ {
		// Read input values for a and b
		a64, _ := reader.ReadString(' ')
		b64, _ := reader.ReadString('\n')
		a, _ := strconv.Atoi(a64)
		b, _ := strconv.Atoi(b64)

		// Swap a and b if a is greater than b
		if a > b {
			a, b = b, a
		}

		// If a is equal to 1, set the corresponding element in r0 to true
		if a == 1 {
			r0[b-1] = true
		}

		// If b is equal to n, add its index to r1
		if b == n {
			r1[nr1] = a - 1
			nr1++
		}
	}

	// Initialize boolean variable res to false
	res := false

	// Check if there exists any pair in r1 whose corresponding element in r0 is true
	for i := 0; i < nr1; i++ {
		// If such a pair is found, set res to true
		if r0[r1[i]] {
			res = true
		}
	}

	// Output the result based on the value of res
	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

