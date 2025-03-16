
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of books (n), the number of skills (m), and the minimum skill level required (x)
	n, m, x := readInt()

	// Read the cost matrix where each row represents a book and columns represent cost and skill levels
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = readInt()
	}

	// Initialize a range array to help generate combinations
	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}

	// Initialize lists to store combinations and removable combinations
	l := make([][]int, 0)
	rem := make([]int, 0)

	// Initialize the answer variable to store the minimum cost
	ans := 0

	// Generate all possible combinations of books using itertools.combinations
	for i := 1; i <= n; i++ {
		for _, j := range combination(pre, i) {
			l = append(l, j)
		}
	}

	// Check each combination to see if the total cost meets the requirement and adjust the list accordingly
	for i := 1; i <= m; i++ {
		for j, k := range l {
			ca := 0
			for _, ii := range k {
				ca += c[ii][i]
			}
			if ca < x {
				rem = append(rem, j)
			} else {
				// Do nothing
			}
		}
		if len(rem) > 0 {
			for _, j := range rem {
				l = append(l[:j], l[j+1:]...)
			}
			rem = make([]int, 0)
		}
		if len(l) == 0 {
			fmt.Println(-1)
			break
		}
	} else {
		// Find the minimum cost among the valid combinations
		for _, i := range l {
			ca := 0
			for _, j := range i {
				ca += c[j][0]
			}
			if ans == 0 {
				ans = ca
			} else {
				ans = min(ans, ca)
			}
		}
		fmt.Println(ans)
	}
}

func readInt() (int, int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	var n, m, x int
	fmt.Scan(&n, &m, &x)
	return n, m, x
}

func combination(arr []int, r int) [][]int {
	var result [][]int
	var combination func(arr []int, r int, index int, combination []int)
	combination = func(arr []int, r int, index int, combination []int) {
		if len(combination) == r {
			result = append(result, combination)
			return
		}
		for i := index; i < len(arr); i++ {
			combination = append(combination, arr[i])
			combination(arr, r, i+1, combination)
			combination = combination[:len(combination)-1]
		}
	}
	combination(arr, r, 0, []int{})
	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

