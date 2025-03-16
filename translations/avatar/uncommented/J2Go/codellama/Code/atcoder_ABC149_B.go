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
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

	A, B, K := readLine(reader)

	x := A - K
	if x < 0 {
		x = 0
		y := B + x
		if y < 0 {
			y = 0
		}
		fmt.Println(x, y)
	} else {
		fmt.Println(x, B)
	}
}

func readLine(reader *bufio.Reader) (int64, int64, int64) {
	var A, B, K int64
	var line string
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	tokens := strings.Split(line, " ")
	A, _ = strconv.ParseInt(tokens[0], 10, 64)
	B, _ = strconv.ParseInt(tokens[1], 10, 64)
	K, _ = strconv.ParseInt(tokens[2], 10, 64)
	return A, B, K
}

// 