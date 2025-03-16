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
	n, _ := strconv.Atoi(readLine(reader))
	c := 0
	for i := 0; i < n; i++ {
		line, _ := readLine(reader)
		parts := strings.Split(line, " ")
		l1 := make([]int, len(parts))
		for j, part := range parts {
			l1[j], _ = strconv.Atoi(part)
		}
		if sum(l1) > 1 {
			c++
		}
	}
	fmt.Println(c)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimRight(line, "\n")
	return line
}

func sum(l1 []int) int {
	total := 0
	for _, value := range l1 {
		total += value
	}
	return total
}
