package main

import (
	"fmt"
)

type Cube struct {
	f [6]int
}

func (c *Cube) rollZ() {
	c.roll(1, 2, 4, 3)
}

func (c *Cube) rollY() {
	c.roll(0, 2, 5, 3)
}

func (c *Cube) rollX() {
	c.roll(0, 1, 5, 4)
}

func (c *Cube) roll(i, j, k, l int) {
	t := c.f[i]
	c.f[i] = c.f[j]
	c.f[j] = c.f[k]
	c.f[k] = c.f[l]
	c.f[l] = t
}

func eq(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ {
		if c1.f[i] != c2.f[i] {
			return false
		}
	}
	return true
}

func equal(c1, c2 Cube) bool {
	for i := 0; i < 6; i++ {
		for j := 0; j < 4; j++ {
			if eq(c1, c2) {
				return true
			}
			c1.rollZ()
		}
		if i%2 == 0 {
			c1.rollY()
		} else {
			c1.rollX()
		}
	}
	return false
}

func main() {
	var c1, c2 Cube

	for i := 0; i < 6; i++ {
		fmt.Scan(&c1.f[i])
	}
	for i := 0; i < 6; i++ {
		fmt.Scan(&c2.f[i])
	}

	if equal(c1, c2) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
