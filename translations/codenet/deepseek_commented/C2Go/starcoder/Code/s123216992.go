<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

// Step 1: Declare a function named'swap' that takes two integer pointers as arguments.
func swap(a, b *int) {
<<<<<<< HEAD
	// Step 2: Declare a temporary variable 'tmp'.
	var tmp int
	// Step 3: Assign the value pointed to by 'a' to 'tmp'.
	tmp = *a
	// Step 4: Assign the value pointed to by 'b' to the memory location pointed to by 'a'.
	*a = *b
	// Step 5: Assign the value stored in 'tmp' to the memory location pointed to by 'b'.
=======
	// Step 2: Inside the'swap' function, declare a temporary variable 'tmp'.
	tmp := *a
	// Step 3: Assign the value pointed to by 'a' to 'tmp'.
	*a = *b
	// Step 4: Assign the value pointed to by 'b' to the memory location pointed to by 'a'.
>>>>>>> 98c87cb78a (data updated)
	*b = tmp
}

func main() {
<<<<<<< HEAD
	// Step 6: Declare two integer variables 'a' and 'b'.
	var a, b int
	// Step 7: Create an infinite loop using 'for {'.
	for {
		// Step 8: Use 'fmt.Scanf' to read two integers from the user and store them in 'a' and 'b'.
		fmt.Scanf("%d %d", &a, &b)
		// Step 9: Check if both 'a' and 'b' are zero. If true, break the loop.
		if a == 0 && b == 0 {
			break
		}
		// Step 10: Check if 'b' is less than 'a'. If true, call the'swap' function to swap the values of 'a' and 'b'.
		if b < a {
			swap(&a, &b)
		}
		// Step 11: Print the values of 'a' and 'b'.
=======
	// Step 5: In the'main' function, declare two integer variables 'a' and 'b'.
	for {
		var a, b int
		fmt.Scanf("%d %d", &a, &b)
		if a == 0 && b == 0 {
			break
		}
		if b < a {
			swap(&a, &b)
		}
>>>>>>> 98c87cb78a (data updated)
		fmt.Printf("%d %d\n", a, b)
	}
}

