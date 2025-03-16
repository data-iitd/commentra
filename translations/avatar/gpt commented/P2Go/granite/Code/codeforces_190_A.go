
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader))
	m, _ := strconv.Atoi(readerReadLine(reader))
	if n < 1 {
		if m < 1 {
			fmt.Println(n, m)
			return
		}
		fmt.Println("Impossible")
		return
	}
	if m > n {
		min := m
		max := n + m - 1
		fmt.Println(min, max)
		return
	}
	min := n
	max := n + m - 1
	if m == 0 {
		max = n
	}
	fmt.Println(min, max)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

