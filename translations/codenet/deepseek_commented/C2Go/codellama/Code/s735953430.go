package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Step 1: Reading Input
	var i_min, min int
	var i, j, k int
	var X, N int
	var err error
	if len(os.Args) != 3 {
		fmt.Println("Usage: ./main X N")
		os.Exit(1)
	}
	X, err = strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("X must be an integer")
		os.Exit(1)
	}
	N, err = strconv.Atoi(os.Args[2])
	if err != nil {
		fmt.Println("N must be an integer")
		os.Exit(1)
	}

	// If no values are excluded, print X and exit
	if N == 0 {
		fmt.Println(X)
		os.Exit(0)
	}

	// Step 2: Initializing Arrays
	plus := make([]int, 256)
	minus := make([]int, 256)
	for i = 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -i
	}

	// Step 3: Marking Excluded Values
	for i = 0; i < N; i++ {
		if len(os.Args) != 3 {
			fmt.Println("Usage: ./main X N")
			os.Exit(1)
		}
		j, err = strconv.Atoi(os.Args[2])
		if err != nil {
			fmt.Println("N must be an integer")
			os.Exit(1)
		}
		plus[j] = 0
	}

	// Step 4: Finding the Nearest Non-Zero Value
	i_min = 0
	min = 1000
	for i = 255; i >= 0; i-- {
		if plus[i] == 0 && i > 0 {
			continue
		}
		k = X - plus[i]
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

