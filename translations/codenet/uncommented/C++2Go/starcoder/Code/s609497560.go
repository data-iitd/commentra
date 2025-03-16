package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a int
	fmt.Scanf("%d", &a)
	fmt.Printf("%d\n", a+a*a+a*a*a)
}

