package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	a, b, c := 0, 0, 0
	fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d %d %d", &a, &b, &c)

	if a < b && b < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

