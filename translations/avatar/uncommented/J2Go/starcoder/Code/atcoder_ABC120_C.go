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
	var x string
	x, _ = reader.ReadString('\n')
	x = strings.TrimSpace(x)
	var s []rune
	s = []rune(x)
	var c int
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			c++
		}
	}
	fmt.Println(c * 2)
}

