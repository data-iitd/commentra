package main

import "fmt"

func main() {
	// Include necessary headers
	// The code starts by including necessary headers for input and output operations.
	// Headers for input and output operations are included.

	// Declare arrays
	// Two arrays, `train` and `bus`, are declared to store the values.
	train := [2]int{}
	bus := [2]int{}

	// Input values
	// The values for `train` and `bus` are taken from the user.
	fmt.Scan(&train[0], &train[1])
	fmt.Scan(&bus[0], &bus[1])

	// Calculate the sum
	// The code then calculates the sum of the minimum values from both arrays.
	fmt.Println((train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]))

	// Output the result
	// Finally, the result is printed to the console.
}

