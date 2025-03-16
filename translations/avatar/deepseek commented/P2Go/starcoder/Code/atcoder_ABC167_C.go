package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of books (n), the number of skills (m), and the minimum skill level required (x)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m, &x)

	// Read the cost matrix where each row represents a book and columns represent cost and skill levels
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m + 1)
		for j := 0; j < m + 1; j++ {
			fmt.Fscan(reader, &c[i][j])
		}
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
		for j := range pre[:i] {
			l = append(l, pre[j:i])
		}
	}

	// Check each combination to see if the total cost meets the requirement and adjust the list accordingly
	for i := 1; i <= m; i++ {
		for j, k := range l {
			ca := 0
			for ii := range k {
				ca += c[k[ii]][i]
			}
			if ca < x {
				rem = append(rem, j)
			} else {
				continue
			}
		}
		if len(rem) > 0 {
			for j := range rem {
				l = append(l[:j], l[j+1:]...)
			}
			rem = make([]int, 0)
		}
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}

	// Find the minimum cost among the valid combinations
	for i := range l {
		ca := 0
		for j := range l[i] {
			ca += c[l[i][j]][0]
		}
		if ans == 0 {
			ans = ca
		} else {
			ans = min(ans, ca)
	}
	fmt.Println(ans)
}

