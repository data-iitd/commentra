
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, b int
	var res int

	fmt.Print("Enter the first integer value: ")
	fmt.Scan(&a)
	fmt.Print("Enter the second integer value: ")
	fmt.Scan(&b)

	res = a

	for a >= b {
		res += a / b
		a = a/b + a%b
	}

	fmt.Println(res)
}

