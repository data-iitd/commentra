package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first pair of integers (a and at) from the user input
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	at, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Read the second pair of integers (b and bt) from the user input
	b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	bt, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"
	t1, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	t2, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

