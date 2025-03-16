
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	if n == 1 {
		fmt.Println("Hello World")
	} else {
		var strs [2]string
		fmt.Scan(&strs[0], &strs[1])
		fmt.Println(strconv.Atoi(strs[0]) + strconv.Atoi(strs[1]))
	}
}

