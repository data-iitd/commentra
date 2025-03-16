
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	// Read the input word from the standard input stream using bufio
	reader := bufio.NewReader(os.Stdin)
	W, _ := reader.ReadString('\n')

	// Sort the characters in the string W in ascending order using the sort function from the sort package
	sort.Strings(strings.Split(W, ""))

	// Initialize a string iterator named itr to point to the first character in the sorted string W
	itr := 0

	// Loop through the sorted string W using a for loop, with the loop condition that itr does not point to the end of the string
	for itr < len(W)-1 {
		// Check if the current character and the next character in the string are the same
		if W[itr]!= W[itr+1] {
			// If they are not the same, print "No" to the standard output stream and return from the main function
			fmt.Println("No")
			return
		}
		// Increment the iterator
		itr++
	}

	// If the loop completes without finding any pair of non-identical characters, print "Yes" to the standard output stream
	fmt.Println("Yes")
}

