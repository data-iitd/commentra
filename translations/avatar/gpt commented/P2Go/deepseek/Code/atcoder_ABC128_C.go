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
	
	// Reading the values of n and m from input
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	
	// Reading m lists of integers, each containing values after the first element
	li := [][]int{}
	for i := 0; i < m; i++ {
		line, _ := reader.ReadString('\n')
		parts := strings.Split(strings.TrimSpace(line), " ")
		nums := []int{}
		for _, part := range parts[1:] {
			num, _ := strconv.Atoi(part)
			nums = append(nums, num)
		}
		li = append(li, nums)
	}
	
	// Reading a tuple p from input
	line, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(line), " ")
	p := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		p = append(p, num)
	}
	
	// Creating a set q that contains all unique elements from the lists in li
	q := map[int]bool{}
	for _, list := range li {
		for _, num := range list {
			q[num] = true
		}
	}
	
	// Creating a set r that contains all integers from 1 to n
	r := map[int]bool{}
	for i := 1; i <= n; i++ {
		r[i] = true
	}
	
	// Finding the set of values v that are in r but not in q
	v := map[int]bool{}
	for i := 1; i <= n; i++ {
		if !q[i] {
			v[i] = true
		}
	}
	
	// Initializing the answer variable to count valid combinations
	ans := 0
	
	// Iterating over all possible sizes of combinations from the set q
	for i := 0; i <= len(q); i++ {
		for s := range combinations(q, i) {
			// Checking each list in li against the corresponding value in p
			for uIdx, u := range li {
				count := 0
				for _, num := range u {
					if _, ok := s[num]; ok {
						count++
					}
				}
				if count%2 != p[uIdx] {
					break
				}
			} else {
				// If all checks passed, increment the answer by 2 raised to the power of the size of v
				ans += 1 << len(v)
			}
		}
	}
	
	// Printing the final answer
	fmt.Println(ans)
}

// Helper function to generate combinations
func combinations(set map[int]bool, size int) map[int]bool {
	result := map[int]bool{}
	var generate func(start int)
	generate = func(start int) {
		if len(result) == size {
			return
		}
		for i := start; i <= n; i++ {
			if !result[i] {
				result[i] = true
				generate(i + 1)
				delete(result, i)
			}
		}
	}
	generate(1)
	return result
}
