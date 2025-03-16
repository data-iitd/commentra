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

	// Read the number of lists `n`
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize a counter `c` to 0
	c := 0

	// Loop `n` times to process each list of integers
	for i := 0; i < n; i++ {
		// Read a line of input, split it by spaces, convert them to integers, and store them in `l1`
		input, _ := reader.ReadString('\n')
		parts := strings.Fields(input)
		l1 := make([]int, len(parts))
		for j, part := range parts {
			num, _ := strconv.Atoi(part)
			l1[j] = num
		}

		// Calculate the sum of the elements in `l1`
		// If the sum is greater than 1, increment the counter `c` by 1
		sum := 0
		for _, num := range l1 {
			sum += num
		}
		if sum > 1 {
			c++
		}
	}

	// After the loop completes, print the final value of `c`
	fmt.Println(c)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
