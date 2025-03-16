package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single value as a tuple
func value() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		val, _ := strconv.Atoi(part)
		result[i] = val
	}
	return result
}

// Function to read multiple values as a tuple
func values() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		val, _ := strconv.Atoi(part)
		result[i] = val
	}
	return result
}

// Function to read a single value as a list
func inlst() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		val, _ := strconv.Atoi(part)
		result[i] = val
	}
	return result
}

// Function to read multiple values as a list
func inlsts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		val, _ := strconv.Atoi(part)
		result[i] = val
	}
	return result
}

// Function to read a single value as an integer
func inp() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

// Function to read a single value as an integer from stdin
func inps() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

// Function to read a single line as a string
func instr() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to read a list of strings
func stlst() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	return parts
}

// Helper function to check if a sub-array of given size exists in a list
func help(a int, b int, l []int) bool {
	tot := [][]int{}
	for i := 0; i < b; i++ {
		sub := l[i*a : i*a+a]
		tot = append(tot, sub)
	}
	for _, row := range tot {
		sum := 0
		for _, val := range row {
			sum += val
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
	for _, char := range x {
		if char == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}

	tot := [][]int{}
	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, []int{12 / i, i})
			}
		}
	}

	fmt.Print(len(tot), " ")
	for _, pair := range tot {
		fmt.Printf("%dx%d ", pair[0], pair[1])
	}
	fmt.Println()
}

// Main function to run the code
func main() {
	numTests := inp()
	for i := 0; i < numTests; i++ {
		solve()
	}
}

