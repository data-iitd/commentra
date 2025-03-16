package main

import (
	"fmt"
)

// Define a struct named Cube with a public array 'f' of size 6
type Cube struct {
	f [6]int // Initialize an integer array 'f' of size 6
}

// Method to roll the cube along z-axis
func (c *Cube) rollZ() {
	c.roll(1, 2, 4, 3)
}

// Method to roll the cube along y-axis
func (c *Cube) rollY() {
	c.roll(0, 2, 5, 3)
}

// Method to roll the cube along x-axis
func (c *Cube) rollX() {
	c.roll(0, 1, 5, 4)
}

// Method to roll the cube in a specific direction
func (c *Cube) roll(i, j, k, l int) {
	t := c.f[i] // Swap the values of 'f[i]' and 'f[j]'
	c.f[i] = c.f[j]
	c.f[j] = t // Swap the values of 'f[j]' and 't'
}

// Function to check if two cubes are equal
func eq(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ { // Iterate through each element of the first cube 'c1'
		if c1.f[i] != c2.f[i] { // If any element is not equal, return false
			return false
		}
	}
	return true // If all elements are equal, return true
}

// Function to check if two cubes are equal after rolling
func equal(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ { // Iterate through each rolling direction for the first cube 'c1'
		for j := 0; j < 4; j++ { // Iterate through each rolling step in the current direction
			if eq(c1, c2) { // If the cubes are equal, return true
				return true
			}
			c1.rollZ() // Roll the cube along z-axis
		}
		if i%2 == 0 {
			c1.rollY() // Roll the cube along y-axis if the current index 'i' is even
		} else {
			c1.rollX() // Roll the cube along x-axis if the current index 'i' is odd
		}
	}
	return false // If the cubes are not equal after all rolling directions and steps, return false
}

// Main function to read the cubes' states and compare them
func main() {
	var c1, c2 Cube // Initialize two empty cubes 'c1' and 'c2'

	// Read the states of the cubes from the standard input
	for i := 0; i < 6; i++ {
		fmt.Scan(&c1.f[i])
	}
	for i := 0; i < 6; i++ {
		fmt.Scan(&c2.f[i])
	}

	// Compare the cubes and print the result
	if equal(c1, c2) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
