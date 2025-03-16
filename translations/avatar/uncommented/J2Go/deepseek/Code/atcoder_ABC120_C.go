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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	x, _ := reader.ReadString('\n')
	s := []rune{}
	c := 0
	for _, char := range x {
		s = append(s, char)
		for len(s) > 1 {
			p := s[len(s)-1]
			q := s[len(s)-2]
			s = s[:len(s)-2]
			if (p == '1' && q == '0') || (p == '0' && q == '1') {
				c++
				continue
			} else {
				s = append(s, q)
				s = append(s, p)
				break
			}
		}
	}
	fmt.Fprintln(writer, c*2)
}

