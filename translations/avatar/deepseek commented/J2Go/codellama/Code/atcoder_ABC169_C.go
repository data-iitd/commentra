
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a int64
	var b string
	fmt.Scan(&a, &b)
	b = b[0 : len(b)-1]
	bInt, _ := strconv.Atoi(b)
	result := (a * int64(bInt)) / 100
	fmt.Println(result)
}

