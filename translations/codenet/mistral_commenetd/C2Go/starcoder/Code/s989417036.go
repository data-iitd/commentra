<<<<<<< HEAD

import "fmt"

func main() {
	var a, b, c, d, e, i int
	fmt.Scanf("%d%d%d", &a, &b, &c)
	if b <= c {
		fmt.Println("NO")
		return
	}
	d = a
	e = d % b
	for i = 0; i < b; i++ {
		d = d % b
		if d == c {
			fmt.Println("YES")
			return
		} else if i!= 0 && d == c {
			fmt.Println("NO")
			return
		}
		d += a
	}
	fmt.Println("NO")
=======
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var a, b, c, d, e, i int

	// Initialize variables with input
	a, b, c = input()

	// Check if b is less than or equal to c
	if b <= c {
		// If so, print "NO" and exit
		fmt.Println("NO")
		os.Exit(0)
	}

	// Else, continue with the following logic
	else {
		// Initialize d with a and e with the remainder of a divided by b
		d = a
		e = d % b

		// Iterate through b using a for loop
		for i = 0; i < b; i++ {
			// Update d by calculating the remainder of d divided by b
			d = d % b

			// If d is equal to c, print "YES" and exit
			if d == c {
				fmt.Println("YES")
				os.Exit(0)
			}

			// If d is already equal to c and i is not the first iteration, print "NO" and exit
			else if i!= 0 && d == c {
				fmt.Println("NO")
				os.Exit(0)
			}

			// Update d by adding a
			d += a
		}
	}

	// If the loop finishes without finding c, print "NO" and exit
	fmt.Println("NO")
	os.Exit(0)
}

func input() (int, int, int) {
	// Declare variables
	var a, b, c int

	// Initialize variables with input
	fmt.Scanf("%d%d%d", &a, &b, &c)

	// Return variables
	return a, b, c
>>>>>>> 98c87cb78a (data updated)
}

