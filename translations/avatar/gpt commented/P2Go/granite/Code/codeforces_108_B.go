
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an input line (not used in the logic)
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')

	// Read a line of integers, split by spaces, and convert them to a list of integers
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	a := make([]int, 0)
	for _, s := range strings.Split(input, " ") {
		i, _ := strconv.Atoi(s)
		a = append(a, i)
	}

	// Sort the list of integers in ascending order
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if a[i] > a[j] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}

	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is different from the previous one
		// and if it is less than double the previous element
		if a[i]!= a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, return 'YES'
			fmt.Println("YES")
			return
		}
	}

	// If no such pair is found, return 'NO'
	fmt.Println("NO")
}

