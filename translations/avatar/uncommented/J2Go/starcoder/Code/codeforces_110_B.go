package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, i, j, p int
	var c []string
	sc := NewScanner(os.Stdin)
	n = sc.nextInt()
	c = make([]string, n)
	for i = 0; i < 4; i++ {
		for j = i; j < n; j += 4 {
			c[j] = string(p)
			p++
		}
	}
	for i = 0; i < n; i++ {
		fmt.Print(c[i])
	}
}

type Scanner struct {
	*bufio.Reader
}

func NewScanner(reader io.Reader) *Scanner {
	return &Scanner{bufio.NewReader(reader)}
}

func (s *Scanner) nextInt() int {
	scanned, _ := strconv.Atoi(s.next())
	return scanned
}

func (s *Scanner) next() string {
	scanned, _ := bufio.NewReader(s).ReadString('\n')
	return strings.TrimSpace(scanned)
}

