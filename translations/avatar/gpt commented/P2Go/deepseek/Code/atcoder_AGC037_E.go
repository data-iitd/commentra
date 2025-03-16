package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var N, K int
	var S string
	fmt.Scan(&N, &K)
	fmt.Scan(&S)

	aaaa := false

	if K >= 15 {
		aaaa = true
	} else if int(math.Pow(2, float64(K))) >= N {
		aaaa = true
	}

	if aaaa {
		minChar := strings.Min([]rune(S)[0], []rune(S)[0])
		result := strings.Repeat(string(minChar), N)
		fmt.Println(result)
		return
	}

	// Function to get the lexicographically smallest rotation of the string
	func getLastDict(sStr string) string {
		// Create a doubled string to facilitate rotation comparison
		U := sStr + sStr[len(sStr)-1::-1]
		// Find the minimum character in the original string
		c := min([]rune(sStr)[0], []rune(sStr)[0])
		// Get the first occurrence of the minimum character
		p := strings.Index(U, string(c))
		minindex := p
		p += 1
		
		// Iterate through the doubled string to find the smallest rotation
		for p <= N {
			if U[p] == c {
				// Compare the current rotation with the previously found minimum
				if checkNormalDict(U, minindex, p) {
					minindex = p
				}
			}
			p += 1
		}
		
		// Return the smallest rotation of length N
		return U[minindex:minindex + N]
	}

	// Function to compare two rotations of the string
	func checkNormalDict(u string, pointer1 int, pointer2 int) bool {
		// Compare characters of the two rotations
		for i := 0; i < N; i++ {
			if u[pointer1 + i] > u[pointer2 + i] {
				return true
			} else if u[pointer1 + i] < u[pointer2 + i] {
				return false
			}
		}
		return false
	}

	// Get the lexicographically smallest rotation of S
	S = getLastDict(S)

	// If K is 1, simply print the smallest rotation
	if K == 1 {
		fmt.Println(S)
	} else {
		count := 0
		// Count how many times the first character appears consecutively
		for _, c := range S {
			if c == []rune(S)[0] {
				count += 1
			} else {
				break
			}
		}
		
		// Check if the repeated character can fill the string of length N
		if count * (int(math.Pow(2, float64(K - 1)))) >= N {
			fmt.Println(strings.Repeat(string([]rune(S)[0]), N))
		} else {
			// Construct the output string based on the count and the original string
			S = strings.Repeat(string([]rune(S)[0]), count * (int(math.Pow(2, float64(K - 1))) - 1)) + S
			// Print the first N characters of the constructed string
			fmt.Println(S[:N])
		}
	}
}
