<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare and initialize variables
	var n int

	// Read an integer value from the user
	fmt.Print("Enter the number of integers: ")
	fmt.Scanf("%d", &n)

	cnt4 := 0
	cnt2 := 0

	// Iterate through each integer input
	for i := 0; i < n; i++ {
		var wk int

		// Read an integer value from the user
		fmt.Print("Enter an integer: ")
		fmt.Scanf("%d", &wk)

		// Check if the current integer is a multiple of 4
		if wk%4 == 0 {
			cnt4++
		} else if wk%2 == 0 {
			cnt2++
		}
	}

	// Check the condition to determine the output
	if cnt4+cnt2/2 >= n/2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

