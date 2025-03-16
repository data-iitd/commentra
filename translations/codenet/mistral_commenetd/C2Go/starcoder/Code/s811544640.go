
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
	var a, b, c int
<<<<<<< HEAD
	fmt.Scanf("%d %d %d", &a, &b, &c)
=======
	fmt.Fscanf(os.Stdin, "%d %d %d", &a, &b, &c)
>>>>>>> 98c87cb78a (data updated)
	if b > a*c {
		fmt.Println(c)
	} else {
		fmt.Println(b/a)
	}
}

