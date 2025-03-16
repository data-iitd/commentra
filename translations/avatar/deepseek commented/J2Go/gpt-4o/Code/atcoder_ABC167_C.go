package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m, x int
	fmt.Scan(&n, &m, &x) // Reading the number of ingredients, nutrient types, and minimum requirement

	min := math.MaxInt32 // Initializing the minimum cost to a large value
	a := make([][]int, n) // Initializing the 2D slice to store nutrient amounts

	// Filling the slice with nutrient amounts for each ingredient
	for i := 0; i < n; i++ {
		a[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Scan(&a[i][j])
		}
	}

	// Generating all possible combinations of ingredients
	for i := 0; i < (1 << n); i++ {
		status := make([]int, n) // Slice to store the status of each ingredient in the combination
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 1 { // Checking if the j-th ingredient is included
				status[j] = 1
			}
		}
		res := make([]int, m+1) // Slice to store the total nutrient amounts for the current combination
		for j := 0; j < n; j++ {
			if status[j] == 1 { // Adding the nutrient amounts of included ingredients
				for k := 0; k <= m; k++ {
					res[k] += a[j][k]
				}
			}
		}
		flag := true // Flag to check if the current combination meets the requirement
		for j := 1; j <= m; j++ {
			if res[j] < x { // Checking if the nutrient requirement is met
				flag = false
				break
			}
		}
		if flag {
			min = int(math.Min(float64(min), float64(res[0]))) // Updating the minimum cost if the requirement is met
		}
	}

	// Outputting the result
	if min == math.MaxInt32 {
		fmt.Println(-1) // Outputting -1 if no combination meets the requirement
	} else {
		fmt.Println(min) // Outputting the minimum cost if a valid combination is found
	}
}

// <END-OF-CODE>
