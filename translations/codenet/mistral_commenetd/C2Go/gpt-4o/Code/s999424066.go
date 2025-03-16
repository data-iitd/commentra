package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Start of the main function
	var a, b, c, x, y int // Declare variables a, b, c, x, and y as integers
	fmt.Scanf("%d%d%d%d%d", &a, &b, &c, &x, &y) // Read five integers from the standard input and store them in variables a, b, c, x, and y

	c *= 2 // Multiply the value of variable c by 2

	if a+b <= c { // Check if the sum of variables a and b is less than or equal to the value of variable c
		fmt.Println(a*x + b*y) // If the condition is true, print the result of multiplying variables a and x, and variables b and y
	} else { // If the condition in the if statement is false, execute the code in the else block

		if x <= y { // Check if the value of variable x is less than or equal to the value of variable y

			if b <= c { // Check if the value of variable b is less than or equal to the value of variable c
				fmt.Println(c*x + (y-x)*b) // If both conditions in the nested if statement are true, print the result
			} else { // If the first condition in the nested if statement is false, execute the code in this else block
				fmt.Println(c * y) // Print the result of multiplying variable c by the value of variable y
			}

		} else { // If the condition in the outer if statement is false and the condition in the if statement that checks if x is less than or equal to y is also false, execute the code in this else block

			if a <= c { // Check if the value of variable a is less than or equal to the value of variable c
				fmt.Println(c*y + (x-y)*a) // If the condition is true, print the result
			} else { // If the condition in the if statement that checks if a is less than or equal to c is false, execute the code in this else block
				fmt.Println(c * x) // Print the result of multiplying variable c by the value of x
			}

		} // End of the else statement that checks if x is greater than y

	} // End of the else statement that checks if the sum of a and b is greater than c

} // End of the main function

// <END-OF-CODE>
