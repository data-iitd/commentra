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
	h, r := 0, 0
	fmt.Sscanf(os.Args[1], "%d", &h)
	fmt.Sscanf(os.Args[2], "%d", &r)
	if r > -h {
		fmt.Println("1")
	} else if r == -h {
		fmt.Println("0")
	} else {
		fmt.Println("-1")
	}
}

