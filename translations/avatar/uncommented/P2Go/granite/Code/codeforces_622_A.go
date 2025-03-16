
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func read() (int, error) {
	var s string
	var n int
	var err error
	if s, err = reader.ReadString('\n'); err!= nil {
		return n, err
	}
	n, err = strconv.Atoi(s)
	if err!= nil {
		return n, err
	}
	return n, nil
}

func write(n int) {
	fmt.Fprintf(writer, "%d\n", n)
	writer.Flush()
}

func main() {
	var n int
	var err error
	if n, err = read(); err!= nil {
		panic(err)
	}
	l := 1
	r := n
	for l < r {
		mid := l + (r-l)/2
		idxcnt := mid * (mid + 1) / 2
		if idxcnt < n {
			l = mid + 1
		} else {
			r = mid
		}
	}
	l -= 1
	idxcnt := l * (l + 1) / 2
	write(int(n - idxcnt))
}

