
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	x := readString(reader)
	a := []byte(x)
	b := []byte(x)
	a1, a2 := 0, 0
	for i := 1; i < len(x); i++ {
		if a[i] == a[i-1] {
			if a[i] == '1' {
				a[i] = '0'
			} else {
				a[i] = '1'
			}
			a1++
		}
	}
	for i := len(x) - 1; i > 0; i-- {
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

func readString(reader *bufio.Reader) string {
	scanner := bufio.NewScanner(reader)
	scanner.Scan()
	return scanner.Text()
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

// END-OF-CODE