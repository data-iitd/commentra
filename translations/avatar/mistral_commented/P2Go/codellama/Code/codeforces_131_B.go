// Import necessary packages
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input from standard input
func input() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to convert string to integer
func strToInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

// Function to convert string to integer slice
func strToIntSlice(s string) []int {
	split := strings.Split(s, " ")
	intSlice := make([]int, len(split))
	for i, v := range split {
		intSlice[i] = strToInt(v)
	}
	return intSlice
}

// Function to count occurrences of numbers
func countOccurrences(s []int) map[int]int {
	m := make(map[int]int)
	for _, v := range s {
		m[v]++
	}
	return m
}

// Function to calculate the result
func calculate(m map[int]int) int {
	c := 0
	for i, v := range m {
		if i == 0 {
			c += v * (v - 1)
		} else if -i in m {
			c += v * m[-i]
		}
	}
	return c
}

// Main function
func main() {
	// Read the number of test cases
	n := strToInt(input())

	// Initialize a Counter object 'w' to store the occurrences of numbers
	w := countOccurrences(strToIntSlice(input()))

	// Initialize a counter 'c' to store the result
	c := calculate(w)

	// Print the result divided by 2
	fmt.Println(c / 2)
}

