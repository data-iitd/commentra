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
	fmt.Scanf("%d", &a)
	b = a / (60 * 60)
	a = a % (60 * 60)
	b = b * 60
	a = a / 60
	fmt.Printf("%d:%d:%d\n", b, a, a%60)
}

