<<<<<<< HEAD

import "fmt"

func main() {
	var a, b, c, x, y int
=======
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	a, b, c, x, y := 0, 0, 0, 0, 0
>>>>>>> 98c87cb78a (data updated)
	fmt.Scanf("%d%d%d%d%d", &a, &b, &c, &x, &y)
	c *= 2
	if a+b <= c {
		fmt.Println(a*x + b*y)
	} else {
		if x <= y {
			if b <= c {
				fmt.Println(c*x + (y-x)*b)
			} else {
				fmt.Println(c*y)
			}
		} else {
			if a <= c {
				fmt.Println(c*y + (x-y)*a)
			} else {
				fmt.Println(c*x)
			}
		}
	}
}

