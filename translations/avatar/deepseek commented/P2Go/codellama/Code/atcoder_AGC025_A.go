
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n string
	fmt.Scan(&n)
	a := []string{"10", "100", "1000", "10000", "100000"}
	new := 0
	for _, v := range n {
		new += int(v - '0')
	}
	if strings.Contains(strings.Join(a, ""), n) {
		fmt.Println(10)
	} else {
		fmt.Println(new)
	}
}

