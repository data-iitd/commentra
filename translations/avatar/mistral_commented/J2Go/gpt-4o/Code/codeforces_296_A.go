package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a buffered reader for standard input
	writer := bufio.NewWriter(os.Stdout) // Creating a buffered writer for standard output
	defer writer.Flush()                  // Ensuring the writer flushes the output at the end

	var n int
	fmt.Fscan(reader, &n) // Reading the number of elements in the array

	array := make([]int, 1001) // Creating a slice of size 1001 to store the frequency of each element
	for i := 0; i < n; i++ {   // Loop to read and store the elements in the array
		var index int
		fmt.Fscan(reader, &index) // Reading the element
		array[index]++            // Incrementing the frequency of the element at the given index
	}

	countMax := -1 // Initializing the maximum frequency to -1
	for i := 1; i < len(array); i++ { // Loop to find the maximum frequency
		if countMax < array[i] {
			countMax = array[i] // Updating the maximum frequency
		}
	}

	if n%2 == 0 { // Checking if the number of elements is even
		if countMax <= n/2 { // If the maximum frequency is less than or equal to half of the number of elements
			fmt.Fprintln(writer, "YES") // Printing "YES" as the output
		} else {
			fmt.Fprintln(writer, "NO") // Else printing "NO" as the output
		}
	} else { // If the number of elements is odd
		if countMax <= n/2+1 { // If the maximum frequency is less than or equal to half of the number of elements plus one
			fmt.Fprintln(writer, "YES") // Printing "YES" as the output
		} else {
			fmt.Fprintln(writer, "NO") // Else printing "NO" as the output
		}
	}
}

// <END-OF-CODE>
