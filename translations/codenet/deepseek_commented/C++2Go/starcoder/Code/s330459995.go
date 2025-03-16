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

// The main function starts here
func main() {
	// Declare variables to store the dimensions of the rectangle and the circle
	var W, H, x, y, r int

	// Read the dimensions of the rectangle and the circle from the input
	fmt.Scanf("%d %d %d %d %d", &W, &H, &x, &y, &r)

	// Check if the circle is outside the rectangle
	if x-r < 0 || x+r > W || y-r < 0 || y+r > H {
		// If any part of the circle is outside the rectangle, print "No"
		fmt.Println("No")
	} else {
		// If the circle is completely inside the rectangle, print "Yes"
		fmt.Println("Yes")
	}
}

