package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	solve(os.Stdin)
}

func solve(sc *os.File) {
	// Step 1: Reading Input Values
	var A, B, n int
	fmt.Fscan(sc, &A, &B, &n)

	// Step 2: Handling Special Case A == 0
	if A == 0 {
		if B == 0 {
			fmt.Println(1)
		} else {
			fmt.Println("No solution")
		}
		return
	}

	// Step 3: Checking Divisibility
	if B%A != 0 {
		fmt.Println("No solution")
		return
	}

	// Step 4: Normalizing B
	B /= A
	neg := B < 0
	if neg && n%2 == 0 {
		fmt.Println("No solution")
		return
	}
	if neg {
		B = -B
	}

	// Step 5: Iterating to Find Solution
	for x := 0; x <= B; x++ {
		if math.Pow(float64(x), float64(n)) == float64(B) {
			if neg {
				fmt.Println(-x)
			} else {
				fmt.Println(x)
			}
			return
		}
	}

	// Step 6: No Solution Found
	fmt.Println("No solution")
}

