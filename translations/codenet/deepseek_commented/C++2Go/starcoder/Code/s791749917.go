<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
)

func main() {
	var H, W int
	fmt.Scan(&H, &W)
	m := H * W
	if H == 1 || W == 1 {
		fmt.Println(1)
	} else if m%2 == 0 {
		fmt.Println(m / 2)
	} else {
		fmt.Println(m/2 + 1)
	}
}

