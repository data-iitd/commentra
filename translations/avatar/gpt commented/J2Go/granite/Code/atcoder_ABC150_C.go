
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func permutation(list []string, target string, ans string) []string {
	// Base case: if the target string is of length 1 or less, add the current answer to the list
	if len(target) <= 1 {
		list = append(list, ans+target)
	} else {
		// Recursive case: iterate through each character in the target string
		for i := 0; i < len(target); i++ {
			// Recursively call permutation with the remaining characters and the current character added to the answer
			list = permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
		}
	}
	// Return the list of permutations
	return list
}

func main() {
	// Create a scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements to be processed
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize a 2D array to store input strings
	line := make([][]string, 2)
	for i := 0; i < 2; i++ {
		line[i] = make([]string, 1)
		// Read n strings from the user and concatenate them into the first column of the array
		for j := 0; j < n; j++ {
			scanner.Scan()
			line[i][0] += scanner.Text()
		}
	}

	// Create a string containing numbers from 1 to n
	number := ""
	for i := 1; i <= n; i++ {
		number += strconv.Itoa(i)
	}

	// List to hold all permutations of the number string
	listA := make([]string, 0)
	// Generate all permutations of the number string
	listA = permutation(listA, number, "")

	// Variable to hold the sum of indices based on matching permutations
	sum := 0
	// Iterate through each row of the input strings
	for j := 0; j < len(line); j++ {
		// Check each permutation against the input strings
		for i := 0; i < len(listA); i++ {
			// If a permutation matches the input string, adjust the sum based on the index
			if listA[i] == line[j][0] {
				if sum == 0 {
					sum += i // Add index if sum is initially zero
				} else {
					sum -= i // Subtract index if sum is not zero
				}
			}
		}
	}

	// Output the absolute value of the sum
	fmt.Println(strconv.Itoa(int(math.Abs(float64(sum)))))
}

