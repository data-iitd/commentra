<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read three integers from the standard input
	a, b, c := readThreeInts()

	// Check if the given condition is true
	if (100*a + 10*b + c) % 4 == 0 {
		// If the condition is true, print 'YES' to the standard output
		fmt.Println("YES")
	} else {
		// If the condition is false, print 'NO' to the standard output
		fmt.Println("NO")
	}
}

func readThreeInts() (int, int, int) {
	// Read three integers from the standard input
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	fmt.Fscan(reader, new(int), new(int), new(int))
	a, b, c := *new(int), *new(int), *new(int)
	fmt.Sscanf(strings.TrimSpace(string(*new(string))), "%d %d %d", &a, &b, &c)
=======
	fmt.Fscan(reader, new(int))
	fmt.Fscan(reader, new(int))
	fmt.Fscan(reader, new(int))

	// Return the three integers
>>>>>>> 98c87cb78a (data updated)
	return a, b, c
}

