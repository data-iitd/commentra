package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s)
	t = s[0:1] + fmt.Sprint(len(s)-2) + s[len(s)-1:]
	fmt.Println(t)
}

