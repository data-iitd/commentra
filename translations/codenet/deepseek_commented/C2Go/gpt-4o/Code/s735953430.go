package main

import (
	"fmt"
	"math"
)

func main() {
	// Step 1: Reading Input
	var X, N int
	fmt.Scan(&X, &N)

	// If no values are excluded, print X and exit
	if N == 0 {
		fmt.Println(X)
		return
	}

	// Step 2: Initializing Arrays
	plus := make([]int, 256)
	minus := make([]int, 256)
	for i := 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -i
	}

	// Step 3: Marking Excluded Values
	for i := 0; i < N; i++ {
		var j int
		fmt.Scan(&j)
		plus[j] = 0
	}

	// Step 4: Finding the Nearest Non-Zero Value
	i_min := 0
	min := math.MaxInt32
	for i := 255; i >= 0; i-- {
		if plus[i] == 0 && i > 0 {
			continue
		}
		k := X - plus[i]
		if k < 0 {
			k *= -1
		}
		if k <= min {
			min = k
			i_min = i
		}
	}

	// Step 5: Outputting the Result
	fmt.Println(i_min)
}

// <END-OF-CODE>
