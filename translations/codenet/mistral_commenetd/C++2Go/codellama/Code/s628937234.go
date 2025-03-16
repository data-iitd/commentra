package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s, t string
	fmt.Scan(&s)
	t = string(s[0])
	t += strconv.Itoa(len(s) - 2)
	t += string(s[len(s) - 1])
	fmt.Println(t)
}

