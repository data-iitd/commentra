package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var h, a, num int
	fmt.Scan(&h, &a)
	for h > 0 {
		h = h - a
		num++
	}
	fmt.Println(num)
}

