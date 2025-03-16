
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to find the greatest common divisor of two numbers
func getGCD ( a, b int ) int {
	if b == 0 { // Base case: if b is 0, return a as the gcd
		return a
	} else {
		return getGCD ( b, a % b ) // Recursive call: finding the gcd of b and the remainder of a divided by b
	}
}

func main ( ) {
	sc := bufio.NewScanner ( os.Stdin ) ; // Creating a new Scanner object to read input
	sc.Split ( bufio.ScanWords ) ; // Defining the split function to split the input by words

	var n, m int ; // Declaring two variables n and m to store the number of elements in the array and the value of m
	var a [ ] int ; // Declaring an integer array a to store the array elements

	fmt.Fscan ( os.Stdin, &n ) ; // Reading the first integer n from the standard input
	fmt.Fscan ( os.Stdin, &m ) ; // Reading the second integer m from the standard input

	// Initializing the array a with input values
	for i := 0 ; i < n ; i ++ {
		var temp int ; // Declaring a temporary variable to store the input value
		fmt.Fscan ( os.Stdin, &temp ) ; // Reading an integer value
		a [ i ] = temp / 2 ; // Dividing the input value by 2 before storing it in the array
	}

	var gcd, lcd int = 1, 1 ; // Declaring two variables gcd and lcm to store the greatest common divisor and the least common multiple

	// Finding the least common multiple of all array elements
	for i := 0 ; i < n ; i ++ {
		gcd = getGCD ( lcd, a [ i ] ) ; // Finding the greatest common divisor of lcm and the current array element
		lcd = lcd * a [ i ] / gcd ; // Updating the value of lcm

		// Checking if lcm is greater than m
		if lcd > m {
			fmt.Println ( 0 ) ; // If true, printing 0 and returning from the method
			return
		}
	}

	// Checking if any array element is a factor of lcm
	for i := 0 ; i < n ; i ++ {
		if ( lcd / a [ i ] ) % 2 == 0 { // Checking if the remainder of lcm divided by the current array element is 0 and even
			fmt.Println ( 0 ) ; // If true, printing 0 and returning from the method
			return
		}
	}

	// Printing the result
	fmt.Println ( ( m / lcd + 1 ) / 2 )
}

