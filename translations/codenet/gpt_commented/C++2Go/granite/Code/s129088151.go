
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables for input and a map to store string entries
	var n int // Number of commands to process
	var str, com string // Variables to hold command and string inputs
	T := make(map[string]bool) // Map to track the presence of strings (true if present)

	// Read the number of commands from input
	reader := bufio.NewReader(os.Stdin)
	n, _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])

	// Loop through each command
	for i := 0; i < n; i++ {
		// Read the command and the associated string
		input := strings.Split(reader.ReadLine(), " ")
		com = input[0]
		str = input[1]

		// Check if the command is 'insert' (indicated by the first character being 'i')
		if com[0] == 'i' {
			// Insert the string into the map with a value of true
			T[str] = true
		} else {
			// If the command is not 'insert', check if the string exists in the map
			if T[str] {
				// If the string exists, print "yes"
				fmt.Println("yes")
			} else {
				// If the string does not exist, print "no"
				fmt.Println("no")
			}
		}
	}
}

