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
	var n, m int
	fmt.Fscan(os.Stdin, &n, &m)
	fmt.Printf("%d\n", (n-1)*(m-1))
}

