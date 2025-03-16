package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read two integers
	a, at := readInt()
	b, bt := readInt()

	// Read time in "HH:MM" format
	t1, t2 := readTime()

	// Calculate the start time by adjusting t1 by subtracting 5 hours and converting to minutes, then adding t2
	st := t2 + (t1 - 5) * 60

	// Calculate the finish time by adding at to the start time
	fin := st + at

	// Initialize now and ans variables
	now := 0
	ans := 0

	// Loop until now is less than fin and now is less than 1140
	for now < fin && now < 1140 {
		if now+bt > st {
			ans++
		}
		now += b
	}

	// Print the final value of ans
	fmt.Println(ans)
}

// readInt reads a single integer from stdin.
func readInt() (int, int) {
	var a, at int
	fmt.Scan(&a, &at)
	return a, at
}

// readTime reads a single time from stdin.
func readTime() (int, int) {
	var t1, t2 int
	fmt.Scan(&t1, &t2)
	return t1, t2
}

