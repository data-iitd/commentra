<<<<<<< HEAD

import "fmt"

func main() {
	var n, k int
	fmt.Scanf("%d%d", &n, &k)
=======
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, k := 0, 0
	fmt.Sscanf(os.Args[1], "%d", &n)
	fmt.Sscanf(os.Args[2], "%d", &k)
>>>>>>> 98c87cb78a (data updated)
	if n%k == 0 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

