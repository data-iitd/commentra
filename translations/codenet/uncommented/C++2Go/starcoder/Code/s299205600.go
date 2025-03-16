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
	a, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	b, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	var result int
	if a > b {
		result = 2*a - 1
	} else if a == b {
		result = 2*a
	} else {
		result = 2*b - 1
	}
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

