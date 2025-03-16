package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the first line of input and split it to get values for 'a' and 'tA'
	var a, tA int
	fmt.Scanf("%d %d\n", &a, &tA)

	// Read the second line of input and split it to get values for 'b' and 'tB'
	var b, tB int
	fmt.Scanf("%d %d\n", &b, &tB)

	// Read the third line of input which contains the time in "HH:MM" format
	var timing string
	fmt.Scanf("%s\n", &timing)

	// Parse the hours and minutes from the input time
	hrs, _ := strconv.Atoi(timing[:2]) // Extract hours
	mins, _ := strconv.Atoi(timing[3:]) // Extract minutes

	// Convert the input time to total minutes since midnight
	simDeparture := hrs*60 + mins

	// Calculate the simulated arrival time by adding 'tA' to the departure time
	simArrival := simDeparture + tA

	// Initialize a counter to keep track of valid bus schedules
	counter := 0

	// Loop through the bus departure times starting from 5:00 AM (300 minutes) to 11:59 PM (1439 minutes)
	for i := 300; i < 1440; i += b {
		busDeparture := i          // Current bus departure time
		busArrival := i + tB      // Calculate bus arrival time

		// Check if the bus schedule overlaps with the simulated arrival time
		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue // If there's no overlap, skip to the next bus
		}

		// If there is an overlap, increment the counter
		counter++
	}

	// Output the total count of valid bus schedules
	fmt.Println(counter)
}

// <END-OF-CODE>
