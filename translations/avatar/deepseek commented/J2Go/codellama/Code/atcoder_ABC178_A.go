
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var x int
	fmt.Scan(&x)
	var bool bool
	if x == 1 {
		bool = true
	} else {
		bool = false
	}
	var result int
	if !bool {
		result = 1
	} else {
		result = 0
	}
	fmt.Println(result)
	fmt.Println("