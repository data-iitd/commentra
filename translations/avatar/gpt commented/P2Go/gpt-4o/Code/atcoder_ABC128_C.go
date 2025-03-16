package main

import (
	"fmt"
	"math/bits"
)

func main() {
	// Reading the values of n and m from input
	var n, m int
	fmt.Scan(&n, &m)

	// Reading m lists of integers, each containing values after the first element
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		var size int
		fmt.Scan(&size)
		li[i] = make([]int, size-1)
		for j := 0; j < size-1; j++ {
			fmt.Scan(&li[i][j])
		}
	}

	// Reading a slice p from input
	p := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&p[i])
	}

	// Creating a set q that contains all unique elements from the lists in li
	q := make(map[int]struct{})
	for _, list := range li {
		for _, val := range list {
			q[val] = struct{}{}
		}
	}

	// Creating a set r that contains all integers from 1 to n
	r := make(map[int]struct{})
	for i := 1; i <= n; i++ {
		r[i] = struct{}{}
	}

	// Finding the set of values v that are in r but not in q
	v := make(map[int]struct{})
	for key := range r {
		if _, exists := q[key]; !exists {
			v[key] = struct{}{}
		}
	}

	// Initializing the answer variable to count valid combinations
	ans := 0

	// Converting q to a slice for combination generation
	qSlice := make([]int, 0, len(q))
	for key := range q {
		qSlice = append(qSlice, key)
	}

	// Iterating over all possible sizes of combinations from the set q
	for i := 0; i <= len(qSlice); i++ {
		// Generating combinations of size i from the set q
		combinations := generateCombinations(qSlice, i)
		for _, s := range combinations {
			sSet := make(map[int]struct{})
			for _, val := range s {
				sSet[val] = struct{}{}
			}

			// Checking each list in li against the corresponding value in p
			valid := true
			for u, w := range li {
				count := 0
				for _, val := range w {
					if _, exists := sSet[val]; exists {
						count++
					}
				}
				if count%2 != p[u] {
					valid = false
					break
				}
			}
			if valid {
				// If all checks passed, increment the answer by 2 raised to the power of the size of v
				ans += 1 << len(v) // 2 ** len(v) is equivalent to 1 << len(v)
			}
		}
	}

	// Printing the final answer
	fmt.Println(ans)
}

// Function to generate combinations of size k from slice arr
func generateCombinations(arr []int, k int) [][]int {
	var result [][]int
	var combination []int
	var backtrack func(start int)
	backtrack = func(start int) {
		if len(combination) == k {
			combinationCopy := make([]int, k)
			copy(combinationCopy, combination)
			result = append(result, combinationCopy)
			return
		}
		for i := start; i < len(arr); i++ {
			combination = append(combination, arr[i])
			backtrack(i + 1)
			combination = combination[:len(combination)-1]
		}
	}
	backtrack(0)
	return result
}

// <END-OF-CODE>
