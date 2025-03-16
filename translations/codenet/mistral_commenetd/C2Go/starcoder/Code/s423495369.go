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
	if a < c && c < b {
		fmt.Println("Yes")
	} else if a > c && c > b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

