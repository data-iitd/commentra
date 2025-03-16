package main

import (
	"fmt"
	"math"
)

func main() {
	// Step 1: Reading Input
	var iMin, min int
	var i, j, k int
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
	excluded := make([]bool, 256)
	for i := 0; i < N; i++ {
		fmt.Scan(&j)
		excluded[j] = true
	}
	
	// Step 4: Finding the Nearest Non-Zero Value
	iMin = 0
	min = 1000
	for i := 255; i >= 0; i-- {
		if excluded[i] {
			continue
		}
		k := int(math.Abs(float64(X - plus[i])))
		if k <= min {
			min = k
			iMin = i
		}
	}
	
	// Step 5: Outputting the Result
	fmt.Println(iMin)
}

