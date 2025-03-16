package main  // Step 1: Declare the main package.

import (  // Step 2: Import the necessary packages.
	"fmt"  // For formatted I/O.
)

func swap(a *int, b *int) {  // Step 3: Define a function named 'swap' that takes two integer pointers as arguments.
	tmp := *a  // Step 4: Inside the 'swap' function, declare a temporary variable 'tmp' and assign the value pointed to by 'a' to 'tmp'.
	*a = *b  // Step 5: Assign the value pointed to by 'b' to the memory location pointed to by 'a'.
	*b = tmp  // Step 6: Assign the value stored in 'tmp' to the memory location pointed to by 'b'.
}

func main() {  // Step 7: In the 'main' function, declare two integer variables 'a' and 'b'.
	for {  // Step 8: Create an infinite loop using 'for'.
		var a, b int  // Step 9: Declare two integer variables 'a' and 'b'.
		fmt.Scanf("%d %d", &a, &b)  // Step 9: Use 'Scanf' to read two integers from the user and store them in 'a' and 'b'.
		if a == 0 && b == 0 { break }  // Step 10: Check if both 'a' and 'b' are zero. If true, break the loop.
		if b < a { swap(&a, &b) }  // Step 11: Check if 'b' is less than 'a'. If true, call the 'swap' function to swap the values of 'a' and 'b'.
		fmt.Printf("%d %d\n", a, b)  // Step 12: Print the values of 'a' and 'b'.
	}
}  // Step 13: End the 'main' function.

