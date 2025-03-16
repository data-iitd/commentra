package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a, at int
	var b, bt int
	var t1, t2 int

	// Reading two integers
	fmt.Scan(&a, &at)
	fmt.Scan(&b, &bt)

	// Reading time in "HH:MM" format
	var timeStr string
	fmt.Scan(&timeStr)
	parts := strings.Split(timeStr, ":")
	t1, _ = strconv.Atoi(parts[0])
	t2, _ = strconv.Atoi(parts[1])

	// Calculate the start time by adjusting t1 by subtracting 5 hours and converting to minutes, then adding t2
	st := t2 + (t1 - 5) * 60

	// Calculate the finish time by adding at to the start time
	fin := st + at

	// Initialize now and ans variables
	now := 0
	ans := 0

	// Loop until now is less than fin and now is less than 1140
	for now < fin && now < 1140 {
		if now + bt > st { // Check if adding bt to now would exceed the start time
			ans += 1 // Increment ans if the condition is met
		}
		now += b // Increment now by b
	}

	// Print the final value of ans
	fmt.Println(ans)
}

