<<<<<<< HEAD

import (
	"fmt"
	"sort"
)

func main() {
	// Read three integers from the standard input
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)

	// Sort the integers in ascending order
	sort.Ints([]int{a, b, c})

	// Print the sorted integers
	fmt.Printf("%d %d %d\n", a, b, c)
=======
package main

import (
    "fmt"
    "sort"
)

func main() {
    var a, b, c int
    fmt.Scanf("%d %d %d", &a, &b, &c)

    if a > b {
        a, b = b, a
    }
    if b > c {
        b, c = c, b
    }
    if a > b {
        a, b = b, a
    }

    fmt.Printf("%d %d %d\n", a, b, c)
>>>>>>> 98c87cb78a (data updated)
}

