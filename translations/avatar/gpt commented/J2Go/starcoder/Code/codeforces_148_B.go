package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read input from stdin
	fmt.Print("Enter the velocity of the person: ")
	VP, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter the velocity of the dog: ")
	VD, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter the initial time before the dog starts chasing: ")
	T, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter the time taken for the dog to return to the person: ")
	F, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)
	fmt.Print("Enter the distance the person needs to cover: ")
	C, _ := strconv.ParseFloat(strings.TrimSpace(reader.ReadString()), 64)

	// If the dog's velocity is less than or equal to the person's velocity, the dog cannot catch up
	if VD <= VP {
		fmt.Println("0") // Output 0 as the dog will never catch the person
		return
	}

	answer := 0 // Initialize the number of times the dog catches up
	start := T  // Start time for the first chase

	// Loop to calculate how many times the dog can catch the person
	for {
		// Calculate the distance the person covers before the dog catches up
		x := start * VP / (VD - VP)

		// Check if the distance covered by the person is greater than or equal to C
		if (start + x) * VP >= C {
			break
		}

		// Update the start time for the next chase
		start += 2 * x + F // Add the time taken for the dog to return and the time to catch up
		answer++ // Increment the count of catches
	}

	// Output the total number of times the dog catches the person
	fmt.Println(answer)
}

