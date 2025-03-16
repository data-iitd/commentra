
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input for the number of elements
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Read a line of space-separated floats and convert them to a list of floats
	arrTemp, err := reader.ReadString('\n')
	checkError(err)
	arrTemp = strings.TrimSpace(arrTemp)
	arr := strings.Split(arrTemp, " ")
	var arrItems []float64
	for _, arrItem := range arr {
		arrItemTemp, err := strconv.ParseFloat(arrItem, 64)
		checkError(err)
		arrItems = append(arrItems, arrItemTemp)
	}

	// Calculate the fractional parts of the elements, excluding whole numbers
	var arr2 []float64
	for _, arrItem := range arrItems {
		frac := arrItem - float64(int(arrItem))
		if frac!= 0 {
			arr2 = append(arr2, frac)
		}
	}

	// Sort the fractional parts in ascending order
	for i := 0; i < len(arr2); i++ {
		for j := 0; j < len(arr2)-i-1; j++ {
			if arr2[j] > arr2[j+1] {
				arr2[j], arr2[j+1] = arr2[j+1], arr2[j]
			}
		}
	}

	// Calculate the number of whole numbers that can be added to the fractional parts
	o := 2*int(n) - len(arr2)

	// Calculate the sum of the fractional parts
	var arr2Sum float64
	for _, arrItem := range arr2 {
		arr2Sum += arrItem
	}

	// Initialize the result with a large number
	res := int(2e9)

	// Iterate through possible counts of fractional parts used
	for i := 0; i <= int(n); i++ {
		// Check if the current count of fractional parts plus whole numbers is sufficient
		if i+o >= int(n) {
			// Update the result with the minimum difference found
			diff := float64(i) - arr2Sum
			if diff < 0 {
				diff = -diff
			}
			if diff < float64(res) {
				res = int(diff)
			}
		}
	}

	// Print the result formatted to three decimal places
	fmt.Printf("%.3f", float64(res))
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

