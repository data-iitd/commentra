package main

import "fmt"

// Class representing a Cube with 6 faces
type Cube struct {
	f [6]int // Array to hold the values of the cube's faces
}

// Default constructor
func NewCube() *Cube {
	return &Cube{}
}

// Method to roll the cube around the Z-axis
func (c *Cube) RollZ() {
	c.Roll(1, 2, 4, 3)
}

// Method to roll the cube around the Y-axis
func (c *Cube) RollY() {
	c.Roll(0, 2, 5, 3)
}

// Method to roll the cube around the X-axis
func (c *Cube) RollX() {
	c.Roll(0, 1, 5, 4)
}

// Method to perform a roll operation on specified faces
func (c *Cube) Roll(i, j, k, l int) {
	t := c.f[i] // Store the value of face i temporarily
	c.f[i] = c.f[j]  // Move value of face j to face i
	c.f[j] = c.f[k]  // Move value of face k to face j
	c.f[k] = c.f[l]  // Move value of face l to face k
	c.f[l] = t     // Assign the temporary value to face l
}

// Function to check if two cubes are equal
func Eq(c1, c2 *Cube) bool {
	for i := 0; i < 6; i++ {
		if c1.f[i] != c2.f[i] {
			return false
		}
	}
	return true
}

// Function to check if two cubes can be made equal through rotations
func Equal(c1, c2 *Cube) bool {
	for i := 0; i < 6; i++ {
		for j := 0; j < 4; j++ {
			if Eq(c1, c2) {
				return true
			}
			c1.RollZ()
		}
		if i % 2 == 0 {
			c1.RollY()
		} else {
			c1.RollX()
		}
	}
	return false
}

func main() {
	c1 := NewCube()
	c2 := NewCube()

	// Input values for the first cube's faces
	for i := 0; i < 6; i++ {
		fmt.Scan(&c1.f[i])
	}
	// Input values for the second cube's faces
	for i := 0; i < 6; i++ {
		fmt.Scan(&c2.f[i])
	}

	// Check if the two cubes can be made equal and print the result
	if Equal(c1, c2) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

