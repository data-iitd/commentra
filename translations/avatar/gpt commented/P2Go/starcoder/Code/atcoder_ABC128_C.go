package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Combinations returns all possible combinations of size n from the set s
func Combinations(s []int, n int) [][]int {
	var comb [][]int
	for i := 0; i < len(s); i++ {
		if n == 1 {
			comb = append(comb, []int{s[i]})
		} else {
			for j := i; j < len(s); j++ {
				if s[j]!= s[i] {
					comb = append(comb, append([]int{s[i]}, Combinations(s[i+1:j], n-1)...))
				}
			}
		}
	}
	return comb
}

func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader)
	// Reading the values of n and m from input
	n, m := strings.Split(strings.TrimSpace(reader.ReadString()), " "), strings.Split(strings.TrimSpace(reader.ReadString()), " ")
	n, m = strconv.Atoi(n[0]), strconv.Atoi(m[0])
	// Reading m lists of integers, each containing values after the first element
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		li[i] = make([]int, n)
		for j := 0; j < n; j++ {
			li[i][j], _ = strconv.Atoi(strings.Split(strings.TrimSpace(reader.ReadString()), " ")[j+1])
		}
	}
	// Reading a tuple p from input
	p := make([]int, m)
	for i := 0; i < m; i++ {
		p[i], _ = strconv.Atoi(strings.Split(strings.TrimSpace(reader.ReadString()), " ")[i])
	}
	// Creating a set q that contains all unique elements from the lists in li
	q := make(map[int]bool)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			q[li[i][j]] = true
		}
	}
	// Creating a set r that contains all integers from 1 to n
	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		r[i] = true
	}
	// Finding the set of values v that are in r but not in q
	v := make(map[int]bool)
	for i := 1; i <= n; i++ {
		if _, ok := q[i];!ok {
			v[i] = true
		}
	}
	// Initializing the answer variable to count valid combinations
	ans := 0
	// Iterating over all possible sizes of combinations from the set q
	for i := 0; i <= len(q); i++ {
		// Generating combinations of size i from the set q
		for _, s := range Combinations(make([]int, 0, len(q)), i) {
			// Checking each list in li against the corresponding value in p
			for j := 0; j < m; j++ {
				if len(s)!= 0 && len(s)!= len(li[j]) {
					break
				}
				if len(s) == 0 {
					if p[j] == 0 {
						ans += 1
					}
					continue
				}
				if p[j] == 0 {
					continue
				}
				if len(s) == len(li[j]) {
					if len(s) == 1 {
						if _, ok := v[li[j][0]]; ok {
							if _, ok := s[0]; ok {
								ans += 1
							}
						}
					} else {
						if _, ok := v[li[j][0]]; ok {
							if _, ok := s[0]; ok {
								ans += 1
							}
						}
						if _, ok := v[li[j][len(s)-1]]; ok {
							if _, ok := s[len(s)-1]; ok {
								ans += 1
							}
						}
					}
				}
			}
		}
	}
	// Printing the final answer
	fmt.Println(ans)
}

