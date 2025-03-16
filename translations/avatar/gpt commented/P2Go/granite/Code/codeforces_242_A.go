
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values for x, y, a, and b and convert them to integers
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	values := strings.Split(input, " ")
	x, _ := strconv.Atoi(values[0])
	y, _ := strconv.Atoi(values[1])
	a, _ := strconv.Atoi(values[2])
	b, _ := strconv.Atoi(values[3])

	// Initialize an empty slice to store valid game pairs
	games := make([][]int, 0)

	// Iterate over the range from a to x (inclusive)
	for i := a; i <= x; i++ {
		// Skip the iteration if i is less than or equal to b
		if i <= b {
			continue
		} else {
			// Iterate over the range from b to y (inclusive)
			for j := b; j <= y; j++ {
				// Check if the current i is greater than j
				if i > j {
					// If the condition is met, append the pair [i, j] to the games slice
					games = append(games, []int{i, j})
				}
			}
		}
	}

	// Print the total number of valid game pairs found
	fmt.Println(len(games))

	// Print each valid game pair
	for _, pair := range games {
		fmt.Printf("%d %d\n", pair[0], pair[1])
	}
}
