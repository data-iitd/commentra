
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new buffered reader.
	reader := bufio.NewReader(os.Stdin)

	// Read the first train's details.
	line, _ := reader.ReadString('\n')
	trainA := strings.Split(line, " ")
	a, _ := strconv.Atoi(trainA[0])
	tA, _ := strconv.Atoi(trainA[1])

	// Read the second train's details.
	line, _ = reader.ReadString('\n')
	trainB := strings.Split(line, " ")
	b, _ := strconv.Atoi(trainB[0])
	tB, _ := strconv.Atoi(trainB[1])

	// Read the current timing.
	line, _ = reader.ReadString('\n')
	timing := strings.Split(line, " ")
	hrs, _ := strconv.Atoi(timing[0])
	mins, _ := strconv.Atoi(timing[1])

	// Calculate the simulated departure and arrival times for train a.
	simDeparture := hrs*60 + mins
	simArrival := simDeparture + tA

	// Initialize counter to keep track of conflicts.
	counter := 0

	// Iterate through the bus schedule, checking for conflicts.
	for i := 300; i < 1440; i += b {
		busDeparture := i
		busArrival := i + tB

		// Check if there's a conflict (bus and train schedules overlap).
		if busDeparture >= simArrival || simDeparture >= busArrival {
			continue
		}

		// Increment counter if a conflict is found.
		counter++
	}

	// Print the number of conflicts found.
	fmt.Println(counter)
}

