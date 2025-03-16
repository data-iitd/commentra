/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
package main
import (
	"fmt" // Include the fmt library for formatting output
	"math" // Include the math library for mathematical functions
	"sort" // Include the sort library for sorting
	"strconv" // Include the strconv library for converting strings to integers
	"strings" // Include the strings library for string manipulation
)

func solve() {
	var n int // Declare a variable for the input number
	fmt.Scan(&n) // Read the input number
	fmt.Println(!n) // Output the boolean negation of n
}

func main() {
	var n = 1 // Initialize n with 1 (commented out as it's overridden)
	for n > 0 { // Run the solve function in a loop with n=1
		solve()
		n--
	}
}

