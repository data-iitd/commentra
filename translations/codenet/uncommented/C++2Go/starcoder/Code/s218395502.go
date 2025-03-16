
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	a, _ := strconv.Atoi(os.Args[1])
	b, _ := strconv.Atoi(os.Args[2])
	c, _ := strconv.Atoi(os.Args[3])

	if (100*a + 10*b + c) % 4 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

