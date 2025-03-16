<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, b, c, d, e, max int
	fmt.Fscan(os.Stdin, &a, &b)
	c = a + b
	d = a - b
	e = a * b
	max = c
	if max < d {
		max = d
	}
	if max < e {
		max = e
	}
	fmt.Println(max)
}

