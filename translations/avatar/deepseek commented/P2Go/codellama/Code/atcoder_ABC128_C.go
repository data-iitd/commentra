package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the number of switches (n) and the number of bulbs (m)
	var n, m int
	fmt.Scan(&n, &m)

	// Read the connections of switches for each bulb and store them in a list (li)
	// Each element in li is a list of switches connected to a bulb, excluding the bulb itself
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		s := strings.Split(fmt.Scanln(), " ")
		li[i] = make([]int, len(s)-1)
		for j := 0; j < len(s)-1; j++ {
			li[i][j] = int(s[j])
		}
	}

	// Read the pattern of on/off states for each bulb and store it in a tuple (p)
	p := make([]int, m)
	fmt.Scan(&p)

	// Create a set (q) containing all the switches from all the bulbs
	q := make(map[int]bool)
	for _, u := range li {
		for _, v := range u {
			q[v] = true
		}
	}

	// Create a set (r) containing all the switches from 1 to n
	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		r[i] = true
	}

	// Calculate the set (v) which contains the switches that are not connected to any bulb
	v := make(map[int]bool)
	for i := 1; i <= n; i++ {
		if !q[i] {
			v[i] = true
		}
	}

	// Initialize the answer variable to count the number of valid configurations
	ans := 0

	// Iterate over all possible combinations of switches from q
	for i := 0; i <= len(q); i++ {
		for s := range combinations(q, i) {
			// Check if each combination satisfies the given pattern p
			for u, w := range p {
				if len(s&li[u])%2 != w {
					break
				}
			}
			// If a combination satisfies the pattern, increment the answer by 2^len(v)
			ans += 1 << len(v)
		}
	}

	// Print the total number of valid configurations
	fmt.Println(ans)
}

// combinations returns the combinations of a set to a specified length
func combinations(s map[int]bool, l int) map[int]bool {
	if l == 0 {
		return map[int]bool{0: true}
	}
	r := make(map[int]bool)
	for i := range s {
		for j := range combinations(s, l-1) {
			r[i|j] = true
		}
	}
	return r
}

