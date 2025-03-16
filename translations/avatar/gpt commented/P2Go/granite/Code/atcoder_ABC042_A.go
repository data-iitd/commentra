
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read a line of input, split it into components, and convert each component to an integer, storing them in a slice
	ABC := make([]int, 3)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	components := strings.Split(scanner.Text(), " ")
	for i, component := range components {
		value, _ := strconv.Atoi(component)
		ABC[i] = value
	}

	// Check if the number 5 appears exactly twice in the slice
	count := 0
	for _, value := range ABC {
		if value == 5 {
			count++
		}
	}
	if count == 2 {
		// If 5 appears twice, check if the sum of the numbers in the slice equals 17
		sum := 0
		for _, value := range ABC {
			sum += value
		}
		if sum == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		// If 5 does not appear exactly twice, print 'NO'
		fmt.Println("NO")
	}
}
