
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

// Read the first line of input from stdin.
input, _ := reader.ReadString('\n')

// Split the input into a slice of strings.
input = strings.Split(input, " ")

// Convert the first string in the slice to an integer.
a, _ := strconv.Atoi(input[0])

// Convert the second string in the slice to an integer.
tA, _ := strconv.Atoi(input[1])

// Read the second line of input from stdin.
input, _ = reader.ReadString('\n')

// Split the input into a slice of strings.
input = strings.Split(input, " ")

// Convert the first string in the slice to an integer.
b, _ := strconv.Atoi(input[0])

// Convert the second string in the slice to an integer.
tB, _ := strconv.Atoi(input[1])

// Read the third line of input from stdin.
input, _ = reader.ReadString('\n')

// Split the input into a slice of strings.
input = strings.Split(input, " ")

// Convert the first string in the slice to an integer.
hrs, _ := strconv.Atoi(input[0])

// Convert the second string in the slice to an integer.
mins, _ := strconv.Atoi(input[1])

// Calculate the simulation time of bus departure.
simDeparture := hrs * 60 + mins

// Calculate the simulation time of bus arrival.
simArrival := simDeparture + tA

// Initialize the counter to 0.
counter := 0

// Loop through the bus timings to find the number of buses that can accommodate students.
for i := 300; i < 1440; i += b {
// Store the bus departure time.
busDeparture := i

// Calculate the bus arrival time.
busArrival := i + tB

// Check if the bus departure or arrival time is after the simulation time.
if busDeparture >= simArrival || simDeparture >= busArrival {
// If so, skip to the next iteration of the loop.
continue
}

// Increment the counter if the bus timing is valid.
counter++
}

// Print the number of buses that can accommodate students.
fmt.Println(counter)
}

