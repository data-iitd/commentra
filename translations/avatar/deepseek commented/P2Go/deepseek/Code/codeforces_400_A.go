package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single value from input
func value() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	result := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		result[i] = num
	}
	return result
}

// Function to read multiple values from input
func values() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	result := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		result[i] = num
	}
	return result
}

// Function to read a list of integers from input
func inlst() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Split(line, " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		result[i] = num
	}
	return result
}

// Function to read a list of integers from stdin
func inlsts() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Split(line, " ")
	result := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		result[i] = num
	}
	return result
}

// Function to read a single integer from input
func inp() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(line))
	return num
}

// Function to read a single integer from stdin
func inps() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(line))
	return num
}

// Function to read a single string from input
func instr() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read a list of strings from input
func stlst() []string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.Fields(line)
}

// Helper function to check if a grid of given dimensions can be formed
func help(a, b int, l []int) bool {
	tot := make([][]int, b)
	for i := 0; i < b; i++ {
		tot[i] = l[i*a : i*a+a]
	}
	for i := 0; i < a; i++ {
		sum := 0
		for j := 0; j < b; j++ {
			sum += tot[j][i]
		}
		if sum == b {
			return true
		}
	}
	return false
}

// Main solving function
func solve() {
	tot := []string{}
	x := instr()
	s := []int{}
	for _, i := range x {
		if i == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}
	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, fmt.Sprintf("%dx%d", 12/i, i))
			}
		}
	}
	fmt.Printf("%d ", len(tot))
	for _, pair := range tot {
		fmt.Printf("%s ", pair)
	}
	fmt.Println()
}

// Main execution block
func main() {
	numCases := inp()
	for i := 0; i < numCases; i++ {
		solve()
	}
}

