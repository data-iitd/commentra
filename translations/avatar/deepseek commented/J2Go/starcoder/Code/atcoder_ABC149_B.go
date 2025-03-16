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
	fmt.Println("Enter the values of A, B and K")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	tokens := strings.Split(input, " ")
	A, _ := strconv.ParseInt(tokens[0], 10, 64)
	B, _ := strconv.ParseInt(tokens[1], 10, 64)
	K, _ := strconv.ParseInt(tokens[2], 10, 64)
	x := A - K
	if x < 0 {
		y := B + x
		x = 0
		if y < 0 {
			y = 0
		}
	}
	fmt.Println(x, y)
}

