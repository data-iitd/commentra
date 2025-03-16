package main

import (
	"fmt"
	"strings"
)

const M = 1046527 // Size of the hash table
const L = 14      // Maximum length of strings to be stored in the hash table

var H [M]string // Hash Table to store strings

// Function to convert a character to a corresponding integer value
func getChar(ch rune) int {
	switch ch {
	case 'A':
		return 1 // A maps to 1
	case 'C':
		return 2 // C maps to 2
	case 'G':
		return 3 // G maps to 3
	case 'T':
		return 4 // T maps to 4
	default:
		return 0 // Return 0 for any other character
	}
}

// Convert a string into a unique integer key using a polynomial rolling hash
func getKey(str string) int64 {
	var sum int64 = 0
	var p int64 = 1 // Initialize power
	for _, ch := range str {
		sum += p * int64(getChar(ch)) // Update sum with the character's value
		p *= 5                          // Increase power of 5 for the next character
	}
	return sum // Return the computed key
}

// Hash function h1: Computes the primary hash index
func h1(key int64) int {
	return int(key % int64(M))
}

// Hash function h2: Computes the secondary hash index for collision resolution
func h2(key int64) int {
	return 1 + int(key%(int64(M)-1))
}

// Function to find a string in the hash table
func find(str string) bool {
	key := getKey(str) // Get the key for the string
	i := 0             // Initialize index for probing
	for {
		// Compute the hash index using double hashing
		hash := (h1(key) + i*h2(key)) % M
		if H[hash] == str {
			return true // String found
		} else if H[hash] == "" {
			return false // Empty slot indicates string not found
		}
		i++ // Increment index for next probe
	}
}

// Function to insert a string into the hash table
func insert(str string) bool {
	key := getKey(str) // Get the key for the string
	i := 0             // Initialize index for probing
	for {
		// Compute the hash index using double hashing
		hash := (h1(key) + i*h2(key)) % M
		if H[hash] == str {
			return true // String already exists
		} else if H[hash] == "" { // If the slot is empty
			H[hash] = str // Insert the string
			return false  // Insertion successful
		}
		i++ // Increment index for next probe
	}
}

func main() {
	var n int
	var str string
	var com string

	// Read the number of commands
	fmt.Scan(&n)

	// Process each command
	for i := 0; i < n; i++ {
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

// <END-OF-CODE>
