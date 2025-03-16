
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	var x string
	fmt.Scan(&x)
	a := strings.Builder{}
	b := strings.Builder{}
	a1 := 0
	a2 := 0
	for i := 1; i < len(x); i++ {
		if x[i] == x[i-1] {
			if x[i] == '1' {
				a.WriteByte('0')
			} else {
				a.WriteByte('1')
			}
			a1++
		}
	}
	for i := len(x) - 1; i > 0; i-- {
		if x[i-1] == x[i] {
			if x[i-1] == '1' {
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

