package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	a, _ := strconv.ParseInt(os.Args[1], 10, 64)
	b, _ := strconv.ParseInt(os.Args[2], 10, 64)
	if (a + b) % 2 == 0 {
		fmt.Println((a + b) / 2)
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

