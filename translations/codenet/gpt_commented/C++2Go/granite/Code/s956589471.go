
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Declare variables to hold input values
	var a, b, c, d, e, k int

	// Read six integers from standard input
	for i := 0; i < 6; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		switch i {
		case 0:
			a = num
		case 1:
			b = num
		case 2:
			c = num
		case 3:
			d = num
		case 4:
			e = num
		case 5:
			k = num
		}
	}

	// Check if the difference between e and a is less than or equal to k
	// If true, print "Yay!", otherwise print ":("
	if e-a <= k {
		fmt.Println("Yay!")
	} else {
		fmt.Println(":(")
	}
}

