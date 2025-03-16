package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x)
	min := math.MaxInt64
	a := make([][]int, n)

	// Filling the array with nutrient amounts for each ingredient
	for i := 0; i < n; i++ {
		a[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	// Generating all possible combinations of ingredients
	for i := 0; i < int(math.Pow(2, float64(n))); i++ {
		status := make([]int, n)
		for j := 0; j < n; j++ {
			if (1 & (i >> j)) == 1 {
				status[j] = 1
			}
		}
		res := make([]int, m+1)
		for j := 0; j < n; j++ {
			if status[j] == 1 {
				for k := 0; k <= m; k++ {
					res[k] += a[j][k]
				}
			}
		}
		flag := true
		for j := 1; j <= m; j++ {
			if res[j] < x {
				flag = false
				break
			}
		}
		if flag {
			min = int(math.Min(float64(min), float64(res[0])))
		}
	}

	// Outputting the result
	if min == math.MaxInt64 {
		fmt.Println(-1)
	} else {
		fmt.Println(min)
	}
}
