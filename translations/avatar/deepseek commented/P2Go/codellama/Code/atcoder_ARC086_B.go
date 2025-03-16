package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	maxVal := 0
	maxSign := 0
	maxIndex := -1

	for i, a0 := range a {
		if abs(a0) > maxVal {
			maxVal = abs(a0)
			maxSign = mySign(a0)
			maxIndex = i
		}
	}

	if maxSign == 0 {
		fmt.Println(0)
	} else if maxSign == 1 {
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex + 1, i + 1)
		}
		for i := 0; i < N-1; i++ {
			fmt.Println(i + 1, i + 2)
		}
	} else {
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex + 1, i + 1)
		}
		for i := N - 1; i >= 0; i-- {
			fmt.Println(i + 2, i + 1)
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func mySign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	}
	return 0
}

