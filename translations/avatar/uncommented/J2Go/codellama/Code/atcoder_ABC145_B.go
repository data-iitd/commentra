
package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)

func main() {
	var n int
	var str string
	var a string
	var b string

	fmt.Scan(&n)
	fmt.Scanln(&str)

	for i := 0; i < n/2; i++ {
		a = a + string(str[i])
	}

	if str == a + a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

