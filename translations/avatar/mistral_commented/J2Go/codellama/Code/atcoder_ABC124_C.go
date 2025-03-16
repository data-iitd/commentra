
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
	a := []byte(x)
	b := []byte(x)
	a1 := 0
	a2 := 0
	for i := 1; i < len(a); i++ {
		if a[i] == a[i-1] {
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			a1++
		}
	}
	for i := len(b) - 1; i > 0; i-- {
		if b[i] == b[i-1] {
			if b[i-1] == '1' {
				b[i-1] = '0'
			} else {
				b[i-1] = '1'
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

