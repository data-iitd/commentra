package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := NewScanner(os.Stdin)
	n, _ := strconv.Atoi(sc.Next())
	ans := 0
	for i := 1; i < n+1; i++ {
		ans += i * (n/i)*(n/i+1)/2
	}
	fmt.Println(ans)
}

type Scanner struct {
	*bufio.Reader
}

func NewScanner(reader io.Reader) *Scanner {
	return &Scanner{bufio.NewReader(reader)}
}

func (s *Scanner) Next() string {
	var (
		isPrefix bool  = true
		b        byte  =''
		buf      []byte = make([]byte, 0)
	)
	for isPrefix && b!= '\n' {
		b, isPrefix, _ = s.ReadLine()
		buf = append(buf, b...)
	}
	return strings.TrimRight(string(buf), "\r\n")
}

