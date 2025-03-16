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
	fmt.Scanf("%d", &n)
	if n%1000 == 0 {
		fmt.Println(0)
	} else {
		fmt.Println((n/1000+1)*1000 - n)
	}
}

