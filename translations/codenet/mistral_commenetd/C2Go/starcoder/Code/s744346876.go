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
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	if a < 10 && b < 10 {
		fmt.Println(a * b)
	} else {
		fmt.Println("-1")
	}
}

