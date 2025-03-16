

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read two integers `n` and `k` from the standard input, separated by a space
	line, _ := reader.ReadString('\n')
	parts := strings.Split(line, " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	// Create a list of integers from the standard input, each line containing `n` integers
	var numbers []int
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		number, _ := strconv.Atoi(line)
		numbers = append(numbers, number)
	}

	// Sort the list in ascending order
	for i := 0; i < n; i++ {
		for j := 0; j < n-i-1; j++ {
			if numbers[j] > numbers[j+1] {
				numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
			}
		}
	}

	// Calculate the sum of the first `k` elements of the sorted list
	var result int
	for i := 0; i < k; i++ {
		result += numbers[i]
	}

	// Print the result
	fmt.Println(result)
}

