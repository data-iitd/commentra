
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Read two integers from input: n (an upper limit) and num (a number to be processed)
	var n, num int
	fmt.Scan(&n, &num)

	// Read a set of integers from input and convert them to a set to ensure uniqueness
	numSet := make(map[int]bool)
	var input string
	fmt.Scan(&input)
	for _, v := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(v)
		numSet[num] = true
	}

	// Initialize an empty set to store values related to the two times condition
	twoTimesSet := make(map[int]bool)

	// Iterate through each number in the unique set
	for i := range numSet {
		// Check how many times the number can be divided by 2
		for j := 1; j < 30; j++ {
			i /= 2 // Divide the number by 2
			if i%2 != 0 { // Check if the result is odd
				twoTimesSet[j] = true // Add the count of divisions to the set
				break // Exit the inner loop if an odd number is found
			}
		}

		// If more than one unique count of divisions by 2 is found, print 0 and exit
		if len(twoTimesSet) != 1 {
			fmt.Println(0)
			return
		}
	}

	// If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
	numList := make([]int, 0, len(numSet))
	for i := range numSet {
		numList = append(numList, i)
	}
	lcm := numList[0] // Initialize LCM with the first element of the list

	// Calculate the LCM of all numbers in the list
	for i := 1; i < len(numList); i++ {
		lcm = lcm * numList[i] / int(math.GCD(float64(lcm), float64(numList[i]))) // Update LCM using the GCD
	}

	// Calculate and print the final result based on the LCM and the input number
	fmt.Println((num - lcm / 2) / lcm + 1)
}

