package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b, c, d int
	fmt.Scanf("%d%d%d%d", &a, &b, &c, &d)

	if a+b > c+d {
		fmt.Println("Left")
	} else if a+b < c+d {
		fmt.Println("Right")
	} else {
		fmt.Println("Balanced")
	}
}

