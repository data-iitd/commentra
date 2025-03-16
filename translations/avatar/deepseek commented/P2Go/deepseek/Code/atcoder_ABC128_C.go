package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	// Read the number of switches (n) and the number of bulbs (m)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())
	
	// Read the connections of switches for each bulb and store them in a slice (li)
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		k, _ := strconv.Atoi(scanner.Text())
		switches := make([]int, k)
		for j := 0; j < k; j++ {
			scanner.Scan()
			switches[j], _ = strconv.Atoi(scanner.Text())
		}
		li[i] = switches
	}
	
	// Read the pattern of on/off states for each bulb and store it in a slice (p)
	p := make([]int, m)
	for i := 0; i < m; i++ {
		scanner.Scan()
		p[i], _ = strconv.Atoi(scanner.Text())
	}
	
	// Create a set (q) containing all the switches from all the bulbs
	q := make(map[int]bool)
	for _, switches := range li {
		for _, switchID := range switches {
			q[switchID] = true
		}
	}
	
	// Create a set (r) containing all the switches from 1 to n
	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		r[i] = true
	}
	
	// Calculate the set (v) which contains the switches that are not connected to any bulb
	var v []int
	for i := 1; i <= n; i++ {
		if !q[i] {
			v = append(v, i)
		}
	}
	
	// Initialize the answer variable to count the number of valid configurations
	ans := 0
	
	// Iterate over all possible combinations of switches from q
	for i := 0; i <= len(q); i++ {
		for s := range combinations(q, i) {
			// Check if each combination satisfies the given pattern p
			valid := true
			for bulbIdx, switches := range li {
				count := 0
				for _, switchID := range switches {
					if s[switchID] {
						count++
					}
				}
				if count%2 != p[bulbIdx] {
					valid = false
					break
				}
			}
			if valid {
				// If a combination satisfies the pattern, increment the answer by 2^len(v)
				ans += 1 << len(v)
			}
		}
	}
	
	// Print the total number of valid configurations
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
				cp := make(map[int]bool)
				for k, v := range comb {
					cp[k] = v
				}
				ch <- cp
				return
			}
			for i := start; i <= len(set); i++ {
				if _, ok := comb[i]; !ok {
					comb[i] = true
					helper(i+1, comb)
					delete(comb, i)
				}
			}
		}
		helper(1, make(map[int]bool))
	}()
	return ch
}
