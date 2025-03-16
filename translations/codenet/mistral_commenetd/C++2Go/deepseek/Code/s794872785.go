package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func solve() {
	// Initialize variables
	maxsize := 0
	maxcnt := 0
	ansNum := -1
	ansNum2 := -1
	strV := []string{} // Slice to store strings read from input

	// Read strings from input
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		in := scanner.Text()
		// Push the string into the slice
		strV = append(strV, in)
		// Update maxsize if the current string is larger
		if maxsize < len(in) {
			maxsize = len(in)
			ansNum = len(strV) - 1
		}
	}

	// Find the string with maximum occurrences in the slice
	sort.Strings(strV)
	for i := 0; i < len(strV); i++ {
		cnt := 0
		// Count the occurrences of the current string in the slice
		for j := 0; j < len(strV); j++ {
			if strV[i] == strV[j] {
				cnt++
			}
		}
		// Update maxcnt and ansNum2 if the current string has more occurrences
		if maxcnt < cnt {
			maxcnt = cnt
			ansNum2 = i
		}
	}

	// Print the answer
	fmt.Printf("%s %s\n", strV[ansNum2], strV[ansNum])
}

func main() {
	// Call the solve function
	solve()
}

