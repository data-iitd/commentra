
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input, split by space character, and convert each to an integer
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])

	// Find the minimum value between 'a' and 'b'
	minValue := int(math.Min(float64(a), float64(b)))

	// Find the maximum value between 'a' and 'b'
	maxValue := int(math.Max(float64(a), float64(b)))

	// Print the minimum value and the average of the difference between minimum and maximum values
	fmt.Println(minValue, int((float64(maxValue)-float64(minValue))/2))
}

