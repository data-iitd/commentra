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
	n, k := 0, 0
	fmt.Sscanf(os.Args[1], "%d", &n)
	fmt.Sscanf(os.Args[2], "%d", &k)
	if n%k == 0 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

