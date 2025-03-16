
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// User inputs the maximum level of the set
	maxLevel, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// User inputs two lists, x and y, separated by a newline
	x := make([]int, 0)
	y := make([]int, 0)
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &x[0])
	for i := 1; i < len(x); i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), " %d", &x[i])
	}
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &y[0])
	for i := 1; i < len(y); i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), " %d", &y[i])
	}

	// Remove the first element from both lists, as they are not part of the sets
	x = x[1:]
	y = y[1:]

	// Convert both lists to sets for faster set operations
	xSet := make(map[int]bool)
	for _, v := range x {
		xSet[v] = true
	}
	ySet := make(map[int]bool)
	for _, v := range y {
		ySet[v] = true
	}

	// Check if zero is present in the first set
	if xSet[0] {
		// If it is, remove it
		delete(xSet, 0)
	}
	// Else, check if zero is present in the second set
	else {
		if ySet[0] {
			// If it is, remove it
			delete(ySet, 0)
		}
	}

	// Combine both sets into a new set z
	z := make(map[int]bool)
	for k := range xSet {
		z[k] = true
	}
	for k := range ySet {
		z[k] = true
	}

	// Check if the size of the combined set is equal to the maximum level
	if len(z)!= maxLevel {
		// If not, print an error message
		fmt.Println("Oh, my keyboard!")
	}
	// Else, print a success message
	else {
		fmt.Println("I become the guy.")
	}
}
