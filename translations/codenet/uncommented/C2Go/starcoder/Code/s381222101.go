package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	a, b, h := 0, 0, 0
	fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d%d%d", &a, &b, &h)
	fmt.Println((a + b) * h / 2)
}

