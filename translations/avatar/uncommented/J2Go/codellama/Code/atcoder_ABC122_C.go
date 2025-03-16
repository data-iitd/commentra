
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 2)
	sc[0] = 1
	sc[1] = 2
	for i := 2; i < 1000000000; i++ {
		sc[i] = sc[i-1] + sc[i-2]
	}
	fmt.Println(sc[1000000000])
}

