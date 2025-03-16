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
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	x := strings.Split(line, " ")
	a, _ := strconv.Atoi(x[0])
	b, _ := strconv.Atoi(x[1])
	c := a - b*2
	if c < 0 {
		c = 0
	}
	fmt.Println(c)
}

