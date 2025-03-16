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
	fmt.Println("Enter two integers separated by a space:")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.Atoi(input)
	fmt.Println("Enter two integers separated by a space:")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, " ", "", -1)
	b, _ := strconv.Atoi(input)
	c := 0
	for i := 0; i < 2; i++ {
		c += max(a, b)
		if a >= b {
			a -= 1
		} else {
			b -= 1
	}
	fmt.Println(c)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

