<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"strings"
)
func main() {
	// Step 1: Read a string from the user
	var s string
	fmt.Scanln(&s)
	
	// Step 2: Iterate through each letter from 'a' to 'z'
	for i := 'a'; i <= 'z'; i++ {
		// Step 3: Count how many times the current letter appears in the input string
		a := strings.Count(s, string(i))
		
		// Step 4: If the letter does not appear in the input string, print it and break out of the loop
		if a == 0 {
			fmt.Println(string(i))
			break
		} 
		
		// Step 5: If all letters from 'a' to 'z' appear in the input string, print "None"
		if i == 'z' {
			fmt.Println("None")
			break
		}
	}
}
