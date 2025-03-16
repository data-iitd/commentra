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
	r, _ := strconv.Atoi(os.Args[1])
	fmt.Println(r * r)
}

