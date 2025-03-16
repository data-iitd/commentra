
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	bf := bufio.NewReader(os.Stdin)
	x := strings.Split(strings.TrimSpace(readLine(bf)), " ")
	a, _ := strconv.Atoi(x[0])
	b, _ := strconv.Atoi(x[1])
	c := a - b*2
	if c < 0 {
		c = 0
	}
	fmt.Println(c)
}

func readLine(bf *bufio.Reader) string {
	str, _, err := bf.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

