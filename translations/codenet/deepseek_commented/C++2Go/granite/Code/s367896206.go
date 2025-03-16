
package main

import "fmt"

// Represents a cube with six faces, each face having an integer value.
type Cube struct {
	f [6]int
}

// Rotates the cube around the z-axis.
func (c *Cube) roll_z() { c.roll(1, 2, 4, 3) }

// Rotates the cube around the y-axis.
func (c *Cube) roll_y() { c.roll(0, 2, 5, 3) }

// Rotates the cube around the x-axis.
func (c *Cube) roll_x() { c.roll(0, 1, 5, 4) }

// Helper method to rotate the cube by swapping the values of the faces.
func (c *Cube) roll(i, j, k, l int) {
	t := c.f[i]
	c.f[i] = c.f[j]
	c.f[j] = c.f[k]
	c.f[k] = c.f[l]
	c.f[l] = t
}

func main() {
	c := Cube{f: [6]int{1, 2, 3, 4, 5, 6}}
	c.roll_z()
	fmt.Println(c.f)
}

// 