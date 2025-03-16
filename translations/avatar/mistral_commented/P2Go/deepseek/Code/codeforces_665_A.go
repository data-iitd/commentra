package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a, at int
	fmt.Scan(&a, &at)

	var b, bt int
	fmt.Scan(&b, &bt)

	var t1, t2 int
	var t1Str, t2Str string
	fmt.Scan(&t1Str, &t2Str)

	// Convert time strings to integers
	t1Hours, _ := strconv.Atoi(t1Str[:2])
	t1Minutes, _ := strconv.Atoi(t1Str[3:])
	t2Hours, _ := strconv.Atoi(t2Str[:2])
	t2Minutes, _ := strconv.Atoi(t2Str[3:])

	// Convert start and end times to seconds
	st := t2Hours*60 + t2Minutes + (t1Hours-5)*60
	fin := st + at

	now := 0
	ans := 0

	// Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
	for now < fin && now < 1140 {
		// If the next event starts after the current time, increment the answer
		if now+bt > st {
			ans++
		}
		// Increment the current time by the duration of the next event
		now += b
	}

	// Print the final answer
	fmt.Println(ans)
}

