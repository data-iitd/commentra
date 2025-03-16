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
	x, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	a, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	da, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	db, _ := strconv.Atoi(scanner.Text())

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
