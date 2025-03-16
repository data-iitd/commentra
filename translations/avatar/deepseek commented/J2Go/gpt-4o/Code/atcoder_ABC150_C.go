package main

import (
	"fmt"
	"math"
	"strings"
)

func permutation(list *[]string, target, ans string) {
	if len(target) <= 1 {
		*list = append(*list, ans+target)
	} else {
		for i := 0; i < len(target); i++ {
			permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
		}
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize a 2D slice to store the input strings
	line := make([][]string, 2)
	for i := 0; i < 2; i++ {
		line[i] = []string{""}
		// Read n strings and concatenate them
		for j := 0; j < n; j++ {
			var input string
			fmt.Scan(&input)
			line[i][0] += input
		}
	}

	// Generate the number string for permutations
	number := ""
	for i := 1; i <= n; i++ {
		number += fmt.Sprint(i)
	}

	// Create a slice to store permutations
	var listA []string
	// Generate all permutations of the number string
	permutation(&listA, number, "")

	// Initialize sum to calculate the result
	sum := 0
	// Compare permutations with input strings and calculate the sum
	for j := 0; j < len(line); j++ {
		for i := 0; i < len(listA); i++ {
			if listA[i] == line[j][0] {
				if sum == 0 {
					sum += i
				} else {
					sum -= i
				}
			}
		}
	}

	// Print the absolute value of the sum
	fmt.Println(int(math.Abs(float64(sum))))
}

// <END-OF-CODE>
