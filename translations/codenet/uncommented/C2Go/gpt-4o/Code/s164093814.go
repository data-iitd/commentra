package main

import (
	"fmt"
	"strings"
)

const M = 1046527 // your task
const L = 14

var H [M]string // Hash Table

func getChar(ch rune) int {
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

// convert a string into an integer value
func getKey(str string) int64 {
	var sum int64 = 0
	var p int64 = 1
	for _, ch := range str {
		sum += p * int64(getChar(ch))
		p *= 5
	}
	return sum
}

func h1(key int64) int {
	return int(key % int64(M))
}

func h2(key int64) int {
	return 1 + int(key%(int64(M)-1))
}

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
