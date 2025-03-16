
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object for input
	sc := NewScanner(os.Stdin)

	// Read the number of positions (n) and the target position (goal)
	n, _ := strconv.Atoi(sc.Next())
	goal, _ := strconv.Atoi(sc.Next())

	// Initialize an array to hold the teleportation values
	arr := make([]int, n-1)

	// Populate the array with teleportation values from input
	for i := 0; i < n-1; i++ {
		arr[i], _ = strconv.Atoi(sc.Next())
	}

	// Call the DFS function starting from position 1 to check if the goal can be reached
	isFound := dfs(1, arr, goal)

	// Output the result based on whether the goal was found
	if isFound {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// DFS method to determine if the target can be reached
func dfs(currpos int, arr []int, target int) bool {
	// Base case: if the current position equals the target, return true
	if currpos == target {
		return true
	}

	// Base case: if the current position exceeds the bounds of the array, return false
	if currpos == len(arr)+1 {
		return false
	}

	// Recursive case: attempt to teleport to the next position based on the current array value
	teleport := dfs(currpos+arr[currpos-1], arr, target)

	// If teleporting leads to the target, return true
	if teleport {
		return true
	}

	// If no valid path found, return false
	return false
}

// Scanner object to read input
type Scanner struct {
	scanner *bufio.Scanner
}

// NewScanner creates a new Scanner object
func NewScanner(input io.Reader) *Scanner {
	return &Scanner{scanner: bufio.NewScanner(input)}
}

// Next reads the next line of input
func (s *Scanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

// NextInt reads the next integer from input
func (s *Scanner) NextInt() int {
	i, _ := strconv.Atoi(s.Next())
	return i
}

// NextIntSlice reads the next slice of integers from input
func (s *Scanner) NextIntSlice() []int {
	s.scanner.Scan()
	return StringToIntSlice(s.scanner.Text())
}

// StringToIntSlice converts a string of integers to a slice of integers
func StringToIntSlice(s string) []int {
	s = strings.Trim(s, "[]")
	if s == "" {
		return nil
	}
	list := strings.Split(s, ",")
	result := make([]int, len(list))
	for i, item := range list {
		result[i], _ = strconv.Atoi(item)
	}
	return result
}

