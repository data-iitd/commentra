
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Cube struct {
	f [6]int
}

func (c *Cube) roll_z() {
	c.roll(1, 2, 4, 3)
}

func (c *Cube) roll_y() {
	c.roll(0, 2, 5, 3)
}

func (c *Cube) roll_x() {
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
		if c1.f[i]!= c2.f[i] {
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

func main() {
	c1 := Cube{}
	c2 := Cube{}

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

	if equal(c1, c2) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
