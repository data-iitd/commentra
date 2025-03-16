
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Functions to read input more efficiently
func LI() []int {
	return []int{int(strconv.Atoi(strings.Split(string(os.Stdin.Read(1000000)), " ")[0]))}
}
func LI_() []int {
	return []int{int(strconv.Atoi(strings.Split(string(os.Stdin.Read(1000000)), " ")[0])) - 1}
}
func LF() []float64 {
	return []float64{float64(strconv.ParseFloat(strings.Split(string(os.Stdin.Read(1000000)), " ")[0], 64))}
}
func LS() []string {
	return strings.Split(string(os.Stdin.Read(1000000)), " ")
}
func I() int {
	return int(strconv.Atoi(strings.Split(string(os.Stdin.Read(1000000)), " ")[0]))
}
func F() float64 {
	return float64(strconv.ParseFloat(strings.Split(string(os.Stdin.Read(1000000)), " ")[0], 64))
}
func S() string {
	return string(os.Stdin.Read(1000000))
}
func pf(s string) {
	fmt.Println(s)
}

// Main function to execute the program
func main() {
	s := S() // Read the input string
	k := I() // Read the integer k
	l := 0   // Initialize a counter for leading '1's
	for _, c := range s { // Loop through each character in the string
		if c != '1' { // Check if the character is not '1'
			break // Exit the loop if a non-'1' character is found
		}
		l += 1 // Increment the counter for each '1' found
	}
	if l >= k { // Check if the number of leading '1's is greater than or equal to k
		return 1 // Return 1 if true
	}
	return s[l] // Return the character at the position of the first non-'1' character
}

// Print the result of the main function
fmt.Println(main())

