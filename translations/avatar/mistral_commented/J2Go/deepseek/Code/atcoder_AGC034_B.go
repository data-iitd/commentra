package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Main function that starts the program
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var s string
	fmt.Fscan(reader, &s)

	cnt := int64(0)
	tmp := int64(0)

	for _, char := range s {
		// Loop through each character in the string
		if char == 'A' {
			// If the character is "A", increment the temporary counter
			tmp++
		} else if char == 'D' {
			// If the character is "D", add the temporary counter to the total count
			cnt += tmp
		} else {
			// If the character is neither "A" nor "D", reset the temporary counter
			tmp = 0
		}
	}

	// Print the result
	fmt.Fprintln(writer, cnt)
}

