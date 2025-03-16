package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the grid
	square := n * n // Calculate the total number of elements

	odd := []int{}  // Slice to store odd numbers
	even := []int{} // Slice to store even numbers

	// Separating numbers into odd and even slices
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i) // Add even numbers to the even slice
		} else {
			odd = append(odd, i) // Add odd numbers to the odd slice
		}
	}

	loop := square / n // Calculate the number of rows/columns
	div := loop / 2    // Calculate half the number of elements in each row/column

	debug(div) // Debugging statement to print the value of div

	// Nested loops to generate the pattern
	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				// Print odd and even numbers in reverse order for odd rows
				fmt.Printf("%d %d ", odd[0], even[len(even)-1])
				odd = odd[1:] // Remove the first element from odd
				even = even[:len(even)-1] // Remove the last element from even
			} else {
				// Print even and odd numbers in reverse order for even rows
				fmt.Printf("%d %d ", even[0], odd[len(odd)-1])
				even = even[1:] // Remove the first element from even
				odd = odd[:len(odd)-1] // Remove the last element from odd
			}
		}
		fmt.Println() // Move to the next line after each row
	}
}

func debug(obj ...interface{}) {
	fmt.Println(obj...) // Debugging statement to print the object array
}

// <END-OF-CODE>
