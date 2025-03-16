package main

import (
	"fmt"
)

func main() {
	var h1, m1, h2, m2, k int // Declare variables for hours and minutes of first and second time, and the difference

	// Input the values of hours and minutes for the first and second time
	fmt.Print("Enter hours and minutes for the first time: ")
	fmt.Scan(&h1, &m1)

	fmt.Print("Enter hours and minutes for the second time: ")
	fmt.Scan(&h2, &m2)

	ans := h2*60 + m2 // Calculate the total minutes of the second time
	fmt.Println("The total minutes of the second time are:", ans)

	ans -= (h1*60 + m1) // Subtract the total minutes of the first time from the total minutes of the second time
	fmt.Println("The difference in minutes is:", ans)

	fmt.Print("Enter the difference 'k' to subtract: ")
	fmt.Scan(&k) // Input the value of k
	ans -= k // Subtract the given difference 'k' from the difference in minutes
	fmt.Println("The difference in minutes after subtracting", k, "is:", ans)

	// Convert the difference in minutes to hours and minutes
	hours := ans / 60
	minutes := ans % 60

	fmt.Printf("%d hours and %d minutes\n", hours, minutes) // Output the result
}

// <END-OF-CODE>
