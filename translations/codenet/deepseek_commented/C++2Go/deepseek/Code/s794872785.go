package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func solve() {
	// Initialize variables to track the longest string and its count
	var maxsize int
	var maxcnt int
	var ans_num int
	var ans_num2 int
	str_v := []string{} // Vector to store input strings

	// Variable to read input strings
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		in := scanner.Text()
		str_v = append(str_v, in) // Store the input string in the vector
		if maxsize < len(in) { // Check if the current string is the longest so far
			maxsize = len(in) // Update the length of the longest string
			ans_num = len(str_v) - 1 // Store the index of the longest string
		}
	}

	// Count occurrences of each string and find the most frequent string
	freqMap := make(map[string]int)
	for i := 0; i < len(str_v); i++ {
		freqMap[str_v[i]]++ // Increment the count for the current string
	}

	// Find the most frequent string
	var mostFrequent string
	maxcnt = 0
	for k, v := range freqMap {
		if v > maxcnt {
			maxcnt = v
			mostFrequent = k
			ans_num2 = i
		}
	}

	// Output the most frequent and the longest string
	fmt.Println(mostFrequent, str_v[ans_num])
}

func main() {
	solve()
}

