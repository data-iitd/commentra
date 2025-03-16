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
	// Declare variables to store input values
	var h, w, hh, ww int

	// Read values from the standard input and store them in the variables
	fmt.Scanln(&h, &w, &hh, &ww)

	// Perform arithmetic operation to calculate the area of a rectangle
	fmt.Println((h-hh)*(w-ww))

	// Indicate that the program ended successfully
}

