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
	fmt.Scanf("%d", &n)
	if n == 1 {
		fmt.Println("Hello World")
	} else {
		var strs [2]string
		for i := 0; i < 2; i++ {
			fmt.Scanf("%s", &strs[i])
		}
		fmt.Println(strconv.Atoi(strs[0]) + strconv.Atoi(strs[1]))
	}
}

