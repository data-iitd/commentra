package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input from stdin
	input, _ := reader.ReadString('\n')
	// Convert the string to an integer
	N, _ := strconv.Atoi(strings.TrimSpace(input))
	// Read the next 5 lines of input from stdin
	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		input, _ := reader.ReadString('\n')
		A[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}
	// Find the minimum value in the list A
	min_value := A[0]
	for i := 1; i < 5; i++ {
		if A[i] < min_value {
			min_value = A[i]
		}
	}
	// Calculate the ceiling value of N divided by the minimum value in the list A
	ceiling_value := int(math.Ceil(float64(N) / float64(min_value)))
	// Add 4 to the ceiling value to get the final answer
	final_answer := ceiling_value + 4
	// Print the final answer
	fmt.Println(final_answer)
}

