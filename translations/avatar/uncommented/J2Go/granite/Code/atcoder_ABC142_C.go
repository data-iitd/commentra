
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	N int
	P []int
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ = strconv.Atoi(readerReadLine(reader))
	idorder := make(map[int]int)
	for i := 1; i <= N; i++ {
		A, _ := strconv.Atoi(readerReadLine(reader))
		idorder[A] = i
	}
	for i := 1; i <= N; i++ {
		fmt.Printf("%d ", idorder[i])
	}
	fmt.Println()
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

