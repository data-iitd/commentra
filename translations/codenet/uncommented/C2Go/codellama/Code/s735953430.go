package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var i_min, min int
	var i, j, k int
	var X, N int
	var err error
	var plus, minus [256]int

	if len(os.Args) != 3 {
		fmt.Println("Usage:", os.Args[0], "X N")
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

	if N == 0 {
		fmt.Println(X)
		os.Exit(0)
	}

	for i = 0; i < 256; i++ {
		plus[i] = i
		minus[i] = (-1 * i)
	}

	for i = 0; i < N; i++ {
		j, err = strconv.Atoi(os.Args[i+2])
		if err != nil {
			fmt.Println("N must be an integer")
			os.Exit(1)
		}
		plus[j] = 0
	}

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

	fmt.Println(i_min)
}

