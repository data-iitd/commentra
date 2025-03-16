
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input which represents the number of elements in the array
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	// Read the next line of input, split it by spaces, convert each element to an integer, and store it in a slice
	arrTemp := strings.Split(readLine(reader), " ")
	var arr []int32
	for _, arrItem := range arrTemp {
		arrItemTemp, err := strconv.ParseInt(arrItem, 10, 64)
		checkError(err)
		arrItemTemp32 := int32(arrItemTemp)
		arr = append(arr, arrItemTemp32)
	}

	// Check if the first element of the array is greater than 15
	if arr[0] > 15 {
		// If true, print 15 as the output
		fmt.Println(15)
	} else {
		// Iterate through the array starting from the second element
		for i := 1; i < len(arr); i++ {
			// Check if the difference between the current and previous element is greater than 15
			if arr[i]-arr[i-1] > 15 {
				// If true, print the previous element plus 15 and exit the loop
				fmt.Println(arr[i-1] + 15)
				break
			}
		} else {
			// If no break occurred, check the last element of the array
			if arr[len(arr)-1] == 90 || arr[len(arr)-1]+15 >= 90 {
				// If the last element is 90 or adding 15 to it results in 90 or more, print 90
				fmt.Println(90)
			} else {
				// Otherwise, print the last element plus 15
				fmt.Println(arr[len(arr)-1] + 15)
			}
		}
	}

	