
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

	// Read a list of integers from input and convert them to a list of integers
	lstTemp, err := reader.ReadString('\n')
	checkError(err)
	lstTemp = strings.TrimSpace(lstTemp)
	lst := strings.Split(lstTemp, " ")
	var lstI []int
	for _, v := range lst {
		i, err := strconv.ParseInt(v, 10, 64)
		checkError(err)
		lstI = append(lstI, int(i))
	}

	// Sort the list in ascending order
	sort(lstI)

	// Reverse the list to get it in descending order
	for i, j := 0, len(lstI)-1; i < j; i, j = i+1, j-1 {
		lstI[i], lstI[j] = lstI[j], lstI[i]
	}

	// Initialize a counter for odd numbers
	od := 0

	// Count the number of odd integers in the list
	for _, v := range lstI {
		if v&1 == 1 { // Check if the number is odd using bitwise AND
			od++ // Increment the odd counter
		}
	}

	// Initialize variables for sum and a flag to track even number inclusion
	sum := 0
	ok := false

	// Iterate through the sorted list to calculate the desired sum
	for _, v := range lstI {
		if v&1 == 0 { // Check if the current number is even
			sum += v // Add even numbers directly to the sum
		} else {
			// If we have already included an odd number or there is more than one odd number left
			if ok || od > 1 {
				sum += v // Add the odd number to the sum
				od--      // Decrement the odd counter
				ok =!ok  // Toggle the flag to indicate an odd number has been included
			}
		}
	}

	// Print the final calculated sum
	fmt.Println(sum)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func sort(arr []int) {
	// Implement your own sorting algorithm here
}

