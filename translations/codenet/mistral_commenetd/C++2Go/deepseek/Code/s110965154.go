package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to sort the vector in ascending order using insertion sort algorithm
func sort(a_rvecIntValue []int) {
	// Iterate through each element in the vector starting from the second element
	for i := 0; i < len(a_rvecIntValue); i++ {
		if i != 0 { // Check if we are not at the first element
			iIntValue := a_rvecIntValue[i] // Get the value of the current element
			j := i - 1                     // Initialize a variable to store the index of the previous element
			for j >= 0 && a_rvecIntValue[j] > iIntValue { // While the previous element is greater than the current element
				a_rvecIntValue[j+1] = a_rvecIntValue[j] // Swap the previous and next elements
				j--                                   // Decrement the index of the previous element
			}
			a_rvecIntValue[j+1] = iIntValue // Place the current element at its correct position
		}
		// Print the sorted vector after each insertion
		for k := 0; k < len(a_rvecIntValue); k++ {
			fmt.Print(a_rvecIntValue[k]) // Print the value of the current element
			if k != len(a_rvecIntValue)-1 { // Check if we are not at the last element
				fmt.Print(" ") // Print a space if not
			}
		}
		fmt.Println() // Print a newline after each pass
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter number of elements: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)
	iNum, _ := strconv.Atoi(text)

	var vecIntValue []int
	for iNum > 0 {
		fmt.Print("Enter an integer: ")
		text, _ := reader.ReadString('\n')
		text = strings.TrimSpace(text)
		iIntValue, _ := strconv.Atoi(text)
		vecIntValue = append(vecIntValue, iIntValue)
		iNum--
	}

	// Call the sorting function to sort the vector
	sort(vecIntValue)
}

