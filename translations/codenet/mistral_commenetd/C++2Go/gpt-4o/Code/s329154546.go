package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, L int // Declare variables for the number of strings and their length
	fmt.Scan(&N, &L) // Read the number of strings and their length from the user
	S := make([]string, N) // Declare a slice of strings 'S' of size 'N'
	for i := 0; i < N; i++ { // Loop to read each string from the user
		fmt.Scan(&S[i]) // Read each string and store it in the slice 'S'
	}
	sort.Strings(S) // Sort the strings in ascending order using the 'sort' package
	for _, str := range S { // Loop to print each sorted string to the console
		fmt.Print(str) // Print each string without a newline
	}
	fmt.Println() // Print an empty line at the end
}

// <END-OF-CODE>
