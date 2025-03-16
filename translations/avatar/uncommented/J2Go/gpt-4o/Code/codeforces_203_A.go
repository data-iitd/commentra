package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var x, t, a, b, da, db int
	fmt.Fscan(reader, &x, &t, &a, &b, &da, &db)

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

// <END-OF-CODE>
