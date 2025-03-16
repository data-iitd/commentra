package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read input: number of test cases, number of lists, and the lists themselves
	var n, m int
	fmt.Fscan(reader, &n, &m)

	li := make([][]int, m)
	for i := 0; i < m; i++ {
		var k int
		fmt.Fscan(reader, &k)
		li[i] = make([]int, k)
		for j := 0; j < k; j++ {
			fmt.Fscan(reader, &li[i][j])
		}
	}

	// Read input: pattern
	p := make([]int, m)
	pInput, _ := reader.ReadString('\n')
	pInput = strings.TrimSpace(pInput)
	pSlice := strings.Split(pInput, " ")
	for i := 0; i < m; i++ {
		p[i], _ = strconv.Atoi(pSlice[i])
	}

	// Create a set of all elements in the lists
	q := make(map[int]bool)
	for _, sublist := range li {
		for _, num := range sublist {
			q[num] = true
		}
	}

	// Create a set of numbers from 1 to n (excluding n)
	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		r[i] = true
	}

	// Find the set of numbers in r that are not in q
	v := make(map[int]bool)
	for num := range r {
		if !q[num] {
			v[num] = true
		}
	}

	// Initialize answer to 0
	ans := 0

	// Iterate through all possible subsets of q, from empty to the full set
	for i := 0; i <= len(q); i++ {
		// Iterate through all combinations of i elements from q
		for s := range combinations(q, i) {
			// Iterate through each list and pattern
			match := true
			for uIdx, u := range li {
				count := 0
				for _, num := range u {
					if s[num] {
						count++
					}
				}
				if count%2 != p[uIdx] {
					match = false
					break
				}
			}
			// If all combinations of lists and pattern match the current subset of q, increment the answer
			if match {
				ans += 1 << len(v)
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// Helper function to generate combinations
func combinations(set map[int]bool, n int) <-chan map[int]bool {
	ch := make(chan map[int]bool)
	go func() {
		defer close(ch)
		var helper func(start int, comb map[int]bool)
		helper = func(start int, comb map[int]bool) {
			if len(comb) == n {
				cpy := make(map[int]bool)
				for k, v := range comb {
					cpy[k] = v
				}
				ch <- cpy
				return
			}
			for i := start; i < len(set); i++ {
				comb[i] = true
				helper(i+1, comb)
				delete(comb, i)
			}
		}
		helper(0, make(map[int]bool))
	}()
	return ch
}
