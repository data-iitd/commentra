
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for n%2 == 0 {
		n /= 2
	}
	if n == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

