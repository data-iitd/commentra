package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	run()
}

func run() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	x := nextInt(reader)
	t := nextInt(reader)
	a := nextInt(reader)
	b := nextInt(reader)
	da := nextInt(reader)
	db := nextInt(reader)

	ok := false

	for i := 0; i < t; i++ {
		first := a - (da * i)
		for j := 0; j < t; j++ {
			second := b - (db * j)

			if second+first == x || second == x || first == x || x == 0 {
				ok = true
				break
			}
		}
		if ok {
			break
		}
	}

	if ok {
		writer.WriteString("YES\n")
	} else {
		writer.WriteString("NO\n")
	}
}

func nextInt(reader *bufio.Reader) int {
	line, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(line[:len(line)-1]) // Convert string to int, removing newline
	return num
}

// <END-OF-CODE>
