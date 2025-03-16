package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a BufferedReader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the maximum allowed length of messages
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	// Read the input string containing messages
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	// Initialize variables to track the maximum message length and store lengths of individual messages
	max := -1
	msgLength := make([]int, len(input)/2)
	count := 0
	idx := 0

	// Iterate through each character in the input string
	for i := 0; i < len(input); i++ {
		c := input[i]

		// Check if the character is a message delimiter (., ?, or !)
		if c == '.' || c == '?' || c == '!' {
			// Store the length of the current message and update the maximum length if necessary
			msgLength[idx] = count + 1
			if count+1 > max {
				max = count + 1
			}
			idx++
			i++ // Move to the next character after the delimiter
			count = 0 // Reset count for the next message
		} else {
			// Increment the count for the current message length
			count++
		}
	}

	// Check if the maximum message length exceeds the allowed length
	if max > n {
		fmt.Println("Impossible")
	} else {
		// Calculate the number of messages that can fit within the allowed length
		ans := 0
		for i := 0; i < idx; i++ {
			l := msgLength[i]

			// Combine consecutive messages if they fit within the allowed length
			for i < idx-1 && l+msgLength[i+1]+1 <= n {
				l += msgLength[i+1] + 1
				i++
			}
			ans++ // Increment the count of messages
		}
		// Output the total number of messages that can be sent
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
