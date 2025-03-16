package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
	A, B, K := readLine(reader)
	x, y := A, B
	x = A - K
	if x < 0 {
		y = B + x
		x = 0
		if y < 0 {
			y = 0
		}
	}
	fmt.Println(x, y)
}

func readLine(reader *bufio.Reader) (int64, int64, int64) {
	var A, B, K int64
	str, _, _ := reader.ReadLine()
	tokens := strings.Split(string(str), " ")
	A, _ = strconv.ParseInt(tokens[0], 10, 64)
	B, _ = strconv.ParseInt(tokens[1], 10, 64)
	K, _ = strconv.ParseInt(tokens[2], 10, 64)
	return A, B, K
}

// 