package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a BufferedReader object to read input
	nStr, _ := reader.ReadString('\n')   // Reading the maximum length for each message
	n, _ := strconv.Atoi(strings.TrimSpace(nStr)) // Parsing the maximum length to an integer
	input, _ := reader.ReadString('\n') // Reading the input text
	input = strings.TrimSpace(input) // Trimming whitespace from the input

	max := -1 // Initializing the maximum message length to -1
	msgLength := make([]int, len(input)/2) // Initializing a slice to store the lengths of each message
	count := 0 // Initializing a counter for the current message length
	idx := 0   // Index for the msgLength slice

	// Iterating through the input string to determine message lengths
	for i := 0; i < len(input); i++ {
		c := input[i] // Getting the current character
		if c == '.' || c == '?' || c == '!' {
			msgLength[idx] = count + 1 // Storing the length of the current message
			idx++ // Incrementing the index
			if count+1 > max {
				max = count + 1 // Updating the maximum message length if necessary
			}
			i++ // Skipping the next character as it is part of the next message
			count = 0 // Resetting the counter for the next message
		} else {
			count++ // Incrementing the counter for the current message length
		}
	}

	// Checking if the maximum message length exceeds the allowed maximum
	if max > n {
		fmt.Println("Impossible") // Printing "Impossible" if the maximum message length is too large
	} else {
		ans := 0 // Initializing the answer variable to store the number of messages
		for i := 0; i < idx; i++ {
			l := msgLength[i] // Getting the length of the current message
			for i < idx-1 && l+msgLength[i+1]+1 <= n {
				l += msgLength[i+1] + 1 // Grouping messages that fit within the maximum length
				i++ // Moving to the next message
			}
			ans++ // Incrementing the answer as we have a complete message
		}
		fmt.Println(ans) // Printing the total number of messages required
	}
}

// <END-OF-CODE>
