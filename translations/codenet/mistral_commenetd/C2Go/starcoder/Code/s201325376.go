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
	a, b, c := 0, 0, 0
	count := 0
	fmt.Sscanf(os.Args[1], "%d", &a)
	fmt.Sscanf(os.Args[2], "%d", &b)
	fmt.Sscanf(os.Args[3], "%d", &c)
	for i := a; i <= b; i++ {
		if c%i == 0 {
			count++
		}
	}
	fmt.Println(count)
}

