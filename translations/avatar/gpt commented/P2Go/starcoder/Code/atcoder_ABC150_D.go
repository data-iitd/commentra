package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers from input: n (an upper limit) and num (a number to be processed)
	n, num := readTwoInts(bufio.NewReader(os.Stdin))

	// Read a set of integers from input and convert them to a set to ensure uniqueness
	numSet := readUniqueInts(bufio.NewReader(os.Stdin))

	// Initialize an empty set to store values related to the two times condition
	twoTimesSet := make(map[int]int)

	// Iterate through each number in the unique set
	for _, i := range numSet {
		// Check how many times the number can be divided by 2
		for j := 1; j < 30; j++ {
			i /= 2 // Divide the number by 2
			if i%2!= 0 { // Check if the result is odd
				twoTimesSet[j]++ // Add the count of divisions to the set
				break // Exit the inner loop if an odd number is found
			}
		}

		// If more than one unique count of divisions by 2 is found, print 0 and exit
		if len(twoTimesSet)!= 1 {
			fmt.Println(0)
			return
		}
	}

	// If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
	numList := make([]int, len(numSet)) // Convert the set back to a list for processing
	copy(numList, numSet)
	lcm := numList[0] // Initialize LCM with the first element of the list

	// Calculate the LCM of all numbers in the list
	for i := 1; i < len(numList); i++ {
		lcm = lcm * numList[i] / gcd(lcm, numList[i]) // Update LCM using the GCD

	}

	// Calculate and print the final result based on the LCM and the input number
	fmt.Println((num - lcm/2) / (lcm) + 1)
}

// readTwoInts reads two integers from input and returns them as a tuple
func readTwoInts(reader *bufio.Reader) (int, int) {
	// Read two integers from input
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	nums := strings.Split(line, " ")
	a, _ := strconv.Atoi(nums[0])
	b, _ := strconv.Atoi(nums[1])
	return a, b
}

// readUniqueInts reads a set of integers from input and returns them as a set
func readUniqueInts(reader *bufio.Reader) map[int]struct{} {
	// Read a set of integers from input and convert them to a set to ensure uniqueness
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	nums := strings.Split(line, " ")
	numSet := make(map[int]struct{})
	for _, num := range nums {
		numSet[atoi(num)] = struct{}{}
	}
	return numSet
}

// gcd calculates the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// atoi converts a string to an integer
func atoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

