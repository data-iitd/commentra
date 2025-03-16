package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var x int
	fmt.Scanf("%d", &x)
	if x == 1 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

