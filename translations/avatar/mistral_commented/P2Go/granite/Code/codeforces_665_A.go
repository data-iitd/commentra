
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Define a function to map strings to integers
	mapStringToInt := func(s string) int {
		i, _ := strconv.Atoi(s)
		return i
	}

	// Read the first pair of integers (a and at) from the user input
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	a := mapStringToInt(parts[0])
	at := mapStringToInt(parts[1])

	// Read the second pair of integers (b and bt) from the user input
	scanner.Scan()
	line = scanner.Text()
	parts = strings.Split(line, " ")
	b := mapStringToInt(parts[0])
	bt := mapStringToInt(parts[1])

	// Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"
	scanner.Scan()
	line = scanner.Text()
	parts = strings.Split(line, ":")
	t1 := mapStringToInt(parts[0]) * 60 + mapStringToInt(parts[1])
	t2 := t1 + at

	// Calculate the start time in seconds
	st := t2 + (t1 - 5) * 60

	// Calculate the finish time in seconds
	fin := st + at

	// Initialize the current time to zero
	now := 0

	// Initialize the answer to zero
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

