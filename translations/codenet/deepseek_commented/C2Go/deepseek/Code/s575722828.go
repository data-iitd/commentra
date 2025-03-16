package main

import (
	"fmt" // Step 1: Include necessary packages
)

func main() { // Step 2: Define the main function
	var S int // Step 3: Declare an integer variable S

	fmt.Scan(&S) // Step 4: Read an integer value from the user and store it in S

	hours := S / 3600 // Step 5: Calculate hours from the total seconds S
	minutes := (S % 3600) / 60 // Step 6: Calculate minutes from the total seconds S
	seconds := S % 60 // Step 7: Calculate seconds from the total seconds S

	fmt.Printf("%d:%d:%d\n", hours, minutes, seconds) // Step 8: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
}

