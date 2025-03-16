package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the number of elements N and the integer K from input
	var N, K int
	fmt.Scan(&N, &K)

	// Read the string S from input
	var S string
	fmt.Scan(&S)

	// Initialize a counter for segments
	segCnt := 0

	// Count the number of segments in the string S
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			segCnt++
		}
	}

	// Calculate the current happiness based on the number of segments
	curHappy := N - 1 - segCnt

	// Determine the final answer based on the relationship between K and segCnt
	var ans int
	if 2*K >= segCnt {
		ans = N - 1 // If K is sufficient to cover all segments
	} else {
		ans = curHappy + 2*K // Otherwise, calculate based on current happiness and K
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
