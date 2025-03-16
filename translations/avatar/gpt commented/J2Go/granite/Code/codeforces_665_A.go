
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize bufio.Scanner to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line of input and tokenize it to get values for 'a' and 'tA'
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	a, _ := strconv.Atoi(parts[0])
	tA, _ := strconv.Atoi(parts[1])

	// Read the second line of input and tokenize it to get values for 'b' and 'tB'
	scanner.Scan()
	line = scanner.Text()
	parts = strings.Split(line, " ")
	b, _ := strconv.Atoi(parts[0])
	tB, _ := strconv.Atoi(parts[1])

	// Read the third line of input which contains the time in "HH:MM" format
	scanner.Scan()
	line = scanner.Text()
	parts = strings.Split(line, ":")
	hrs, _ := strconv.Atoi(parts[0])
	mins, _ := strconv.Atoi(parts[1])

	// Convert the input time to total minutes since midnight
	simDeparture := hrs*60 + mins

	// Calculate the simulated arrival time by adding 'tA' to the departure time
	simArrival := simDeparture + tA

	// Initialize a counter to keep track of valid bus schedules
	counter := 0

	// Loop through the bus departure times starting from 5:00 AM (300 minutes) to 11:59 PM (1439 minutes)
	for i := 300; i < 1440; i += b {
		busDeparture := i
		busArrival := i + tB

		// Check if the bus schedule overlaps with the simulated arrival time
		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue
		}

		// If there is an overlap, increment the counter
		counter++
	}

	// Output the total count of valid bus schedules
	fmt.Println(counter)
}

