package main

import (
	"fmt"
)

func sort(a_rvecIntValue []int) {
	// Step 4: Sort function implementation
	// The sort function uses the insertion sort algorithm.
	// It iterates through the slice, inserting each element in the correct position.
	// It prints the slice after each insertion to show the progress of the sorting process.

	for i := 0; i < len(a_rvecIntValue); i++ {
		// If it's not the first element, insert it in the correct position
		if i != 0 {
			iIntValue := a_rvecIntValue[i]
			j := i - 1
			for j >= 0 && a_rvecIntValue[j] > iIntValue {
				a_rvecIntValue[j+1] = a_rvecIntValue[j]
				j--
			}
			a_rvecIntValue[j+1] = iIntValue
		}

		// Print the slice after each insertion
		for k := 0; k < len(a_rvecIntValue); k++ {
			fmt.Print(a_rvecIntValue[k])
			if k != len(a_rvecIntValue)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

func main() {
	// Step 3: Main function
	// The main function reads the number of integers to be sorted.
	// It then reads each integer and stores them in a slice.
	// It calls the `sort` function with the slice.

	var iNum int
	fmt.Scan(&iNum)
	vecIntValue := make([]int, 0, iNum)

	for iNum > 0 {
		var iIntValue int
		fmt.Scan(&iIntValue)
		vecIntValue = append(vecIntValue, iIntValue)
		iNum--
	}

	sort(vecIntValue)
}

// Step 5: Output
// The program outputs the sorted slice after each insertion.

