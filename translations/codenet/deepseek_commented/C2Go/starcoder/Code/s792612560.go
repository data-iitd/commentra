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
	var n int
	var m uint64
	fmt.Scanf("%d", &n)
	m = uint64(n)
	n--
	for ; n > 1; n-- {
		m *= uint64(n)
	}
	fmt.Printf("%d\n", m)
}

