package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to parse input data
func parser() chan string {
	data := make(chan string)
	go func() {
		for {
			// Read input and split it into a list of strings
			input := bufio.NewScanner(os.Stdin)
			input.Scan()
			data <- input.Text()
		}
	}()
	return data
}

// Function to get the next value from the input parser as a string
func gw(data chan string) string {
	return <-data
}

// Function to get the next value from the input parser and convert it to an integer
func gi(data chan string) int {
	i, _ := strconv.Atoi(<-data)
	return i
}

// Define a constant for the modulo operation
const MOD = int(1e9 + 7)

// Function to count the number of segments in the string S
func countSegments(S string) int {
	// Initialize a counter for segments
	seg_cnt := 0
	// Count the number of segments in the string S
	for i := 0; i < len(S) - 1; i++ {
		if S[i]!= S[i + 1] {
			seg_cnt += 1
	}
	return seg_cnt
}

// Function to calculate the current happiness based on the number of segments
func curHappy(N int, seg_cnt int) int {
	return N - 1 - seg_cnt
}

// Function to determine the final answer based on the relationship between K and seg_cnt
func finalAnswer(N int, K int, seg_cnt int) int {
	if 2 * K >= seg_cnt {
		return N - 1
	} else {
		return curHappy(N, seg_cnt) + 2 * K
	}
}

func main() {
	// Read the number of elements N and the integer K from input
	N := gi(parser())
	K := gi(parser())
	// Read the string S from input
	S := gw(parser())
	// Count the number of segments in the string S
	seg_cnt := countSegments(S)
	// Calculate the current happiness based on the number of segments
	cur_happy := curHappy(N, seg_cnt)
	// Determine the final answer based on the relationship between K and seg_cnt
	ans := finalAnswer(N, K, seg_cnt)
	// Print the final answer
	fmt.Println(ans)
}

