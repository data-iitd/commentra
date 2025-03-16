
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var n, m int

	// Read input values for n and m
	fmt.Scanf("%d%d", &n, &m)

	// Initialize boolean array r0 with all elements set to false
	r0 := make([]bool, n)

	// Initialize integer array r1 and counter for its size
	r1 := make([]int, n)
	nr1 := 0

	// Process each of the m input pairs
	for i := 0; i < m; i++ {
		// Read input values for a and b
		var a, b int
		fmt.Scanf("%d%d", &a, &b)

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

