
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables for number of friends (N), days (D), and initial chocolates (X)
	var N, D, X int
	// Variable to store the total number of chocolates
	var num_of_chocolate int
	// Counter for the number of days
	var counter int
	// Variable to track days for each friend
	var days int
	// Array to hold the chocolate consumption rate for each friend
	A := make([]int, 101)

	// Input the number of friends, days, and initial chocolates
	reader := bufio.NewReader(os.Stdin)
	N, _ = strconv.Atoi(reader.ReadLine()[0:1])
	D, _ = strconv.Atoi(reader.ReadLine()[0:1])
	X, _ = strconv.Atoi(reader.ReadLine()[0:1])

	// Input the chocolate consumption rates for each friend
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(reader.ReadLine()[0:1])
	}

	// Initialize the total number of chocolates with the initial amount
	num_of_chocolate = 0

	// Loop through each friend to calculate the number of chocolates they will consume
	for i := 0; i < N; i++ {
		// Reset days and counter for each friend
		days = 0
		counter = 0

		// Calculate how many chocolates can be consumed within the given days
		for j := 0;; j++ {
			// Calculate the total days required to consume chocolates
			days = j * A[i] + 1
			// If the calculated days are within the limit, increment the counter
			if days <= D {
				counter++
			}
			// Break the loop if the days exceed the limit
			else {
				break
			}
		}
		// Add the count of chocolates consumed by this friend to the total
		num_of_chocolate = num_of_chocolate + counter
	}

	// Add the initial chocolates to the total count
	num_of_chocolate = num_of_chocolate + X

	// Output the total number of chocolates
	fmt.Println(num_of_chocolate)
}
