
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
	c, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	d, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d)-c)
	} else {
		list := []int{a, b, c, d}
		sort(list)
		fmt.Println(list[2] - list[1])
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func sort(list []int) {
	for i := 0; i < len(list); i++ {
		for j := i + 1; j < len(list); j++ {
			if list[i] > list[j] {
				list[i], list[j] = list[j], list[i]
			}
		}
	}
}

