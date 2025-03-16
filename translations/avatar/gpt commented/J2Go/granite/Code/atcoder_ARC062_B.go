
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the input string S
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	score := 0 // Initialize score to zero

	// Iterate through each character in the string S
	for i := 0; i < len(s); i++ {
		// Determine the character for'my' based on the index (even or odd)
		my := "gp"[i%2]

		// Get the character from the input string at the current index
		his := s[i]

		// Compare'my' and 'his' characters to update the score
		if my!= his {
			// Increment score if'my' is 'p', otherwise decrement
			score += int(my == 'p') - int(my == 'g')
		}
	}

	// Output the final score
	fmt.Fprintln(writer, score)

	// Flush the output
	writer.Flush()
}

// END-OF-CODE