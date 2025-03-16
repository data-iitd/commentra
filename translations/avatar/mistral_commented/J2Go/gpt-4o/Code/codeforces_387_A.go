package main

import (
	"fmt"
	"log"
	"time"
)

func main() {
	// Create a new scanner to read input from the console
	var input1, input2 string
	fmt.Scan(&input1, &input2)

	// Parse the first time string
	t1, err := time.Parse("15:04", input1)
	if err != nil {
		log.Fatal(err)
	}

	// Parse the second time string
	t2, err := time.Parse("15:04", input2)
	if err != nil {
		log.Fatal(err)
	}

	// Calculate the difference between the two times
	diff := t1.Sub(t2)

	// Print the result in hours and minutes
	hours := int(diff.Hours())
	minutes := int(diff.Minutes()) % 60
	fmt.Printf("%d hours and %d minutes\n", hours, minutes)
}

// <END-OF-CODE>
