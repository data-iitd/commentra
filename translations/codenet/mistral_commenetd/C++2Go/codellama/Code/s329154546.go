package main

import (
	"fmt"
	"sort"
)

func main() {
	var L, N int // Declare variables for the length of the string and the number of strings
	fmt.Scan(&N, &L) // Read the number of strings and their length from the user
	S := make([]string, N) // Declare an array of strings 'S' of size 'N'
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i]) // Read each string from the user and store it in the array 'S'
	}
	sort.Strings(S) // Sort the strings in ascending order using the 'sort' function
	for i := 0; i < N; i++ {
		fmt.Println(S[i]) // Print each sorted string to the console
	}
	fmt.Println() // Print an empty line at the end
}

