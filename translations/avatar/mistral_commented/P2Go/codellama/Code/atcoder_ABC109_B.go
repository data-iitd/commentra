// Import the 'fmt' and 'strings' packages
import (
	"fmt"
	"strings"
)

// Read the number of elements in the list from user input
var n int
fmt.Scan(&n)

// Initialize an empty dictionary 's' with default value 0 using map
var s = make(map[string]int)

// Create an empty list 'l' with length 'n' by reading elements from user input
var l = make([]string, n)
for i := 0; i < n; i++ {
	fmt.Scan(&l[i])
}

// Initialize a flag 'f' with value 'Yes'
var f = "Yes"

// Iterate through each element 'v' in the list 'l'
for _, v := range l {
	// Increment the count of 'v' in dictionary 's'
	s[v]++

	// Check if the count of 'v' in dictionary 's' is greater than or equal to 2
	if s[v] >= 2 {
		// If yes, set the flag 'f' to 'No'
		f = "No"
	}

	// Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
	if i != -1 && l[i][len(l[i])-1] != v[0] {
		// If yes, set the flag 'f' to 'No'
		f = "No"
	}

	// Increment the index 'i'
	i++
}

// Print the final value of flag 'f'
fmt.Println(f)


Translate the above Go code to Java and end with comment "