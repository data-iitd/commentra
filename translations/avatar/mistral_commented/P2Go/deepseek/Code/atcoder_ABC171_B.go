package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers `n` and `k` from the standard input, separated by a space
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	// Read the list of integers from the standard input, each line containing `n` integers
	input, _ = reader.ReadString('\n')
	numbersStr := strings.Split(strings.TrimSpace(input), " ")
	numbers := make([]int, n)
	for i := 0; i < n; i++ {
		numbers[i], _ = strconv.Atoi(numbersStr[i])
	}

	// Sort the list in ascending order
	sort.Ints(numbers)

	// Calculate the sum of the first `k` elements of the sorted list
	result := 0
	for i := 0; i < k; i++ {
		result += numbers[i]
	}

	// Print the result
	fmt.Println(result)
}
