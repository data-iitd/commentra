
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the list
	n, _ := strconv.Atoi(readLine())

	// Read the list of integers and count the occurrences of each integer
	w := make(map[int]int)
	for i := 0; i < n; i++ {
		s := readLine()
		x, _ := strconv.Atoi(s)
		w[x]++
	}

	// Initialize a variable to store the count of pairs
	c := 0

	// Iterate over each integer in the Counter object
	for i := range w {
		// If the integer is 0, calculate the number of ways to choose 2 items from the occurrences of 0
		if i == 0 {
			c += w[i] * (w[i] - 1)
		}
		// If the integer is not 0, check if its negative counterpart is also in the Counter
		else {
			if -i in w {
				// Calculate the number of ways to choose 2 items from the occurrences of i and -i
				c += w[i] * w[-i]
			}
		}
	}

	// Print the result of c // 2, which represents the number of unique pairs
	fmt.Println(c / 2)
}

func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// 