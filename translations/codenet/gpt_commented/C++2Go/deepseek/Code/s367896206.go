package main

import (
	"fmt"
)

// Cube represents a cube with 6 faces
type Cube struct {
	f [6]int // Array to hold the values of the cube's faces
}

// rollZ performs a roll operation around the Z-axis
func (c *Cube) rollZ() {
	c.roll(1, 2, 4, 3)
}

// rollY performs a roll operation around the Y-axis
func (c *Cube) rollY() {
	c.roll(0, 2, 5, 3)
}

// rollX performs a roll operation around the X-axis
func (c *Cube) rollX() {
	c.roll(0, 1, 5, 4)
}

// roll performs a roll operation on specified faces
func (c *Cube) roll(i, j, k, l int) {
	t := c.f[i] // Store the value of face i temporarily
	c.f[i] = c.f[j]  // Move value of face j to face i
	c.f[j] = c.f[k]  // Move value of face k to face j
	c.f[k] = c.f[l]  // Move value of face l to face k
	c.f[l] = t       // Assign the temporary value to face l
}

// eq checks if two cubes are equal
func eq(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ {
		if c1.f[i] != c2.f[i] {
			return false // Return false if any face differs
		}
	}
	return true // Return true if all faces are equal
}

// equal checks if two cubes can be made equal through rotations
func equal(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ { // Iterate through each face of the cube
		for j := 0; j < 4; j++ { // Try 4 rotations around the Z-axis
			if eq(c1, c2) {
				return true // Check if cubes are equal after rotation
			}
			c1.rollZ() // Roll the cube around the Z-axis
		}
		// Alternate rolling around Y and X axes based on the iteration index
		if i%2 == 0 {
			c1.rollY() // Roll around Y-axis for even indices
		} else {
			c1.rollX() // Roll around X-axis for odd indices
		}
	}
	return false // Return false if no configuration matches
}

func main() {
	var c1, c2 Cube // Create two Cube objects

	// Input values for the first cube's faces
	for i := 0; i < 6; i++ {
		fmt.Scan(&c1.f[i])
	}
	// Input values for the second cube's faces
	for i := 0; i < 6; i++ {
		fmt.Scan(&c2.f[i])
	}

	// Check if the two cubes can be made equal and print the result
	if equal(c1, c2) {
		fmt.Println("Yes") // Print "Yes" if they are equal
	} else {
		fmt.Println("No") // Print "No" if they are not equal
	}
}

