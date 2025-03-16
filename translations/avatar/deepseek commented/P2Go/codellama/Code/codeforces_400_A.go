package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single value from input
func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read multiple values from input
func values() (int, int, int) {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	return a, b, c
}

// Function to read a list of integers from input
func inlst() []int {
	var s string
	fmt.Scan(&s)
	var lst []int
	for _, i := range strings.Split(s, " ") {
		lst = append(lst, mustInt(i))
	}
	return lst
}

// Function to read a list of integers from stdin
func inlsts() []int {
	var s string
	fmt.Scan(&s)
	var lst []int
	for _, i := range strings.Split(s, " ") {
		lst = append(lst, mustInt(i))
	}
	return lst
}

// Function to read a single integer from input
func inp() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single integer from stdin
func inps() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single string from input
func instr() string {
	var a string
	fmt.Scan(&a)
	return a
}

// Function to read a list of strings from input
func stlst() []string {
	var s string
	fmt.Scan(&s)
	var lst []string
	for _, i := range strings.Split(s, " ") {
		lst = append(lst, i)
	}
	return lst
}

// Helper function to check if a grid of given dimensions can be formed
func help(a, b int, l []int) bool {
	tot := make([][]int, b)
	for i := 0; i < b; i++ {
		tot[i] = l[i*a : i*a+a]
	}
	for _, i := range tot {
		if sum(i) == b {
			return true
		}
	}
	return false
}

// Main solving function
func solve() {
	tot := [][]int{}
	x := instr()
	s := []int{}
	for _, i := range x {
		if i == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}
	for i := 1; i < 13; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, []int{12 / i, i})
			}
		}
	}
	fmt.Println(len(tot))
	for _, i := range tot {
		fmt.Printf("%dx%d ", i[0], i[1])
	}
	fmt.Println()
}

// Main execution block
func main() {
	for i := 0; i < inp(); i++ {
		solve()
	}
}

