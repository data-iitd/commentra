package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	// Create a new string t from the string s
	t := string(s[0]) + strconv.Itoa(len(s)-2) + string(s[len(s)-1])

	// Output the newly created string t
	fmt.Println(t)
}

