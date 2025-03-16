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
	x, _ := strconv.Atoi(os.Args[1])
	if x == 1 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

