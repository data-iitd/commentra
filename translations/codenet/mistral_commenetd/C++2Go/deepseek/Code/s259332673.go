package main

import (
	"fmt"
)

func main() {
	var h1, h2, m1, m2, k int

	// Input the values of hours and minutes for the first and second time
	fmt.Print("Enter hours and minutes for the first time: ")
	fmt.Scan(&h1, &m1)

	fmt.Print("Enter hours and minutes for the second time: ")
	fmt.Scan(&h2, &m2)

	ans := h2*60 + m2 // Calculate the total minutes of the second time
	fmt.Printf("The total minutes of the second time are: %d\n", ans)

	ans -= (h1*60 + m1) // Subtract the total minutes of the first time from the total minutes of the second time
	fmt.Printf("The difference in minutes is: %d\n", ans)

	fmt.Print("Enter the difference in minutes: ")
	fmt.Scan(&k)

	ans -= k // Subtract the given difference 'k' from the difference in minutes
	fmt.Printf("The difference in minutes after subtracting %d is: %d\n", k, ans)

	// Convert the difference in minutes to hours and minutes
	hours := ans / 60
	minutes := ans % 60

	fmt.Printf("%d hours and %d minutes\n", hours, minutes) // Output the result
}

