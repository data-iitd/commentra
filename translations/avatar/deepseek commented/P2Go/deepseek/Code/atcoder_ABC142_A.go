package main

import (
	"bufio"
	"fmt"
	"os"
)

func nextInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nums := []int{}
	scanner.Text()
	for _, num := range strings.Split(scanner.Text(), " ") {
		n, _ := strconv.Atoi(num)
		nums = append(nums, n)
	}
	return nums
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize a counter to keep track of odd numbers
	t := 0

	// Loop through each number from 0 to n-1
	for i := 0; i < n; i++ {
		// Check if the current index plus one is odd
		if (i + 1) % 2 != 0 {
			// Increment the counter if the condition is true
			t++
		}
	}

	// Calculate the ratio of odd numbers to the total numbers and print it
	fmt.Println(float64(t) / float64(n))
}
