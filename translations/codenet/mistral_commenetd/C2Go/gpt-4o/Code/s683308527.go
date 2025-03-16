package main // Declare the main package

import (
	"bufio" // Import bufio for buffered I/O
	"fmt"   // Import fmt for formatted I/O
	"strings" // Import strings for string manipulation
)

func main() { // Start of the main function
	var n int // Declare an integer variable 'n' to store the number of strings to be processed
	reader := bufio.NewReaderSize(os.Stdin, 10010) // Create a buffered reader
	fmt.Scanf("%d\n", &n) // Read an integer 'n' from the standard input

	for i := 0; i < n; i++ { // Start of the for loop that processes each string
		s, _ := reader.ReadString('\n') // Read a string from the standard input

		for strings.Contains(s, "Hoshino") { // Start of the inner loop that replaces the substring "Hoshino" with "aana"
			s = strings.Replace(s, "Hoshino", "aaan", 1) // Replace the first occurrence of "Hoshino" with "aaan"
		}

		fmt.Print(s) // Print the modified string to the standard output
	}
}

// <END-OF-CODE>
