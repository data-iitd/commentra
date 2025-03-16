package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

// Function to read a line from standard input and remove trailing whitespace
func S() string {
	sc.Scan()
	return sc.Text()
}

// Function to read an integer from standard input
func I() int {
	num, _ := strconv.Atoi(S())
	return num
}

// Function to read a list of integers from standard input
func LI() []int {
	sc.Scan()
	nums := make([]int, 0)
	for _, num := range strings.Split(sc.Text(), " ") {
		n, _ := strconv.Atoi(num)
		nums = append(nums, n)
	}
	return nums
}

// Function to read a list of strings from standard input
func LS() []string {
	sc.Scan()
	return strings.Split(sc.Text(), " ")
}

func main() {
	// Read two integers from input
	nums := LI()
	a, b := nums[0], nums[1]

	// Check if the first integer 'a' is positive
	if a > 0 {
		fmt.Println("Positive") // Output 'Positive' if 'a' is greater than 0
	} else if a <= 0 && b >= 0 {
		fmt.Println("Zero") // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
	} else {
		// If 'a' is negative and 'b' is also negative
		if (a+b)%2 == 0 {
			fmt.Println("Negative") // Output 'Negative' if the sum of 'a' and 'b' is even
		} else {
			fmt.Println("Positive") // Output 'Positive' if the sum of 'a' and 'b' is odd
		}
	}
}
