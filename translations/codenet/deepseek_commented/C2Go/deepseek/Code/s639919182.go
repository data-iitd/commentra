package main

import "fmt"

func main() {
	var v [10]int // Step 2: Declare an array of 10 integers
	var sum int // Step 2: Declare and initialize a variable to store the sum
	
	for i := 0; i < 10; i++ { // Step 3: Initialize a loop to read 10 integers from the user
		fmt.Scan(&v[i]) // Step 3: Read an integer and store it in the array
	}
	
	for i := 0; i < 10; i++ { // Step 4: Initialize a loop to calculate the sum of the integers
		sum += v[i] // Step 4: Add the current element to the sum
	}
	
	fmt.Println(sum) // Step 5: Print the sum of the integers
}

