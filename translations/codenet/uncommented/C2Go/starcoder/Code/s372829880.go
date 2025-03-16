package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	x, a := 0, 0
	fmt.Sscanf(os.Args[1], "%d", &x)
	fmt.Sscanf(os.Args[2], "%d", &a)
	fmt.Printf("%d\n", (x >= a) * 10)
}

