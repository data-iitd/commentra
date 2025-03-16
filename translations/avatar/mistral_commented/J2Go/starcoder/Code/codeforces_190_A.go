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
	fmt.Println("Enter the value of n")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the value of m")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
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

