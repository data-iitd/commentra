package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s string
	fmt.Scan(&s)
	t := string(s[0]) + strconv.Itoa(len(s)-2) + string(s[len(s)-1])
	fmt.Println(t)
}

// <END-OF-CODE>
