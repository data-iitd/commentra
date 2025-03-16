package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int  // Declare number of rounds
	fmt.Scan(&n)  // Read the number of rounds
	t := make([]string, n)  // Declare Tarō's strings
	h := make([]string, n)  // Declare Hanako's strings
	var taro, hanako int  // Declare scores

	// Loop through each round
	for i := 0; i < n; i++ {
		fmt.Scan(&t[i])  // Read Tarō's string
		fmt.Scan(&h[i])  // Read Hanako's string
		if strings.Compare(t[i], h[i]) < 0 {  // Compare and update Hanako's score
			hanako += 3
		}
		if strings.Compare(t[i], h[i]) > 0 {  // Compare and update Tarō's score
			taro += 3
		}
		if strings.Compare(t[i], h[i]) == 0 {  // If strings are equal
			taro += 1  // Increment Tarō's score by 1
			hanako += 1  // Increment Hanako's score by 1
		}
	}

	fmt.Println(taro, hanako)  // Print the final scores
}

