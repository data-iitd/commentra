package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	var K int
	var S string
	var firstTime bool
	var step int

	// Read the input
	fmt.Scan(&N)
	fmt.Scan(&K)
	fmt.Scan(&S)

	// Initialize the flag and step size
	firstTime = true
	step = 1

	// Main loop to manipulate the string based on the value of K
	for K > 0 {
		// Create a copy of S
		T := S
		// Reverse the copy
		T = reverse(T)
		// Concatenate S with its reverse
		revU := S + T
		// Reverse the concatenated string
		revU = reverse(revU)
		// Initialize sDash with the original string S
		sDash := S

		// Iterate over the reversed concatenated string to find the best substring
		for i := N; i >= 0; i -= step {
			// Get a substring of length N
			tmp := revU[i : i+N]
			// Compare lexicographically
			if sDash > tmp {
				sDash = tmp
			} else {
				if !firstTime {
					break
				}
			}
		}

		// Check if it's the first time through the loop
		if firstTime {
			firstTime = false
			if math.Pow(2, float64(K)) > float64(N) {
				// Check the power of 2 of K
				c := sDash[0]
				// Get the first character of sDash
				for i := 0; i < N; i++ {
					// Print the character N times
					fmt.Print(string(c))
				}
				fmt.Println()
				os.Exit(0)
			}
		} else {
			step += step
		}
		K--
		S = sDash
		S = reverse(S)
	}
	fmt.Println(reverse(S))
}

// Reverse a string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Convert a string to an integer
func toInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

// Convert a string to a boolean
func toBool(s string) bool {
	b, _ := strconv.ParseBool(s)
	return b
}

// Convert a boolean to a string
func toString(b bool) string {
	return strconv.FormatBool(b)
}

// Convert an integer to a string
func toString2(i int) string {
	return strconv.Itoa(i)
}

// Convert a string to a slice of strings
func toSlice(s string) []string {
	return strings.Split(s, " ")
}

// Convert a slice of strings to a string
func toString3(ss []string) string {
	return strings.Join(ss, " ")
}

// Convert a slice of integers to a string
func toString4(si []int) string {
	res := ""
	for _, i := range si {
		res += strconv.Itoa(i) + " "
	}
	return strings.TrimRight(res, " ")
}

// Convert a string to a slice of integers
func toSlice2(s string) []int {
	si := strings.Split(s, " ")
	res := make([]int, len(si))
	for i, val := range si {
		res[i], _ = strconv.Atoi(val)
	}
	return res
}

// Convert a 2D slice of integers to a string
func toString5(s [][]int) string {
	res := ""
	for _, val := range s {
		res += toString4(val) + "\n"
	}
	return strings.TrimRight(res, "\n")
}

// Convert a string to a 2D slice of integers
func toSlice3(s string) [][]int {
	si := strings.Split(s, "\n")
	res := make([][]int, len(si))
	for i, val := range si {
		res[i] = toSlice2(val)
	}
	return res
}

// End of code
