
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Read three integers from the standard input
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(reader.ReadLine())
	b, _ := strconv.Atoi(reader.ReadLine())
	c, _ := strconv.Atoi(reader.ReadLine())

	// Sort the integers in ascending order
	numbers := []int{a, b, c}
	sort.Ints(numbers)

	// Print the sorted integers
	fmt.Println(numbers[0], numbers[1], numbers[2])
}

