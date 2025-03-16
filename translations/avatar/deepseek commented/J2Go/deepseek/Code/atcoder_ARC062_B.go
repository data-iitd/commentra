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

	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)

	score := 0
	for i := 0; i < len(S); i++ {
		my := 'g'
		if i%2 == 0 {
			my = 'g'
		} else {
			my = 'p'
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

