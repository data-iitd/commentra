package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single value as a tuple
func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}

// Function to read multiple values as a tuple
func values() (int, int) {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])
	return a, b
}

// Function to read a single value as a list
func inlst() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	lst := make([]int, len(parts))
	for i, part := range parts {
		lst[i], _ = strconv.Atoi(part)
	}
	return lst
}

// Function to read multiple values as a list
func inlsts() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	lst := make([]int, len(parts))
	for i, part := range parts {
		lst[i], _ = strconv.Atoi(part)
	}
	return lst
}

// Function to read a single value as an integer
func inp() int {
	var a int
	fmt.Scan(&a)
	return a
}

// Function to read a single value as an integer from stdin
func inps() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	a, _ := strconv.Atoi(strings.TrimSpace(line))
	return a
}

// Function to read a single line as a string
func instr() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a list of strings
func stlst() []string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.Fields(line)
}

// Helper function to check if a sub-array of given size exists in a list
func help(a, b int, l []int) bool {
	tot := [][]int{}
	for i := 0; i < b; i++ {
		tot = append(tot, l[i*a:i*a+a])
	}
	for i := 0; i < a; i++ {
		sum := 0
		for j := 0; j < len(tot); j++ {
			sum += tot[j][i]
		}
		if sum == b {
			return true
		}
	}
	return false
}

// Main function to solve the problem
func solve() {
	x := instr()
	s := []int{}
	for _, i := range x {
		if i == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}

	tot := []struct {
		a, b int
	}{}
	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, struct {
					a, b int
				}{12 / i, i})
			}
		}
	}

	fmt.Print(len(tot), " ")
	for _, pair := range tot {
		fmt.Printf("%dx%d ", pair.a, pair.b)
	}
	fmt.Println()
}

// Main function to run the code
func main() {
	for i := inp(); i > 0; i-- {
		solve()
	}
}

// <END-OF-CODE>
