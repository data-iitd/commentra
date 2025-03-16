package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter two integers n and m: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)
	m, _ := strconv.Atoi(input)
	if n == 0 {
		if m!= 0 {
			fmt.Println("Impossible")
		} else {
			fmt.Println(0, 0)
		}
		return
	}
	if m <= n {
		if m == 0 {
			m = 1
		}
		fmt.Println(n, m+n-1)
		return
	}
	fmt.Println(m, m+n-1)
}

