
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
	in := bufio.NewScanner(reader)
	in.Scan()
	line := in.Text()
	tokens := strings.Split(line, " ")
	A, _ := strconv.ParseInt(tokens[0], 10, 64)
	B, _ := strconv.ParseInt(tokens[1], 10, 64)
	K, _ := strconv.ParseInt(tokens[2], 10, 64)
	x := A - K
	if x < 0 {
		B += x
		x = 0
		if B < 0 {
			B = 0
		}
	}
	fmt.Println(x, B)
}

