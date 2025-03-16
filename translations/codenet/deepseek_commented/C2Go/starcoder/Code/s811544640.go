<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)
	if b > a*c {
		fmt.Println(c)
	} else {
		fmt.Println(b/a)
	}
}

