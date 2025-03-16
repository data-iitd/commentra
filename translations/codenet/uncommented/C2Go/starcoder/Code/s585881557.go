package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	h, r := 0, 0
	h, _ = strconv.Atoi(os.Args[1])
	r, _ = strconv.Atoi(os.Args[2])
	if r > -h {
		fmt.Println("1")
	} else if r == -h {
		fmt.Println("0")
	} else {
		fmt.Println("-1")
	}
}

