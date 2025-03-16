
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers from input: h (height) and a (height per shoe)
	reader := bufio.NewReader(os.Stdin)
	hStr, _ := reader.ReadString('\n')
	h, _ := strconv.Atoi(hStr)
	aStr, _ := reader.ReadString('\n')
	a, _ := strconv.Atoi(aStr)

	// Calculate the number of shoes needed by performing integer division
	sho := h / a

	// Calculate the remaining height after accounting for full shoes
	am := h % a

	// If there is any remaining height, we need one additional shoe
	if am!= 0 {
		sho += 1 // Increment the shoe count by 1 for the remaining height
	} else {
		// No additional shoe needed if there is no remaining height
	}

	// Print the total number of shoes required
	fmt.Println(sho)
}
