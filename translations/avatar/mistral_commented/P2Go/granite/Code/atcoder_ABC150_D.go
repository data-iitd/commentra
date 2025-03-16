
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Taking input of n and number of distinct numbers
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	inputSlice := strings.Split(input, " ")
	n, _ := strconv.Atoi(inputSlice[0])
	num, _ := strconv.Atoi(inputSlice[1])

	// Creating a set of distinct numbers
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	inputSlice = strings.Split(input, " ")
	numSet := make(map[int]bool)
	for _, numStr := range inputSlice {
		numInt, _ := strconv.Atoi(numStr)
		numSet[numInt] = true
	}

	// Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
	twoTimesSet := make(map[int]bool)
	for num := range numSet {
		// Initializing a counter to keep track of the number of times 2 is divided
		powerOfTwo := 0

		// Dividing num by 2 repeatedly until it is no longer odd
		for num%2 == 0 {
			powerOfTwo++
			num /= 2
		}

		// If the number of times 2 is divided is not exactly 1, then the answer is 0
		if powerOfTwo > 1 {
			fmt.Println(0)
			return
		}

		// Add the power of 2 to two_times_set
		twoTimesSet[powerOfTwo] = true
	}

	// If the size of two_times_set is not exactly 1, then the answer is 0
	if len(twoTimesSet)!= 1 {
		fmt.Println(0)
		return
	}

	// Finding the least common multiple of all numbers in num_set
	lcm := 1
	for num := range numSet {
		lcm *= num
	}

	// Printing the answer
	fmt.Println((num - lcm/2) / lcm + 1)
}
