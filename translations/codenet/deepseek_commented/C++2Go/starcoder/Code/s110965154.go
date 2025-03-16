<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// InsertionSort sorts a vector of integers using the insertion sort algorithm.
func InsertionSort(a_rvecIntValue []int) {

	// Iterate through the vector, inserting each element in the correct position
	for i := 0; i < len(a_rvecIntValue); i++ {

		// If it's not the first element, insert it in the correct position
		if i!= 0 {
			iIntValue := a_rvecIntValue[i]
			j := i - 1
			for ; j >= 0 && a_rvecIntValue[j] > iIntValue; j-- {
				a_rvecIntValue[j+1] = a_rvecIntValue[j]
			}
			a_rvecIntValue[j+1] = iIntValue
		}

		// Print the vector after each insertion
		fmt.Println(a_rvecIntValue)
	}
}

func main() {

	// Read the number of integers to be sorted
	var iNum int
	fmt.Scanf("%d\n", &iNum)

	// Read each integer and store them in a vector
	var vecIntValue []int
	for i := 0; i < iNum; i++ {
		var iIntValue int
		fmt.Scanf("%d\n", &iIntValue)
		vecIntValue = append(vecIntValue, iIntValue)
	}

	// Sort the vector
	InsertionSort(vecIntValue)
}

// 