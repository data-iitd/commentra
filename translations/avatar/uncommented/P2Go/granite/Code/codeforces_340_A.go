
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func G(a, b int) int {
	for a%b!= 0 {
		a, b = b, a%b
	}
	return b
}

func L(a, b int) int {
	return a * b / G(a, b)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	l, _ := reader.ReadString('\n')
	l = strings.TrimSpace(l)
	l = strings.TrimSuffix(l, "\n")
	s := strings.Split(l, " ")
	x, _ := strconv.Atoi(s[0])
	y, _ := strconv.Atoi(s[1])
	a, _ := strconv.Atoi(s[2])
	b, _ := strconv.Atoi(s[3])
	lcm := L(x, y)
	fmt.Println(b/lcm - (a-1)/lcm)
}
