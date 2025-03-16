
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Ask user for the number of arrays (n) they want to input
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of arrays: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0])

	// Create an empty list called 'q' to store these arrays
	q := make([][]string, n)

	// Use a for loop to iterate through the range of 'n' and for each iteration,
	// ask the user for an array (a) and append it to our list 'q'
	for i := 0; i < n; i++ {
		fmt.Print("Enter array " + strconv.Itoa(i+1) + ": ")
		a := strings.Split(reader.ReadLine()[0], " ")
		q[i] = a
	}

	// Use another for loop to iterate through each array in our list 'q'
	count := 0
	for i := 0; i < n; i++ {
		// For each array 'j', use another for loop to iterate through every other array in our list 'q'
		for j := 0; j < n; j++ {
			// Exclude the current array 'j' from comparison using 'continue' statement if they are the same
			if j == i {
				continue
			}
			// Check if the last element of the second array 'k' matches the first element of the first array 'j'
			if q[i][0] == q[j][len(q[j])-1] {
				// If it does, increment our 'count' variable
				count++
			}
		}
	}

	// Finally, print out the value of our 'count' variable
	fmt.Println(count)
}
