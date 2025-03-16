
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
	fmt.Print("Enter two integers separated by space: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	a, b := strings.Split(input, " ")
	a, _ = strconv.Atoi(a)
	b, _ = strconv.Atoi(b)
	c := 0
	for i := 0; i < 2; i++ {
		c += max(a, b)
		if a >= b {
			a -= 1
		} else {
			b -= 1
		}
	}
	fmt.Println(c)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

