package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var MOD = int(1e9 + 7)

// Function to parse input line by line
func parser() <-chan string {
	ch := make(chan string)
	go func() {
		defer close(ch)
		scanner := bufio.NewScanner(os.Stdin)
		for scanner.Scan() {
			data := scanner.Text()
			for _, number := range split(data) {
				if len(number) > 0 {
					ch <- number
				}
			}
		}
	}()
	return ch
}

// Function to split a string by whitespace
func split(s string) []string {
	return bufio.NewScanner(strings.NewReader(s)).Split(bufio.ScanWords)
}

// Function to get the next token from the parser
func gw(ch <-chan string) string {
	return <-ch
}

// Function to get the next integer from the parser
func gi(ch <-chan string) int {
	data := gw(ch)
	num, _ := strconv.Atoi(data)
	return num
}

func main() {
	inputParser := parser()

	// Get the number of segments in the string
	N := gi(inputParser)

	// Get the number of queries
	K := gi(inputParser)

	// Get the string S
	S := gw(inputParser)

	// Initialize segment count
	segCnt := 0

	// Iterate through the string and count the number of segments
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			segCnt++
		}
	}

	// Calculate the current happiness
	curHappy := N - 1 - segCnt

	// Check if the number of queries is greater than or equal to the number of segments
	var ans int
	if 2*K >= segCnt {
		// If yes, then the answer is the total number of segments
		ans = N - 1
	} else {
		// Otherwise, the answer is the current happiness plus twice the number of queries
		ans = curHappy + 2*K
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
