package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	scanner.Scan()
	inputs := strings.Fields(scanner.Text())
	x, _ := strconv.Atoi(inputs[0])
	t, _ := strconv.Atoi(inputs[1])
	a, _ := strconv.Atoi(inputs[2])
	b, _ := strconv.Atoi(inputs[3])
	da, _ := strconv.Atoi(inputs[4])
	db, _ := strconv.Atoi(inputs[5])

	ok := false

	for i := 0; i < t; i++ {
		first := a - da*i
		for j := 0; j < t; j++ {
			second := b - db*j
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
