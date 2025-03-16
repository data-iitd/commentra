
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Step 1: Reading Input Values
	A, _ := strconv.Atoi(os.Args[1])
	B, _ := strconv.Atoi(os.Args[2])
	n, _ := strconv.Atoi(os.Args[3])

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
			fmt.Println(neg ? -x : x)
			return
		}
	}

	// Step 6: No Solution Found
	fmt.Println("No solution")
}

