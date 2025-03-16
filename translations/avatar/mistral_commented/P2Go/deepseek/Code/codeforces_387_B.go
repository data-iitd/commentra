package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables n and m with the given input
	var n, m int
	fmt.Scan(&n, &m)

	// Initialize slices round_complexity and george_complexity
	// with the given input
	round_complexity := make([]int, n)
	george_complexity := make([]int, m)

	// Read the input for round_complexity
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	round_complexity_str := strings.Split(input, " ")
	for i := 0; i < n; i++ {
		round_complexity[i], _ = strconv.Atoi(round_complexity_str[i])
	}

	// Read the input for george_complexity
	scanner.Scan()
	input = scanner.Text()
	george_complexity_str := strings.Split(input, " ")
	for i := 0; i < m; i++ {
		george_complexity[i], _ = strconv.Atoi(george_complexity_str[i])
	}

	// Initialize variables i and j to 0
	i, j := 0, 0

	// Start the while loop that compares the complexity of each
	// round with George's complexity and moves the pointers accordingly
	for i < n && j < m {

		// Increment i if the complexity of the current round is
		// less than or equal to George's complexity at the current j
		if round_complexity[i] <= george_complexity[j] {
			i++
		}

		// Increment j
		j++
	}

	// Print the final answer
	fmt.Println(n - i)
}

