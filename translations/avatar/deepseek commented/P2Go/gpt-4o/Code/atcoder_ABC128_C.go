package main

import (
	"fmt"
	"math/bits"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	// Read the connections of switches for each bulb
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		var k int
		fmt.Scan(&k)
		li[i] = make([]int, k-1)
		for j := 0; j < k-1; j++ {
			fmt.Scan(&li[i][j])
		}
	}

	// Read the pattern of on/off states for each bulb
	p := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&p[i])
	}

	// Create a set of all switches from all bulbs
	q := make(map[int]struct{})
	for _, switches := range li {
		for _, switchNum := range switches {
			q[switchNum] = struct{}{}
		}
	}

	// Create a set of all switches from 1 to n
	r := make(map[int]struct{})
	for i := 1; i <= n; i++ {
		r[i] = struct{}{}
	}

	// Calculate the set of switches that are not connected to any bulb
	v := make(map[int]struct{})
	for i := 1; i <= n; i++ {
		if _, exists := q[i]; !exists {
			v[i] = struct{}{}
		}
	}

	// Initialize the answer variable to count the number of valid configurations
	ans := 0

	// Iterate over all possible combinations of switches from q
	qKeys := make([]int, 0, len(q))
	for k := range q {
		qKeys = append(qKeys, k)
	}

	// Total combinations of switches
	totalCombinations := 1 << len(qKeys)

	for i := 0; i < totalCombinations; i++ {
		s := make(map[int]struct{})
		for j := 0; j < len(qKeys); j++ {
			if (i>>j)&1 == 1 {
				s[qKeys[j]] = struct{}{}
			}
		}

		// Check if each combination satisfies the given pattern p
		valid := true
		for u, w := range p {
			count := 0
			for _, switchNum := range li[u] {
				if _, exists := s[switchNum]; exists {
					count++
				}
			}
			if count%2 != w {
				valid = false
				break
			}
		}

		if valid {
			// If a combination satisfies the pattern, increment the answer by 2^len(v)
			ans += 1 << len(v)
		}
	}

	// Print the total number of valid configurations
	fmt.Println(ans)
}

// <END-OF-CODE>
