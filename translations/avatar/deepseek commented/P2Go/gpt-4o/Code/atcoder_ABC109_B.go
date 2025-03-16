package main

import (
	"fmt"
)

func main() {
	// Step 1: Import necessary packages.
	
	// Step 2: Take an integer input n which represents the number of strings.
	var n int
	fmt.Scan(&n)

	// Step 3: Initialize a map to count occurrences of strings.
	s := make(map[string]int)

	// Step 4: Create a slice l by taking n inputs from the user.
	l := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	// Step 5: Initialize a variable f to "Yes" to keep track of the validity of the sequence.
	f := "Yes"

	// Step 6: Initialize a variable i to -1 to keep track of the index of the current string in the list.
	i := -1

	// Step 7: Enter a for loop to iterate over each string v in the list l.
	for _, v := range l {
		// Step 8: Increment the count of the current string v in the map s.
		s[v]++

		// Step 9: If the count of v becomes 2 or more, set f to "No".
		if s[v] >= 2 {
			f = "No"
		}

		// Step 10: If i is not -1 and the last character of the previous string is not the same as the first character of the current string, set f to "No".
		if i != -1 && l[i][len(l[i])-1] != v[0] {
			f = "No"
		}

		// Step 11: Increment the index i after processing each string.
		i++
	}

	// Step 12: Print the value of f, which indicates whether the sequence is valid or not.
	fmt.Println(f)
}

// <END-OF-CODE>
