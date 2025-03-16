
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

// Define a struct named Cube with a public array 'f' of size 6
type Cube struct {
	f [6]int
}

// Function to check if two cubes are equal
func eq(c1 Cube, c2 Cube) bool {
	for i := 0; i < 6; i++ { // Iterate through each element of the first cube 'c1'
		if c1.f[i]!= c2.f[i] { // If any element is not equal, return false
			return false
		}
	}
	return true // If all elements are equal, return true
}

// Function to check if two cubes are equal after rolling
func equal(c1 Cube, c2 Cube) bool {
	for i := 0; i < 6; i++ { // Iterate through each rolling direction for the first cube 'c1'
		for j := 0; j < 4; j++ { // Iterate through each rolling step in the current direction
			if eq(c1, c2) { // If the cubes are equal, return true
				return true
			}
			c1.roll_z() // Roll the cube along z-axis
		}
		if i%2 == 0 {
			c1.roll_y() // Roll the cube along y-axis if the current index 'i' is even
		} else {
			c1.roll_x() // Roll the cube along x-axis if the current index 'i' is odd
		}
	}
	return false // If the cubes are not equal after all rolling directions and steps, return false
}

// Main function to read the cubes' states and compare them
func main() {
	var c1, c2 Cube // Initialize two empty cubes 'c1' and 'c2'

	// Read the states of the cubes from the standard input
	reader := bufio.NewReader(os.Stdin)
	for i := 0; i < 6; i++ {
		text, _ := reader.ReadString('\n')
		text = strings.TrimSpace(text)
		c1.f[i], _ = strconv.Atoi(text)
	}
	for i := 0; i < 6; i++ {
		text, _ := reader.ReadString('\n')
		text = strings.TrimSpace(text)
		c2.f[i], _ = strconv.Atoi(text)
	}

	// Compare the cubes and print the result
	if equal(c1, c2) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

