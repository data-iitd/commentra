package main

import (
	"fmt"
	"strings"
)

const M = 1046527 // Size of the hash table
const L = 14      // Maximum length of strings

var H [M]string // Hash Table

// Convert a character to an integer value
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

// Convert a string into an integer value
func getKey(str string) int64 {
	var sum int64 = 0
	var p int64 = 1
	for i := 0; i < len(str); i++ {
		sum += p * int64(getChar(str[i]))
		p *= 5
	}
	return sum
}

// First hash function
func h1(key int64) int {
	return int(key % int64(M))
}

// Second hash function
func h2(key int64) int {
	return 1 + int(key%(int64(M)-1))
}

// Search for a string in the hash table
func find(str string) bool {
	key := getKey(str)
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

// Insert a string into the hash table
func insert(str string) bool {
	key := getKey(str)
	i := 0
	for {
		hash := (h1(key) + i*h2(key)) % M
		if H[hash] == str {
			return true
		} else if H[hash] == "" {
			H[hash] = str
			return false
		}
		i++
	}
}

// Main function to handle commands
func main() {
	var n int
	var str string
	var com string

	for i := 0; i < M; i++ {
		H[i] = ""
	}

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&com, &str)

		if com[0] == 'i' {
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

// <END-OF-CODE>
