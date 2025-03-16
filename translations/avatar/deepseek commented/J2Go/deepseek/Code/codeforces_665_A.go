package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create BufferedReader to read input from System.in
	reader := bufio.NewReader(os.Stdin)
	// Create PrintWriter to write output to System.in
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the first train's details
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	a, _ := strconv.Atoi(parts[0]) // Train number a
	tA, _ := strconv.Atoi(parts[1]) // Travel time for train a

	// Read the second train's details
	line, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(line), " ")
	b, _ := strconv.Atoi(parts[0]) // Train number b
	tB, _ := strconv.Atoi(parts[1]) // Travel time for train b

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
		busDeparture := i // Bus departure time
		busArrival := busDeparture + tB // Bus arrival time

		// Check if there's a conflict (bus and train schedules overlap)
		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue
		}

		// Increment counter if a conflict is found
		counter++
	}

	// Print the number of conflicts found
	fmt.Fprintln(writer, counter)
}

