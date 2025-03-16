package main

import (
	"fmt"
	"strconv"
)

// Generates all permutations of a given string
func permutation(list []string, target string, ans string) []string {
	if len(target) <= 1 {
		list = append(list, ans+target)
	} else {
		for i := 0; i < len(target); i++ {
			permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
		}
	}
	return list
}

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize a 2D slice to store the input strings
	line := make([][]string, 2)
	for i := range line {
		line[i] = make([]string, 1)
		// Read n strings and concatenate them
		for j := 0; j < n; j++ {
			var s string
			fmt.Scan(&s)
			line[i][0] += s
		}
	}

	// Generate the number string for permutations
	number := ""
	for i := 1; i <= n; i++ {
		number += strconv.Itoa(i)
	}

	// Create a slice to store permutations
	var listA []string
	// Generate all permutations of the number string
	listA = permutation(listA, number, "")

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
	fmt.Println(abs(sum))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

