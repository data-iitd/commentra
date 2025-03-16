package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	// Define input variables
	var N, K int
	fmt.Scan(&N, &K)
	var S string
	fmt.Scan(&S)

	// Initialize a flag variable
	aaaa := false

	// Check if K is greater than or equal to 15
	if K >= 15 {
		// If so, set the flag variable to True
		aaaa = true
	} else if int(math.Pow(2, float64(K))) >= N {
		// Else, check if 2^K is greater than or equal to N
		aaaa = true
	}

	// If the flag variable is True, print the result and exit the function
	if aaaa {
		fmt.Println(strings.Repeat(string(minChar(S)), N))
		return
	}

	// Get the last dictionary of the string S
	S = getLastDict(S, N)

	// If K is equal to 1, print the string S
	if K == 1 {
		fmt.Println(S)
	} else {
		count := 0
		for i := 0; i < len(S); i++ {
			// If the current character is the same as the first character, increment the count
			if S[i] == S[0] {
				count++
			} else {
				break
			}
		}
		// If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
		if count*(int(math.Pow(2, float64(K-1)))) >= N {
			fmt.Println(strings.Repeat(string(S[0]), N))
		} else {
			// Else, construct the string S by concatenating N-1 instances of the first character with the original string S
			S = strings.Repeat(string(S[0]), count*(int(math.Pow(2, float64(K-1))))-1) + S
			// Print the first N characters of the constructed string S
			fmt.Println(S[:N])
		}
	}
}

// Function to get the last dictionary of the string S
func getLastDict(sStr string, N int) string {
	U := sStr + reverse(sStr)
	c := minChar(sStr)
	p := strings.Index(U, string(c))
	minindex := p
	p++

	for p <= len(U)-1 {
		if U[p] == c && checkNormalDict(U, minindex, p, N) {
			minindex = p
		}
		p++
	}
	return U[minindex:minindex+N]
}

// Function to check if a substring is a normal dictionary
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
func minChar(s string) byte {
	min := s[0]
	for i := 1; i < len(s); i++ {
		if s[i] < min {
			min = s[i]
		}
	}
	return min
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
