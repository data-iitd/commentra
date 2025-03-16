package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number 'n' from the user

	square := n * n // Calculating the square of the number 'n'

	odd := []int{}  // Creating an empty slice for odd numbers
	even := []int{} // Creating an empty slice for even numbers

	for i := 1; i <= square; i++ { // Looping from 1 to square
		if i%2 == 0 { // If the number is even
			even = append(even, i) // Add the number to the even slice
		} else { // If the number is odd
			odd = append(odd, i) // Add the number to the odd slice
		}
	}

	loop := square / n // Calculating the number of pairs to be printed
	div := loop / 2    // Calculating half of the number of pairs

	for i := 1; i <= loop; i++ { // Looping through each pair
		for j := 0; j < div; j++ { // Looping through half of the pair
			if i%2 == 1 { // If the current pair is odd
				fmt.Printf("%d %d ", odd[0], even[len(even)-1]) // Print the first and last numbers of the current pair
				odd = odd[1:] // Remove the first element from odd
				even = even[:len(even)-1] // Remove the last element from even
			} else { // If the current pair is even
				fmt.Printf("%d %d ", even[0], odd[len(odd)-1]) // Print the last and first numbers of the current pair
				even = even[1:] // Remove the first element from even
				odd = odd[:len(odd)-1] // Remove the last element from odd
			}
		}
		fmt.Println() // Printing a newline after each pair
	}
}

// <END-OF-CODE>
