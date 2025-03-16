
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

func main() {
	// Declare a character array 'c' of size 26 to store the count of each character.
	c := make([]int, 26)
<<<<<<< HEAD

	// Use a loop to read strings from the standard input using bufio.ScanWords() until the end of file is reached.
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Use a loop to traverse the string'str'.
		for _, r := range strings.ToLower(scanner.Text()) {
			// Use nested if conditions to check if the current character is a lowercase or uppercase letter.
			if 'a' <= r && r <= 'z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[r-'a']++
			} else if 'A' <= r && r <= 'Z' {
				// Increment the count of the corresponding character in the 'c' array.
				c[r-'A']++
=======
	// Declare a character array'str' of size 1200 to store the input string.
	str := make([]byte, 1200)
	// Declare a pointer 'p' to traverse the string'str'.
	p := str
	// Use a loop to read strings from the standard input using bufio.Scanln() until the end of file is reached.
	for bufio.Scanln(str) > 0 {
		// Use a loop to traverse the string'str' and increment the count of each character in the 'c' array.
		for p = str; *p!= 0; p++ {
			if 'a' <= *p && *p <= 'z' {
				c[*p-'a']++
			} else if 'A' <= *p && *p <= 'Z' {
				c[*p-'A']++
>>>>>>> 98c87cb78a (data updated)
			}
		}
	}
	// Use a loop to print the count of each character and its corresponding character.
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

