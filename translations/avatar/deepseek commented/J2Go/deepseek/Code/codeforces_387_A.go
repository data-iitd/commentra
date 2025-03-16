package main

import (
	"fmt"
	"time"
)

func main() {
	// Step 1: Read two times from the user, split by colon and convert to LocalTime objects
	var s, t string
	fmt.Scan(&s, &t)

	// Split the input strings by colon
	sParts := strings.Split(s, ":")
	tParts := strings.Split(t, ":")

	// Convert the parts to integers and create LocalTime objects
	hour1, _ := strconv.Atoi(sParts[0])
	minute1, _ := strconv.Atoi(sParts[1])
	hour2, _ := strconv.Atoi(tParts[0])
	minute2, _ := strconv.Atoi(tParts[1])

	x := time.Date(0, 0, 0, hour1, minute1, 0, 0, time.UTC)
	y := time.Date(0, 0, 0, hour2, minute2, 0, 0, time.UTC)

	// Step 2: Calculate the difference between the two times
	difference := x.Sub(y)

	// Print the difference
	fmt.Println(difference)
}
