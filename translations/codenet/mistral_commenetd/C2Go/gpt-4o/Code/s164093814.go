package main

import (
	"fmt"
	"strings"
)

const M = 1046527 // Define the size of the hash table
const L = 14      // Define the length of each string in the hash table

var H [M]string // Declare a slice named H as the hash table

// A helper function to convert a single character into its corresponding integer value
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
	default:
		return 0
	}
}

// A function to convert a string into an integer value
func getKey(str string) int64 {
	var sum int64 = 0
	var p int64 = 1
	for i := 0; i < len(str); i++ {
		sum += p * int64(getChar(str[i]))
		p *= 5
	}
	return sum
}

// A helper function to calculate the first hash index
func h1(key int64) int {
	return int(key % int64(M))
}

// A helper function to calculate the second hash index
func h2(key int64) int {
	return 1 + int(key%(int64(M)-1))
}

// A function to check if a string is already present in the hash table
func find(str string) bool {
	key := getKey(str) // Calculate the key for the given string
	i := 0
	for {
		hash := (h1(key) + i*h2(key)) % M
		if H[hash] == str {
			return true
		} else if H[hash] == "" {
			return false
		}
		i++
	}
}

// A function to insert a string into the hash table
func insert(str string) {
	key := getKey(str) // Calculate the key for the given string
	i := 0
	for {
		hash := (h1(key) + i*h2(key)) % M
		if H[hash] == "" {
			H[hash] = str // Copy the string into the empty index
			return
		}
		i++
	}
}

func main() {
	var n int
	var str string
	var com string

	// Initialize the hash table with empty strings
	for i := 0; i < M; i++ {
		H[i] = ""
	}

	fmt.Scan(&n) // Read the number of operations

	for i := 0; i < n; i++ {
		fmt.Scan(&com, &str) // Read a command and a string

		if com[0] == 'i' {
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

// <END-OF-CODE>
