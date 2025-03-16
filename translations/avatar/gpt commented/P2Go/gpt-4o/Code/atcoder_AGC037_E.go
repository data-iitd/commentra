package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	var S string
	fmt.Scan(&S)

	// Initialize a flag to determine if we can use a shortcut for output
	aaaa := false

	// Check if K is large enough or if 2^K is greater than or equal to N
	if K >= 15 {
		aaaa = true
	} else if int(math.Pow(2, float64(K))) >= N {
		aaaa = true
	}

	// If the shortcut condition is met, print the minimum character repeated N times and exit
	if aaaa {
		minChar := string(min(S))
		fmt.Println(strings.Repeat(minChar, N))
		return
	}

	// Get the lexicographically smallest rotation of the string
	S = getLastDict(S, N)

	// If K is 1, simply print the smallest rotation
	if K == 1 {
		fmt.Println(S)
		return
	}

	count := 0
	// Count how many times the first character appears consecutively
	for i := 0; i < N; i++ {
		if S[i] == S[0] {
			count++
		} else {
			break
		}
	}

	// Check if the repeated character can fill the string of length N
	if count*(int(math.Pow(2, float64(K-1)))) >= N {
		fmt.Println(strings.Repeat(string(S[0]), N))
	} else {
		// Construct the output string based on the count and the original string
		S = strings.Repeat(string(S[0]), count*(int(math.Pow(2, float64(K-1)))-1)) + S
		// Print the first N characters of the constructed string
		fmt.Println(S[:N])
	}
}

// Function to get the lexicographically smallest rotation of the string
func getLastDict(sStr string, N int) string {
	U := sStr + reverse(sStr)
	c := min(sStr)
	p := strings.Index(U, string(c))
	minIndex := p
	p++

	// Iterate through the doubled string to find the smallest rotation
	for p <= N {
		if U[p] == c {
			// Compare the current rotation with the previously found minimum
			if checkNormalDict(U, minIndex, p, N) {
				minIndex = p
			}
		}
		p++
	}

	// Return the smallest rotation of length N
	return U[minIndex:minIndex+N]
}

// Function to compare two rotations of the string
func checkNormalDict(u string, pointer1, pointer2, N int) bool {
	for i := 0; i < N; i++ {
		if u[pointer1+i] > u[pointer2+i] {
			return true
		} else if u[pointer1+i] < u[pointer2+i] {
			return false
		}
	}
	return false
}

// Function to find the minimum character in a string
func min(s string) byte {
	minChar := s[0]
	for i := 1; i < len(s); i++ {
		if s[i] < minChar {
			minChar = s[i]
		}
	}
	return minChar
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
