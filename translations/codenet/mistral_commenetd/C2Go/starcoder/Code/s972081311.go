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
	var n, sum int
	fmt.Fscan(os.Stdin, &n)
	sum = (n * (n + 1)) / 2
	fmt.Println(sum)
}

