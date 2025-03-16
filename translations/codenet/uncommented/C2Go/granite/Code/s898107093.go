
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	taro := 0
	hanako := 0
	for i := 0; i < n; i++ {
		var t, h string
		fmt.Scan(&t)
		fmt.Scan(&h)
		if strings.Compare(t, h) < 0 {
			hanako += 3
		} else if strings.Compare(t, h) > 0 {
			taro += 3
		} else {
			taro += 1
			hanako += 1
		}
	}
	fmt.Println(taro, hanako)
}

