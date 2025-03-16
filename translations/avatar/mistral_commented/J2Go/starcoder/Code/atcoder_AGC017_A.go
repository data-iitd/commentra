
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// C is a function to calculate the binomial coefficient C(n, m)
func C(n, m int) int {
	var res int = 1

	// Calculate the binomial coefficient for n choose m
	for i := m - n + 1; i <= m; i++ {
		res *= i
	}

	for i := 1; i <= n; i++ {
		res /= i
	}

	return res
}

func main() {
	var n, p int

	// Read the value of n from standard input
	fmt.Scanln(&n)

	// Read the value of p from standard input
	fmt.Scanln(&p)

	var k0, k1 int = 0, 0

	// Read the values of n elements and count the number of odd and even elements
	for i := 0; i < n; i++ {
		var x int

		// Read the value of x from standard input
		fmt.Scanln(&x)

		if x%2 == 1 {
			k1++
		} else {
			k0++
		}
	}

	var ans int = 1

	// Calculate the answer based on the given conditions
	for i := 0; i < k0; i++ {
		ans *= 2
	}

	if p == 0 {
		var add int = 0

		// Calculate the answer using the given formula
		for i := 0; i <= k1; i += 2 {
			add += C(i, k1)
		}

		ans *= add
	} else {
		var add int = 0

		// Calculate the answer using a similar formula
		for i := 1; i <= k1; i += 2 {
			add += C(i, k1)
		}

		ans *= add
	}

	// Print the final answer
	fmt.Println(ans)
}

