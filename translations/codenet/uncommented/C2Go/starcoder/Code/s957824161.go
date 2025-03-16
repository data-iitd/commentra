package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var x, y int
	fmt.Scanf("%d %d", &x, &y)
	fmt.Printf("%d %d\n", x*y, 2*x+2*y)
}

