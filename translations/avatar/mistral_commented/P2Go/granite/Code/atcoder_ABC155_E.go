
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	isTest bool
	using_method int
	input_methods []string
	input_method string
)

func main() {
	input_methods = []string { "clipboard", "file", "key" }
	using_method = 0
	input_method = input_methods [ using_method ]

	if isTest {
		ic := input_clipboard()
		input = func() string {
			return ic.Next()
		}
	} else {
		sc := bufio.NewScanner(os.Stdin)
		sc.Split(bufio.ScanWords)
		input = func() string {
			sc.Scan()
			return sc.Text()
		}
	}

	s := input()
	pp := 0
	na := 0
	for i, c := range []rune(s) {
		cc := int(c) - int('0') + na
		na = 0
		if cc <= 4 {
			pp += cc
		} else {
			if i == len(s) - 1 {
				pp += 1
			} else {
				pp += 10 - cc
			}
		}
	}
	fmt.Println(pp)
}

func input_clipboard() *bufio.Scanner {
	var b bytes.Buffer
	clipboard.Read(&b)
	return bufio.NewScanner(&b)
}

// 