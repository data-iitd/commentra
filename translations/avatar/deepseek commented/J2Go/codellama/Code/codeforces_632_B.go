
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Reading Input
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Step 2: Reading a String
	var s string
	fmt.Scan(&s)

	// Step 3: Initial Sum Calculation
	sum := 0
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += a[i]
		}
	}

	// Step 4: First Loop
	ans := sum
	sum1 := sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		if sum1 > ans {
			ans = sum1
		}
	}

	// Step 5: Second Loop
	sum1 = sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		if sum1 > ans {
			ans = sum1
		}
	}

	// Step 6: Output
	fmt.Println(ans)
}

