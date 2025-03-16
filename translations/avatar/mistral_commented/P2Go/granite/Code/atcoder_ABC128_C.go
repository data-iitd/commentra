
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input: number of test cases, number of lists, and the lists themselves
	var n, m int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &m)
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		var k int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &k)
		li[i] = make([]int, k)
		for j := 0; j < k; j++ {
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &li[i][j])
		}
	}

	// Read input: pattern
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &p[i])
	}

	// Create a set of all elements in the lists
	q := make(map[int]bool)
	for _, v := range li {
		for _, w := range v {
			q[w] = true
		}
	}

	// Create a set of numbers from 1 to n (excluding n)
	r := make(map[int]bool)
	for i := 1; i < n; i++ {
		r[i] = true
	}

	// Find the set of numbers in r that are not in q
	v := make(map[int]bool)
	for k := range r {
		if!q[k] {
			v[k] = true
		}
	}

	// Initialize answer to 0
	ans := 0

	// Iterate through all possible subsets of q, from empty to the full set
	for i := 0; i <= len(q); i++ {
		// Iterate through all combinations of i elements from q
		for s := range combinations(q, i) {
			// Iterate through each list and pattern
			for _, u := range li {
				// Convert s to a set
				sSet := make(map[int]bool)
				for k := range s {
					sSet[k] = true
				}
				// Check if the current combination of lists and pattern match the current subset of q
				if count(sSet, u)%2!= p[i] {
					// If not, break out of the inner loop and move on to the next combination
					break
				}
			}
			// If all combinations of lists and pattern match the current subset of q, increment the answer
			else {
				ans += pow(2, len(v))
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

func combinations(s map[int]bool, k int) chan map[int]bool {
	c := make(chan map[int]bool)
	go func() {
		defer close(c)
		var keys []int
		for k := range s {
			keys = append(keys, k)
		}
		for i := 0; i < len(keys); i++ {
			for j := i; j < len(keys); j++ {
				if j-i+1 == k {
					m := make(map[int]bool)
					for _, v := range keys[i : j+1] {
						m[v] = true
					}
					c <- m
				}
			}
		}
	}()
	return c
}

func count(s map[int]bool, a []int) int {
	c := 0
	for _, v := range a {
		if s[v] {
			c++
		}
	}
	return c
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	} else if n%2 == 0 {
		return pow(x*x, n/2)
	} else {
		return x * pow(x*x, n/2)
	}
}

// End of code