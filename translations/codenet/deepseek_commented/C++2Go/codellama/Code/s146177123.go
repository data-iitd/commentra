
package main

import (
	"fmt"
)

// Array to represent the segments of the digits 0-9
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

func main() {
	var n, t int
	for fmt.Scan(&n); n != 0; fmt.Scan(&n) {
		// Initialize the state array to represent the current display state
		st := make([]bool, 7)
		for i := 0; i < n; i++ {
			fmt.Scan(&t) // Read the next digit
			ans := make([]byte, 8)
			for i := 0; i < 7; i++ {
				// Calculate the current segment state and store it in the answer array
				ans[i] = byte(st[i] ^ seg[t][i])
				// Update the state array with the current segment state
				st[i] = seg[t][i]
			}
			// Output the current display state
			fmt.Println(string(ans))
		}
	}
}

