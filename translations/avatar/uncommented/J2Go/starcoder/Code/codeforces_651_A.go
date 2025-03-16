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

	var a, b int
	fmt.Fscan(reader, &a, &b)
	c := 0
	if a == 1 && b == 1 {
		fmt.Fprintln(writer, 0)
	} else {
		for a >= 1 || b >= 1 {
			if a >= b {
				b++
				a -= 2
			} else {
				a++
				b -= 2
			}
			if a <= 0 || b <= 0 {
				c++
				break
			}
			c++
		}
		fmt.Fprintln(writer, c)
	}
}

func swap(a, b int) {
	a, b = b, a
}

func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

