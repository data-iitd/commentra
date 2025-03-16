package main

import (
	"fmt"
)

func main() {
	var str [4]string // Define an array of strings named str with a length of 4 to store the input strings
	var i int = -1    // Initialize an integer variable i to -1

	for i != 3 { // Enter a loop that continues as long as i is not equal to 3
		i++ // Increment i by 1
		fmt.Scan(&str[i]) // Read the next input string and store it in the str array at index i
	}

	var u int = -1 // Initialize an integer variable u to -1

	for u != 2 { // Enter an outer loop that continues as long as u is not equal to 2
		u++ // Increment u by 1

		yes := 0 // Initialize an integer variable yes to 0
		var j int = -1 // Initialize an integer variable j to -1

		for j != 2 { // Enter an inner loop that continues as long as j is not equal to 2
			j++ // Increment j by 1

			if (str[u][j] == str[u][j+1] && (str[u+1][j] == str[u][j] || str[u+1][j+1] == str[u][j])) ||
				(str[u+1][j] == str[u+1][j+1] && (str[u][j] == str[u+1][j] || str[u][j+1] == str[u+1][j])) {
				yes = 1 // Set the yes variable to 1 if the condition is true
				fmt.Println("YES") // Print "YES" to the standard output if the condition is true
				break // Break out of the inner loop if the condition is true
			}
		}

		if yes == 1 { // If the yes variable is set to 1, break out of the outer loop
			break
		}

		if yes == 0 { // If the yes variable is still equal to 0, print "NO" to the standard output
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
