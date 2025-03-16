package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single value from input
func value() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read multiple values from input
func values() []int {
	var x []int
	fmt.Scan(&x)
	return x
}

// Function to read a list of integers from input
func inlst() []int {
	var x []int
	fmt.Scan(&x)
	return x
}

// Function to read a list of integers from stdin
func inlsts() []int {
	var x []int
	fmt.Fscan(os.Stdin, &x)
	return x
}

// Function to read a single integer from input
func inp() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a single integer from stdin
func inps() int {
	var x int
	fmt.Fscan(os.Stdin, &x)
	return x
}

// Function to read a single string from input
func instr() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Function to read a list of strings from input
func stlst() []string {
	var x []string
	fmt.Scan(&x)
	return x
}

// Helper function to check if a grid of given dimensions can be formed
func help(a, b, l []int) bool {
	tot := make([]int, b)
	for i := 0; i < b; i++ {
		tot[i] = 0
		for j := 0; j < a; j++ {
			tot[i] += l[i*a+j]
		}
	}
	for i := 0; i < b; i++ {
		if tot[i] == b {
			return true
		}
	}
	return false
}

// Main solving function
func solve() {
	tot := make([][]int, 0)
	x := instr()
	s := make([]int, len(x))
	for i := 0; i < len(x); i++ {
		if x[i] == 'O' {
			s[i] = 0
		} else {
			s[i] = 1
		}
	}
	for i := 1; i < 13; i++ {
		if 12%i == 0 {
			if help(make([]int, i), 12/i, s) {
				tot = append(tot, []int{12/i, i})
			}
		}
	}
	fmt.Println(len(tot))
	for _, v := range tot {
		fmt.Printf("%dx%d ", v[0], v[1])
	}
	fmt.Println()
}

// Main execution block
func main() {
	for i := 0; i < inp(); i++ {
		solve()
	}
}

