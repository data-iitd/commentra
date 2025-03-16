package main

import (
	"fmt"
	"strings"
)

const M = 1046527
const L = 14

var H [M][L]byte

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

func getKey(str string) int {
	sum := 0
	p := 1
	for i := 0; i < len(str); i++ {
		sum += p * getChar(str[i])
		p *= 5
	}
	return sum
}

func h1(key int) int {
	return key % M
}

func h2(key int) int {
	return 1 + (key % (M - 1))
}

func find(str string) bool {
	key := getKey(str)
	i := 0
	for {
		hash := (h1(key) + i*h2(key)) % M
		if string(H[hash][:]) == str {
			return true
		}
		if len(H[hash]) == 0 {
			return false
		}
		i++
	}
}

func insert(str string) {
	key := getKey(str)
	i := 0
	for {
		hash := (h1(key) + i*h2(key)) % M
		if len(H[hash]) == 0 {
			copy(H[hash][:], str)
			return
		}
		i++
	}
}

func main() {
	var n int
	var com, str string
	for i := 0; i < M; i++ {
		H[i] = [L]byte{}
	}

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&com, &str)

		if com == "insert" {
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

