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
	sa, sb, _ := strings.Cut(readLine(reader), " ")
	a, _ := strconv.Atoi(sa)
	b, _ := strconv.Atoi(strings.ReplaceAll(sb, ".", ""))
	fmt.Println(a * b / 100)
}

func readLine(reader *bufio.Reader) string {
	bytes, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(bytes)
}
