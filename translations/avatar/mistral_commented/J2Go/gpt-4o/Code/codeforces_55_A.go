package main

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() {
	var n, i, k, p int // Declaring variables
	var flag bool = true // Initializing the boolean variable 'flag' to true
	a := make([]int, 1000) // Declaring and initializing an integer slice of size 1000

	fmt.Scan(&n) // Reading the first integer from the standard input stream and assigning it to the variable 'n'

	i = 1 // Initializing the variable 'i' to 1
	k = 0 // Initializing the variable 'k' to 0
	p = 1 // Initializing the variable 'p' to 1

	for k <= n { // Starting a for loop that runs as long as 'k' is less than or equal to 'n'
		i += k // Incrementing the variable 'i' by the value of 'k'

		if i >= n { // Checking if the value of 'i' is greater than or equal to 'n'
			for i >= n { // If yes, then decrement 'i' by 'n' until it becomes less than 'n'
				i -= n
			}
		}

		a[i]++ // Incrementing the value of the 'i'-th element of the slice 'a' by 1
		k++ // Incrementing the variable 'k' by 1
	}

	for i = 0; i < n; i++ { // Starting a for loop that runs from 0 to 'n'-1
		if a[i] == 0 { // Checking if the 'i'-th element of the slice 'a' is equal to 0
			flag = false // If yes, then set the boolean variable 'flag' to false
			break // Exiting the for loop
		}
	}

	if flag { // If the boolean variable 'flag' is still true after the for loop
		fmt.Println("YES") // Print "YES" to the standard output stream
	} else {
		fmt.Println("NO") // Otherwise, print "NO" to the standard output stream
	}
}

// <END-OF-CODE>
