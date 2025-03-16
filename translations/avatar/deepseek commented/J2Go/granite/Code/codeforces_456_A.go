

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var md []int // Global slice to store some data

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a bufio.Reader object to read input
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64) // Read the number of elements
	checkError(err)
	n := int(nTemp) // Convert the number of elements to an integer
	a := make([]int, n) // Initialize slice 'a' to store first set of values
	b := make([]int, n) // Initialize slice 'b' to store second set of values
	temp := 0 // Variable to temporarily store a value
	q := 0 // Variable to store a value for comparison
	w := 0 // Variable to store the maximum value of 'a'
	e := 0 // Variable to store a value for comparison
	f := false // Boolean variable to determine the output

	// Loop through each element
	for i := 0; i < n; i++ {
		aTemp, err := strconv.ParseInt(readLine(reader), 10, 64) // Read the value for array 'a'
		checkError(err)
		a[i] = int(aTemp) // Convert the value for array 'a' to an integer
		bTemp, err := strconv.ParseInt(readLine(reader), 10, 64) // Read the value for array 'b'
		checkError(err)
		b[i] = int(bTemp) // Convert the value for array 'b' to an integer
		if temp < a[i] { // Check if the current 'a' value is greater than the stored 'temp' value
			if q > b[i] { // Check if the stored 'q' value is greater than the current 'b' value
				f = true // Set 'f' to true if the condition is met
			}
			q = b[i] // Update 'q' with the current 'b' value
			temp = a[i] // Update 'temp' with the current 'a' value
		}
		if temp > a[i] { // Check if the current 'a' value is less than the stored 'temp' value
			if q < b[i] { // Check if the stored 'q' value is less than the current 'b' value
				f = true // Set 'f' to true if the condition is met
			}
			q = b[i] // Update 'q' with the current 'b' value
			temp = a[i] // Update 'temp' with the current 'a' value
		}
		if a[i] > w { // Check if the current 'a' value is greater than the stored 'w' value
			w = a[i] // Update 'w' with the current 'a' value
			if b[i] < e { // Check if the current 'b' value is less than the stored 'e' value
				f = true // Set 'f' to true if the condition is met
			}
			e = b[i] // Update 'e' with the current 'b' value
		}
		if a[i] < w { // Check if the current 'a' value is less than the stored 'w' value
			if b[i] > e { // Check if the current 'b' value is greater than the stored 'e' value
				f = true // Set 'f' to true if the condition is met
			}
		}
	}

	// Determine and print the output based on the value of 'f'
	if f == true {
		fmt.Println("Happy Alex") // Print "Happy Alex" if 'f' is true
	} else {
		fmt.Println("Poor Alex") // Print "Poor Alex" if 'f' is false
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine() // Read a line of input
	if err == nil {
		return strings.TrimRight(string(str), "\r\n") // Return the line of input without trailing whitespace
	}
	return "" // Return an empty string if an error occurs
}

func checkError(err error) {
	if err!= nil {
		panic(err) // Panic if an error occurs
	}
}

