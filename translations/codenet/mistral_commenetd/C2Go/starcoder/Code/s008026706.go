
<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b, x, y int
=======
package main

import "fmt"

func main() {
	var a, b, x, y int

>>>>>>> 98c87cb78a (data updated)
	fmt.Scanf("%d%d", &a, &b)
	x = 2*a + 2*b
	y = a*b
	fmt.Printf("%d %d\n", y, x)
}

