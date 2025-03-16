package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to read a single integer from input
func I() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	return parseInt(input)
}

// Function to read multiple integers from input and return them as a map
func MI() map[string]int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := scanner.Text()
	mapInt := make(map[string]int)
	for _, v := range strings.Split(inputs, " ") {
		mapInt[v] = parseInt(v)
	}
	return mapInt
}

// Function to read multiple integers from input and return them as a list
func LI() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := scanner.Text()
	listInt := []int{}
	for _, v := range strings.Split(inputs, " ") {
		listInt = append(listInt, parseInt(v))
	}
	return listInt
}

// Helper function to convert string to integer
func parseInt(s string) int {
	var result int
	for _, v := range s {
		result = result*10 + int(v-'0')
	}
	return result
}

func main() {
	// Define the modulo constant
	const mod = 1000000007

	// Read input values: N (total items), A (items of type A), B (items of type B)
	inputs := MI()
	N := inputs["N"]
	A := inputs["A"]
	B := inputs["B"]

	// Initialize the answer variable
	ans := 0

	// Calculate how many complete cycles of (A + B) fit into N
	rep := N / (A + B)

	// Add the total items of type A from the complete cycles to the answer
	ans += rep * A

	// Calculate the remaining items after complete cycles
	res := N - rep*(A+B)

	// Add the minimum of remaining items or A to the answer
	ans += min(res, A)

	// Print the final answer
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
