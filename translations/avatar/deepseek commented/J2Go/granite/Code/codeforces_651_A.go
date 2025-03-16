
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	a, _ := strconv.Atoi(read())
	b, _ := strconv.Atoi(read())
	c := 0

	if a == 1 && b == 1 {
		fmt.Println(0)
	} else {
		for a >= 1 || b >= 1 {
			if a >= b {
				b++
				a -= 2
			} else {
				a++
				b -= 2
			}
			if a <= 0 || b <= 0 {
				c++
				break
			}
			c++
		}
		fmt.Println(c)
	}
	out.Flush()
}

func read() string {
	buf := make([]byte, 0)
	for {
		line, prefix, err := in.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if prefix == false {
			break
		}
	}
	return string(buf)
}

func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

