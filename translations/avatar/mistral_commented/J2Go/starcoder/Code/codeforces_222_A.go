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
	fmt.Println("Enter the number of integers")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the number of integers to be checked")
	k, _ := strconv.Atoi(reader.ReadString('\n'))
	l := 0
	c := 1
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(reader.ReadString('\n'))
		if a == l {
			c++
		} else {
			c = 1
		}
		l = a
	}
	if c+k > n {
		fmt.Println(n - c)
	} else {
		fmt.Println(-1)
	}
}

