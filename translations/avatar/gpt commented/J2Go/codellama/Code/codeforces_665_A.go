package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and tokenize it to get values for 'a' and 'tA'
	scanner.Scan()
	tokens := strings.Split(scanner.Text(), " ")
	a, _ := strconv.Atoi(tokens[0]) // 'a' represents some integer value
	tA, _ := strconv.Atoi(tokens[1]) // 'tA' represents the time taken by 'a'

	// Read the second line of input and tokenize it to get values for 'b' and 'tB'
	scanner.Scan()
	tokens = strings.Split(scanner.Text(), " ")
	b, _ := strconv.Atoi(tokens[0]) // 'b' represents another integer value
	tB, _ := strconv.Atoi(tokens[1]) // 'tB' represents the time taken by 'b'

	// Read the third line of input which contains the time in "HH:MM" format
	scanner.Scan()
	timing := scanner.Text()

	// Parse the hours and minutes from the input time
	hrs, _ := strconv.Atoi(timing[0:2]) // Extract hours
	mins, _ := strconv.Atoi(timing[3:]) // Extract minutes

	// Convert the input time to total minutes since midnight
	simDeparture := hrs*60 + mins

	// Calculate the simulated arrival time by adding 'tA' to the departure time
	simArrival := simDeparture + tA

	// Initialize a counter to keep track of valid bus schedules
	counter := 0

	// Loop through the bus departure times starting from 5:00 AM (300 minutes) to 11:59 PM (1439 minutes)
	for i := 300; i < 1440; i += b {
		busDeparture := i // Current bus departure time
		busArrival := i + tB // Calculate bus arrival time

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

