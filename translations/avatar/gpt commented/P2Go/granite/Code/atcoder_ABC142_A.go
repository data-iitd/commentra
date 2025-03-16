
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single integer from input
func nextInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	num, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}
	return num
}

// Function to read a list of integers from input
func nextInts() []int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	split := strings.Split(sc.Text(), " ")
	var nums []int
	for _, s := range split {
		num, err := strconv.Atoi(s)
		if err!= nil {
			panic(err)
		}
		nums = append(nums, num)
	}
	return nums
}

func main() {
	// Read the number of iterations or elements
	n := nextInt()

	// Initialize a counter for odd indices
	t := 0

	// Loop through the range of n
	for i := 0; i < n; i++ {
		// Check if the current index (i + 1) is odd
		if (i + 1)%2 == 1 {
			t++ // Increment the counter for odd indices
		}
	}

	// Calculate and print the ratio of odd indices to total elements
	fmt.Println(float64(t) / float64(n))
}

