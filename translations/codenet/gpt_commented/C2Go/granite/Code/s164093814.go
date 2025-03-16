
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	M = 1046527 // Size of the hash table
	L = 14      // Maximum length of strings to be stored in the hash table
)

var H [M][L]byte // Hash Table to store strings

// Function to convert a character to a corresponding integer value
func getChar(ch byte) int {
	switch ch {
	case 'A':
		return 1
	case 'C':
		return 2
	case 'G':
		return 3
	case 'T':
		return 4
	}
	return 0
}

// Convert a string into a unique integer key using a polynomial rolling hash
func getKey(str string) int {
	sum, p := 0, 1
	for _, ch := range str {
		sum += p * getChar(ch) // Update sum with the character's value
		p *= 5                // Increase power of 5 for the next character
	}
	return sum
}

// Hash function h1: Computes the primary hash index
func h1(key int) int { return key % M }

// Hash function h2: Computes the secondary hash index for collision resolution
func h2(key int) int { return 1 + (key % (M - 1)) }

// Function to find a string in the hash table
func find(str string) bool {
	key := getKey(str) // Get the key for the string
	i := 0              // Initialize index for probing
	for {
		// Compute the hash index using double hashing
		hash := (h1(key) + i*h2(key)) % M
		if str == string(H[hash]) {
			return true // String found
		} else if len(H[hash]) == 0 {
			return false // Empty slot indicates string not found
		}
		i++ // Increment index for next probe
	}
}

// Function to insert a string into the hash table
func insert(str string) bool {
	key := getKey(str) // Get the key for the string
	i := 0              // Initialize index for probing
	for {
		// Compute the hash index using double hashing
		hash := (h1(key) + i*h2(key)) % M
		if str == string(H[hash]) {
			return true // String already exists
		} else if len(H[hash]) == 0 {
			copy(H[hash][:], str) // Insert the string
			return false // Insertion successful
		}
		i++ // Increment index for next probe
	}
}

func main() {
	var i, n int
	var str, com string

	// Initialize the hash table with empty strings
	for i = 0; i < M; i++ {
		H[i][0] = 0
	}

	// Read the number of commands
	fmt.Scan(&n)

	// Process each command
	for i = 0; i < n; i++ {
		fmt.Scan(&com, &str) // Read command and string

		// Check if the command is to insert a string
		if com[0] == 'i' {
			insert(str) // Insert the string into the hash table
		} else {
			// If the command is not insert, check if the string exists
			if find(str) {
				fmt.Println("yes") // String found
			} else {
				fmt.Println("no") // String not found
			}
		}
	}
}

// 