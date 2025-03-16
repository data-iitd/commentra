
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a int64
	var b string
	fmt.Scan(&a, &b)
	bStr := ""
	for _, v := range b {
		if v != '.' {
			bStr += string(v)
		}
	}
	bInt, _ := strconv.Atoi(bStr)
	result := (a * int64(bInt)) / 100
	fmt.Println(result)
}

