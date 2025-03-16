package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a new reader to read input from the console
	reader := bufio.NewReader(os.Stdin)
	
	// Initialize a new writer to output results to the console
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	
	// Read the first line of input and tokenize it to get values for 'a' and 'tA'
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(strings.TrimSpace(line), " ")
	a, _ := strconv.Atoi(tokens[0])
	tA, _ := strconv.Atoi(tokens[1])
	
	// Read the second line of input and tokenize it to get values for 'b' and 'tB'
	line, _ = reader.ReadString('\n')
	tokens = strings.Split(strings.TrimSpace(line), " ")
	b, _ := strconv.Atoi(tokens[0])
	tB, _ := strconv.Atoi(tokens[1])
	
	// Read the third line of input which contains the time in "HH:MM" format
	line, _ = reader.ReadString('\n')
	timing := strings.TrimSpace(line)
	
	// Parse the hours and minutes from the input time
	hrs, _ := strconv.Atoi(timing[:2])
	mins, _ := strconv.Atoi(timing[3:])
	
	// Convert the input time to total minutes since midnight
	simDeparture := hrs * 60 + mins
	
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
	writer.WriteString(strconv.Itoa(counter) + "\n")
}

