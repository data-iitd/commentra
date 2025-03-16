package main

import (
	"fmt"
)

func main() {
	var n int64   // Number of participants
	var k int64   // Points required to win
	var q int64   // Number of questions
	var a [100001]int64 // Array to store the questions
	var point [100001]int64 // Array to track points of each participant

	// Read input values for n, k, and q
	fmt.Scan(&n, &k, &q)

	// Process each question and update points for the corresponding participant
	for i := int64(0); i < q; i++ {
		fmt.Scan(&a[i]) // Read the participant number for the question
		point[a[i]-1]++ // Increment the point for the participant who answered
	}

	// Determine if each participant has enough points to win
	for i := int64(0); i < n; i++ {
		if k-(q-point[i]) > 0 { // Check if the participant has enough points
			fmt.Println("Yes") // Participant can win
		} else {
			fmt.Println("No") // Participant cannot win
		}
	}
}

// <END-OF-CODE>
