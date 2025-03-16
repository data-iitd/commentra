
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Cube struct representing a Cube with 6 faces
type Cube struct {
	f [6]int // Array to hold the values of the cube's faces
}

// Method to roll the cube around the Z-axis
func (c *Cube) roll_z() { c.roll(1, 2, 4, 3) }

// Method to roll the cube around the Y-axis
func (c *Cube) roll_y() { c.roll(0, 2, 5, 3) }

// Method to roll the cube around the X-axis
func (c *Cube) roll_x() { c.roll(0, 1, 5, 4) }

// Method to perform a roll operation on specified faces
func (c *Cube) roll(i, j, k, l int) {
	t := c.f[i] // Store the value of face i temporarily
	c.f[i] = c.f[j]  // Move value of face j to face i
	c.f[j] = c.f[k]  // Move value of face k to face j
	c.f[k] = c.f[l]  // Move value of face l to face k
	c.f[l] = t       // Assign the temporary value to face l
}

// Function to check if two cubes are equal
func eq(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ {
		if c1.f[i]!= c2.f[i] {
			return false // Return false if any face differs
		}
	}
	return true // Return true if all faces are equal
}

// Function to check if two cubes can be made equal through rotations
func equal(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ { // Iterate through each face of the cube
		for j := 0; j < 4; j++ { // Try 4 rotations around the Z-axis
			if eq(c1, c2) {
				return true // Check if cubes are equal after rotation
			}
			c1.roll_z() // Roll the cube around the Z-axis
		}
		// Alternate rolling around Y and X axes based on the iteration index
		if i%2 == 0 {
			c1.roll_y() // Roll around Y-axis for even indices
		} else {
			c1.roll_x() // Roll around X-axis for odd indices
		}
	}
	return false // Return false if no configuration matches
}

func main() {
	c1 := Cube{} // Create two Cube objects
	c2 := Cube{}

	// Input values for the first cube's faces
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < 6; i++ {
		scanner.Scan()
		face, _ := strconv.Atoi(scanner.Text())
		c1.f[i] = face
	}
	// Input values for the second cube's faces
	for i := 0; i < 6; i++ {
		scanner.Scan()
		face, _ := strconv.Atoi(scanner.Text())
		c2.f[i] = face
	}

	// Check if the two cubes can be made equal and print the result
	if equal(c1, c2) {
		fmt.Println("Yes") // Print "Yes" if they are equal
	} else {
		fmt.Println("No") // Print "No" if they are not equal
	}
}

