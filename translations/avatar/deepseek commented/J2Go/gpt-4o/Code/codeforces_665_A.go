package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from standard input
	reader := bufio.NewReader(os.Stdin)

	// Read the first train's details
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)
	a, _ := strconv.Atoi(tokens[0]) // Train number a
	tA, _ := strconv.Atoi(tokens[1]) // Travel time for train a

	// Read the second train's details
	line, _ = reader.ReadString('\n')
	tokens = strings.Fields(line)
	b, _ := strconv.Atoi(tokens[0]) // Train number b
	tB, _ := strconv.Atoi(tokens[1]) // Travel time for train b

	// Read the current timing
	timing, _ := reader.ReadString('\n')
	timing = strings.TrimSpace(timing)
	hrs, _ := strconv.Atoi(timing[:2]) // Extract hour from timing
	mins, _ := strconv.Atoi(timing[3:]) // Extract minute from timing

	// Calculate the simulated departure and arrival times for train a
	simDeparture := hrs*60 + mins
	simArrival := simDeparture + tA

	// Initialize counter to keep track of conflicts
	counter := 0

	// Iterate through the bus schedule, checking for conflicts
	for i := 300; i < 1440; i += b {
		busDeparture := i   // Bus departure time
		busArrival := i + tB // Bus arrival time

		// Check if there's a conflict (bus and train schedules overlap)
		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue
		}

		// Increment counter if a conflict is found
		counter++
	}

	// Print the number of conflicts found
	fmt.Println(counter)
}

// <END-OF-CODE>
