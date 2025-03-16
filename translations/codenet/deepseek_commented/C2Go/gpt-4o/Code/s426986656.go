package main  // Declare the main package

import (
	"fmt"  // Import the fmt package for formatted I/O
)

func main() {
	var A, B int  // Declare integer variables A and B
	var flag int  // Declare an integer variable flag

	fmt.Scanf("%d %d", &A, &B)  // Read input values for A and B

	// Loop through numbers 1 to 3 to check if the product of A, B, and i is odd
	for i := 1; i <= 3; i++ {
		if (A*B*i)%2 == 1 {  // Check if the product is odd
			flag = 1  // Set flag to 1 if an odd product is found
			break  // Break out of the loop
		}
	}

	if flag == 1 {
		fmt.Println("Yes")  // Print "Yes" if an odd product was found
	} else {
		fmt.Println("No")  // Print "No" if no odd product was found
	}
}
