package main

import (
	"bufio" // Package for buffered I/O
	"fmt"   // Package for formatted I/O
	"os"    // Package for OS functions
	"strconv" // Package for string conversions
	"strings" // Package for string manipulation
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a buffered reader to read input
	writer := bufio.NewWriter(os.Stdout) // Create a buffered writer to write output

	// Read the first line of input and parse the integers
	line, _ := reader.ReadString('\n') // Read the first line
	tokens := strings.Fields(line) // Split the line into fields
	a, _ := strconv.Atoi(tokens[0]) // Parse the first integer (number of students)
	tA, _ := strconv.Atoi(tokens[1]) // Parse the second integer (time taken by student A)

	// Read the second line of input and parse the integers
	line, _ = reader.ReadString('\n') // Read the second line
	tokens = strings.Fields(line) // Split the line into fields
	b, _ := strconv.Atoi(tokens[0]) // Parse the first integer (number of students in bus B)
	tB, _ := strconv.Atoi(tokens[1]) // Parse the second integer (time taken by bus B)

	// Read the third line of input and parse the string
	line, _ = reader.ReadString('\n') // Read the string representing the bus timing
	timing := strings.TrimSpace(line) // Trim any whitespace
	hrs, _ := strconv.Atoi(timing[:2]) // Parse the hours from the string
	mins, _ := strconv.Atoi(timing[3:]) // Parse the minutes from the string
	simDeparture := hrs*60 + mins // Calculate the simulation time of bus departure
	simArrival := simDeparture + tA // Calculate the simulation time of bus arrival

	counter := 0 // Initialize the counter to 0

	// Loop through the bus timings to find the number of buses that can accommodate students
	for i := 300; i < 1440; i += b { // Loop through the bus timings from 300 to 1439 in increments of busB
		busDeparture := i // Store the bus departure time
		busArrival := i + tB // Calculate the bus arrival time

		if busDeparture >= simArrival || simDeparture >= busArrival { // Check if the bus departure or arrival time is after the simulation time
			continue // If so, skip to the next iteration of the loop
		}
		counter++ // Increment the counter if the bus timing is valid
	}

	// Write the output to the console
	fmt.Fprintln(writer, counter) // Print the number of buses that can accommodate students
	writer.Flush() // Flush the buffered writer to write the output immediately
}

// <END-OF-CODE>
