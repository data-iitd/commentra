package main

import (
	"bufio" // bufio for buffered input
	"fmt"   // fmt for formatted I/O
	"os"    // os for standard input
	"strconv" // strconv for string to int conversion
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Initialize buffered reader to read input

	nStr, _ := reader.ReadString('\n') // Read the number of messages as a string
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to integer, removing newline

	input, _ := reader.ReadString('\n') // Read the string of messages

	max := -1 // Initialize max to -1
	msgLength := make([]int, len(input)/2) // Initialize msgLength slice with size len(input)/2
	count := 0 // Initialize count to 0
	idx := 0 // Initialize index to 0

	// Loop through each character in the input string
	for i := 0; i < len(input); i++ {
		c := input[i] // Read the character at index i

		if c == '.' || c == '?' || c == '!' { // If character is a question mark, exclamation mark or period
			msgLength[idx] = count + 1 // Store count in msgLength slice (incrementing count for the current message)
			idx++ // Increment index for the next message
			if count > max {
				max = count // Update max if count is greater than current max
			}
			count = 0 // Reset count as we have started a new message
		} else {
			count++ // Increment count if character is not a question mark, exclamation mark or period
		}
	}

	// Check if the total length of messages is greater than n
	if max > n {
		fmt.Println("Impossible") // Print "Impossible" if total length is greater than n
		return
	}

	ans := 0 // Initialize answer to 0

	// Loop through each message and find the maximum number of messages that can be sent
	for i := 0; i < idx; i++ {
		l := msgLength[i] // Initialize length of current message

		for i < idx-1 && l+msgLength[i+1]+1 <= n { // While we can add next message to current message
			l += msgLength[i+1] + 1 // Add length of next message and 1 for separator
			i++ // Increment i to move to next message
		}
		ans++ // Increment answer as we have added one more message
	}

	fmt.Println(ans) // Print the answer
}

// <END-OF-CODE>
