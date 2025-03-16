
package main

import (
	"fmt"
	"strconv"
	"strings"
)

const (
	M = 1046527 // Define the size of the hash table
	L = 14      // Define the length of each string in the hash table
)

var H [M][L]string // Declare a 2D array named H as the hash table

func getChar(ch byte) int {
	// A helper function to convert a single character into its corresponding integer value
	if ch == 'A' {
		return 1
	} else if ch == 'C' {
		return 2
	} else if ch == 'G' {
		return 3
	} else if ch == 'T' {
		return 4
	}
	return 0
}

// A function to convert a string into an integer value
func getKey(str string) int {
	sum := 0
	p := 1
	for i := 0; i < len(str); i++ {
		sum += p * getChar(str[i])
		p *= 5
	}
	return sum
}

// A helper function to calculate the first hash index
func h1(key int) int {
	return key % M
}

// A helper function to calculate the second hash index
func h2(key int) int {
	return 1 + (key % (M - 1))
}

// A function to check if a string is already present in the hash table
func find(str string) bool {
	key := getKey(str) // Calculate the key for the given string
	i := 0
	// Iterate through the hash table until the string is found or the hash table is exhausted
	for {
		hash := (h1(key) + i*h2(key))%M
		if H[hash] == str {
			return true
		}
		// If the current index in the hash table is empty, insert the string and return
		if len(H[hash]) == 0 {
			return false
		}
		i++
	}
	return false
}

// A function to insert a string into the hash table
func insert(str string) {
	key := getKey(str) // Calculate the key for the given string
	i := 0
	// Iterate through the hash table until an empty index is found
	for {
		hash := (h1(key) + i*h2(key))%M
		if len(H[hash]) == 0 {
			H[hash] = str // Copy the string into the empty index
			return
		}
		i++
	}
}

func main() {
	var n int
	fmt.Scan(&n) // Read the number of operations

	for i := 0; i < M; i++ {
		H[i] = "" // Initialize the hash table with empty strings
	}

	for i := 0; i < n; i++ {
		var com, str string
		fmt.Scan(&com, &str) // Read a command and a string

		if com == "i" {
			// If the command is 'insert', insert the string into the hash table
			insert(str)
		} else {
			// If the command is 'find', check if the string is present in the hash table
			if find(str) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

