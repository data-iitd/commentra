
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
	s := make([]byte, 0)
	c := 0
	for i := 0; i < len(x); i++ {
		s = append(s, x[i])
		for len(s) > 1 {
			p := s[len(s)-1]
			q := s[len(s)-2]
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++
				s = s[:len(s)-2]
				continue
			} else {
				s = s[:len(s)-1]
				break
			}
		}
	}
	fmt.Println(c * 2)
}

