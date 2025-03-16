<<<<<<< HEAD

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n uint64
    fmt.Scanf("%d", &n)
    b := n * (n - 1) / 2
    fmt.Printf("%d\n", b)
=======
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n uint64
	fmt.Scanf("%d", &n)
	b := n*(n-1)/2
	fmt.Printf("%d\n", b)
>>>>>>> 98c87cb78a (data updated)
}

