<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var x, y, z int
	fmt.Scanf("%d %d", &x, &y)
	if x >= y {
		z = you(x, y)
	} else {
		z = you(y, x)
	}
	fmt.Println(z)
}

func you(x, y int) int {
	var z int
	for {
		z = x % y
		x = y
		y = z
		if y <= 0 {
			break
		}
	}
	return x
}

