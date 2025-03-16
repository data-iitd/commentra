package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the first line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string to an integer
	N, err := strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		panic(err)
	}
	// Read the second line of input
	line, err = reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string to an integer
	K, err := strconv.Atoi(strings.TrimSpace(line))
	if err!= nil {
		panic(err)
	}
	// Read the third line of input
	line, err = reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}
	// Convert the string to a slice of runes
	S := []rune(strings.TrimSpace(line))
	// Initialize a flag to track changes and a count for 'R' occurrences
	flag := false
	count := 0
	// First pass: Change 'L' to 'R' up to K times
	for i := 0; i < N; i++ {
		// If the flag is set and the current character is 'R', increment count and reset flag
		if flag && S[i] == 'R' {
			flag = false
			count++
		}
		// Break the loop if K changes have been made
		if count == K {
			break
		}
		// If the current character is 'L', set the flag and change 'L' to 'R'
		if S[i] == 'L' {
			flag = true
			S[i] = 'R'
		}
	}
	// Reset flag and count for the second pass
	flag = false
	count = 0
	// Second pass: Change 'R' to 'L' up to K times
	for i := 0; i < N; i++ {
		// If the flag is set and the current character is 'L', increment count and reset flag
		if flag && S[i] == 'L' {
			flag = false
			count++
		}
		// Break the loop if K changes have been made
		if count == K {
			break
		}
		// If the current character is 'R', set the flag and change 'R' to 'L'
		if S[i] == 'R' {
			flag = true
			S[i] = 'L'
		}
	}
	// Initialize variables to count consecutive characters in S1
	count = 1
	sum1 := 0
	bef := S[0]
	// Count the number of consecutive characters in S1
	for i := 1; i < N; i++ {
		if S[i] == bef {
			count++
			// If it's the last character, add the count to sum1
			if i == N-1 {
				sum1 += count - 1
			}
		} else {
			bef = S[i]
			sum1 += count - 1
			count = 1
		}
	}
	// Reset count and initialize variables to count consecutive characters in S3
	count = 1
	sum3 := 0
	bef = S[0]
	// Count the number of consecutive characters in S3
	for i := 1; i < N; i++ {
		if S[i] == bef {
			count++
			// If it's the last character, add the count to sum3
			if i == N-1 {
				sum3 += count - 1
			}
		} else {
			bef = S[i]
			sum3 += count - 1
			count = 1
		}
	}
	// Output the maximum of the two sums calculated from S1 and S3
	fmt.Println(max(sum1, sum3))
}

// max returns the larger of its 2 arguments
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

