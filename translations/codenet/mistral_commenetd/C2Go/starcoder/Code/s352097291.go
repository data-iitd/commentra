
<<<<<<< HEAD

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    // Initialize variables
    var c string
    fmt.Scanf("%s", &c) // Read a string from the standard input and store it in the 'c' variable

    // Process the string
    for i := 0; c[i]!= '\0'; i++ { // Iterate through each character in the string 'c'
        if c[i]!= 'B' { // If the current character is not 'B'
            fmt.Print(c[i]) // Print the character
        } else { // If the current character is 'B'
            fmt.Print(strings.TrimSuffix(fmt.Sprint(c[:i]), string("B"))) // Remove the last character from the output string 'ans'
        }
    }

    // Print the output
    fmt.Println() // Print a new line
=======
package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	// Initialize variables
	var c string
	fmt.Scanf("%s", &c)

	// Process the string
	var ans string
	for i := 0; c[i]!= '\0'; i++ {
		if c[i]!= 'B' {
			ans += c[i:i+1]
		} else {
			ans = ans[:len(ans)-1]
		}
	}

	// Print the output
	fmt.Printf("%s\n", ans)
>>>>>>> 98c87cb78a (data updated)
}

// The comments explain the purpose of each logical block and make the code more readable.

<<<<<<< HEAD
=======
Translate the above Go code to Python and end with comment "
>>>>>>> 98c87cb78a (data updated)
