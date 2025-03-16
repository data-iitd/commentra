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

	var S string
	fmt.Fscan(reader, &S)

	score := 0

	for i := 0; i < len(S); i++ {
		var my, his byte

		if i%2 == 0 {
			my = 'g'
		} else {
			my = 'p'
		}

		his = S[i]

		if my != his {
			if my == 'p' {
				score++
			} else {
				score--
			}
		}
	}

	fmt.Fprintln(writer, score)
}

