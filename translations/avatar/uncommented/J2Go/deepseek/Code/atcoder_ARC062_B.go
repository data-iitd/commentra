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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	S := readString(reader)
	score := 0
	for i := 0; i < len(S); i++ {
		my := 'p'
		if i%2 == 0 {
			my = 'g'
		}
		his := rune(S[i])
		if my != his {
			if my == 'p' {
				score += 1
			} else {
				score -= 1
			}
		}
	}
	fmt.Fprintln(writer, score)
}

func readString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}
