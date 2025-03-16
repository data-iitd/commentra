

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read two integers 'n' and 'd' from the standard input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	d, _ := strconv.Atoi(scanner.Text())

	// Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
	a := d*2 + 1

	// Use the ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
	// Print the result to the standard output
	fmt.Println(int(math.Ceil(float64(n) / float64(a))))
}

