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
	var a, b int
	fmt.Fscan(os.Stdin, &a)
	fmt.Fscan(os.Stdin, &b)
	if (a*b)%2 == 0 {
		fmt.Println("Even")
	} else {
		fmt.Println("Odd")
	}
}

