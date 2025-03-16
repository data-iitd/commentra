
package main

import (
	"fmt"
	"strconv"
)

const (
	M = 1046527 // Size of the hash table
	L = 14      // Maximum length of strings
)

var H [M][L]string // Hash Table

// Convert a character to an integer value
func getChar(ch byte) int {
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

// Convert a string into an integer value
func getKey(str string) int {
	sum := 0
	p := 1
	for i := 0; i < len(str); i++ {
		sum += p * getChar(str[i])
		p *= 5
	}
	return sum
}

// First hash function
func h1(key int) int {
	return key % M
}

// Second hash function
func h2(key int) int {
	return 1 + (key % (M - 1))
}

// Search for a string in the hash table
func find(str string) bool {
	key := getKey(str)
	i := 0
	for {
		hash := (h1(key) + i*h2(key))%M
		if H[hash] == str {
			return true
		} else if len(H[hash]) == 0 {
			return false
		}
		i++
	}
	return false
}

// Insert a string into the hash table
func insert(str string) bool {
	key := getKey(str)
	i := 0
	for {
		hash := (h1(key) + i*h2(key))%M
		if H[hash] == str {
			return true
		} else if len(H[hash]) == 0 {
			H[hash] = str
			return false
		}
		i++
	}
	return false
}

// Main function to handle commands
func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < M; i++ {
		H[i] = ""
	}

	for i := 0; i < n; i++ {
		var com, str string
		fmt.Scan(&com, &str)

		if com == "i" {
			insert(str)
		} else {
			if find(str) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

