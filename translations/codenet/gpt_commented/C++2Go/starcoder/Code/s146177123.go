package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read input until a negative number is encountered
func main() {
	var n, t int
	var st [7]bool

	// Read input until a negative number is encountered
	for {
		if _, err := fmt.Scanf("%d", &n); err!= nil {
			break
		}

		// Process each digit input
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &t)

			// Determine the segment states based on the input digit
			ans := make([]string, 7)
			for j := 0; j < 7; j++ {
				ans[j] = fmt.Sprintf("%d", st[j]^seg[t][j])
				st[j] = seg[t][j]
			}
			fmt.Println(strings.Join(ans, ""))
		}
	}
}

// Segment representation for digits 0-9
var seg = [][]bool{
	{false, true, true, true, true, true, true}, // 0
	{false, false, false, false, true, true, false}, // 1
	{true, false, true, true, false, true, true}, // 2
	{true, false, false, true, true, true, true}, // 3
	{true, true, false, false, true, true, false}, // 4
	{true, true, false, true, true, false, true}, // 5
	{true, true, true, true, true, false, true}, // 6
	{false, true, false, false, true, true, true}, // 7
	{true, true, true, true, true, true, true}, // 8
	{true, true, false, true, true, true, true}, // 9
}

