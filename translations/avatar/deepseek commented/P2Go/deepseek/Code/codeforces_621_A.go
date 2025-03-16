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
	line, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(line))

	line, _ = reader.ReadString('\n')
	lstStr := strings.Fields(line)
	lst := make([]int, n)
	for i := 0; i < n; i++ {
		lst[i], _ = strconv.Atoi(lstStr[i])
	}

	// Sort the list in ascending order and then reverse to get descending order
	sort.Slice(lst, func(i, j int) bool {
		return lst[i] > lst[j]
	})

	// Initialize a counter for odd numbers
	od := 0
	for _, i := range lst {
		if i%2 != 0 {
			od++
		}
	}

	// Initialize sum to accumulate the result
	sum := 0
	ok := false // Initialize a flag to track if an odd number has been added

	// Iterate through the list to process each number
	for _, i := range lst {
		if i%2 == 0 {
			sum += i // Add even numbers to sum
		} else {
			if ok || od > 1 {
				sum += i // Add odd number to sum
				od--     // Decrement the count of odd numbers
				ok = !ok  // Toggle the flag
			}
		}
	}

	fmt.Println(sum) // Print the final sum
}
