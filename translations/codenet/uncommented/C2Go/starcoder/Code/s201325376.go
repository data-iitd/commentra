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
	count := 0
	for i := a; i <= b; i++ {
		if c%i == 0 {
			count++
		}
	}
	fmt.Println(count)
}

