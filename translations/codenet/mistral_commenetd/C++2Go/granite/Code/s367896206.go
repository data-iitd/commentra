

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define a struct named Cube with a public array 'f' of size 6
type Cube struct {
	f [6]int
}

// Function to roll the cube along z-axis
func (c *Cube) roll_z() {
	c.roll(1, 2, 4, 3)
}

// Function to roll the cube along y-axis
func (c *Cube) roll_y() {
	c.roll(0, 2, 5, 3)
}

// Function to roll the cube along x-axis
func (c *Cube) roll_x() {
	c.roll(0, 1, 5, 4)
}

// Function to roll the cube in a specific direction
func (c *Cube) roll(i, j, k, l int) {
	t := c.f[i]
	c.f[i] = c.f[j]
	c.f[j] = t
	t = c.f[j]
	c.f[j] = c.f[k]
	c.f[k] = t
	c.f[k] = c.f[l]
}

// Function to check if two cubes are equal
func eq(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ {
		if c1.f[i]!= c2.f[i] {
			return false
		}
	}
	return true
}

// Function to check if two cubes are equal after rolling
func equal(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ {
		for j := 0; j < 4; j++ {
			if eq(c1, c2) {
				return true
			}
			c1.roll_z()
		}
		if i%2 == 0 {
			c1.roll_y()
		} else {
			c1.roll_x()
		}
	}
	return false
}

// Main function to read the cubes' states and compare them
func main() {
	c1 := Cube{}
	c2 := Cube{}

	// Read the states of the cubes from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < 6; i++ {
		scanner.Scan()
		f, _ := strconv.Atoi(scanner.Text())
		c1.f[i] = f
	}
	for i := 0; i < 6; i++ {
		scanner.Scan()
		f, _ := strconv.Atoi(scanner.Text())
		c2.f[i] = f
	}

	// Compare the cubes and print the result
	if equal(c1, c2) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

