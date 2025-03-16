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
	var x string
	fmt.Fscanln(reader, &x)
	a := strings.Builder{}
	a.WriteString(x)
	b := strings.Builder{}
	b.WriteString(x)
	a1 := 0
	a2 := 0
	for i := 1; i < len(x); i++ {
		if a.String()[i] == a.String()[i-1] {
			if a.String()[i] == "1" {
				a.WriteByte('0')
			} else {
				a.WriteByte('1')
			}
			a1++
		}
	}
	for i := len(x) - 1; i > 0; i-- {
		if b.String()[i] == b.String()[i-1] {
			if b.String()[i-1] == "1" {
				b.WriteByte('0')
			} else {
				b.WriteByte('1')
			}
			a2++
		}
	}
	fmt.Println(min(a1, a2))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

