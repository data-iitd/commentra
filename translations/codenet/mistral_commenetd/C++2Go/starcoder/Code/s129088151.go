
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Declare variables
var n int
var str string
var com string
var T map[string]bool

func main() {
	// Read the number of input pairs from the standard input
	fmt.Scanf("%d", &n)

	// Iterate through each input pair
	for i := 0; i < n; i++ {
		// Read the command and the string from the standard input
		fmt.Scanf("%s%s", &com, &str)

		// If the command is 'i', add the string to the map with a value of true
		if com[0] == 'i' {
			T[str] = true
		}
		// If the command is not 'i', check if the string is present in the map and print the result accordingly
		else {
			if T[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

