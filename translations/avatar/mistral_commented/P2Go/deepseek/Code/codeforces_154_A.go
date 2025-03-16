package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1] // Remove the newline character
	n := readInt(reader)

	ans := 0

	for i := 0; i < n; i++ {
		x, _ := reader.ReadString('\n')
		x = x[:len(x)-1] // Remove the newline character
		a, b := 0, 0

		for _, j := range s {
			if j == rune(x[0]) {
				a++
			} else if j == rune(x[1]) {
				b++
			} else {
				ans += min(a, b)
				a, b = 0, 0
			}
		}
		ans += min(a, b)
	}

	fmt.Fprintln(writer, ans)
}

func readInt(reader *bufio.Reader) int {
	var num int
	for {
		char, _ := reader.ReadByte()
		if char == ' ' || char == '\n' {
			break
		}
		num = num*10 + int(char-'0')
	}
	return num
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

