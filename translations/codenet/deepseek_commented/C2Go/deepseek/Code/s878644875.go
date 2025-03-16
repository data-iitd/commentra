package main

import (
	"fmt"
)

func main() {
	var s, t [4]byte // Declare byte arrays to store input strings
	fmt.Scan(&s)     // Read the first string from the user and store it in s
	fmt.Scan(&t)     // Read the second string from the user and store it in t
	hit := 0         // Initialize a counter for hits
	for i := 0; i < 3; i++ { // Compare characters in the strings
		if s[i] == t[i] { // Increment the hit counter if characters match
			hit++
		}
	}
	fmt.Println(hit) // Print the number of matching characters
}

