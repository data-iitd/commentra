package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func sort(vecIntValue []int) {
	// Step 4: Sort function implementation
	// The sort function uses the insertion sort algorithm.
	// It iterates through the vector, inserting each element in the correct position.
	// It prints the vector after each insertion to show the progress of the sorting process.

	for i := 0; i < len(vecIntValue); i++ {
		// If it's not the first element, insert it in the correct position
		if i != 0 {
			iIntValue := vecIntValue[i]
			j := i - 1
			for j >= 0 && vecIntValue[j] > iIntValue {
				vecIntValue[j+1] = vecIntValue[j]
				j--
			}
			vecIntValue[j+1] = iIntValue
		}
		// Print the vector after each insertion
		for k := 0; k < len(vecIntValue); k++ {
			fmt.Print(vecIntValue[k])
			if k != len(vecIntValue)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}

func main() {
	// Step 3: Main function
	// The main function reads the number of integers to be sorted.
	// It then reads each integer and stores them in a vector.
	// It calls the `sort` function with the vector.

	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter number of integers: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	iNum, _ := strconv.Atoi(input)

	vecIntValue := []int{}
	for i := 0; i < iNum; i++ {
		fmt.Print("Enter integer: ")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		iIntValue, _ := strconv.Atoi(input)
		vecIntValue = append(vecIntValue, iIntValue)
	}

	sort(vecIntValue)
}

