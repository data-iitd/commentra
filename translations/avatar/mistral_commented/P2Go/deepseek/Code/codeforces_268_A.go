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
	n, _ := strconv.Atoi(readLine(reader))

	// Create an empty list called 'q' to store these arrays
	q := [][]string{}

	// Use a for loop to iterate through the range of 'n' and for each iteration,
	// ask the user for an array (a) and append it to our list 'q'
	for i := 0; i < n; i++ {
		// Ask user for an array (a)
		a := strings.Split(readLine(reader), " ")
		// Append array 'a' to our list 'q'
		q = append(q, a)
	}

	// Initialize a count variable to keep track of matches
	count := 0

	// Use another for loop to iterate through each array in our list 'q'
	for _, j := range q {
		// For each array 'j', use another for loop to iterate through every other array in our list 'q'
		for _, k := range q {
			// Exclude the current array 'j' from comparison using 'continue' statement if they are the same
			if strings.Join(j, " ") == strings.Join(k, " ") {
				continue
			}
			// Check if the last element of the second array 'k' matches the first element of the first array 'j'
			if j[0] == k[len(k)-1] {
				// If it does, increment our 'count' variable
				count++
			}
		}
	}

	// Finally, print out the value of our 'count' variable
	fmt.Println(count)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}
