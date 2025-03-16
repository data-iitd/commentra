
package main

import (
	"fmt"
	"strconv"
)

func main() {
	n := input()
	a := []string{"10", "100", "1000", "10000", "100000"}
	new := 0
	for _, v := range n {
		new += int(v) - 48
	}
	if n == "10" || n == "100" || n == "1000" || n == "10000" || n == "100000" {
		fmt.Println(10)
	} else {
		fmt.Println(new)
	}
}

func input() string {
	var n string
	fmt.Scanln(&n)
	return n
}

