
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var x, y, a, b int
	var count int
	var in = bufio.NewReader(os.Stdin)
	var out = bufio.NewWriter(os.Stdout)
	var err error

	x, err = strconv.Atoi(in.ReadLine())
	if err!= nil {
		panic(err)
	}
	y, err = strconv.Atoi(in.ReadLine())
	if err!= nil {
		panic(err)
	}
	a, err = strconv.Atoi(in.ReadLine())
	if err!= nil {
		panic(err)
	}
	b, err = strconv.Atoi(in.ReadLine())
	if err!= nil {
		panic(err)
	}

	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			count++
		}
	}
	fmt.Fprintln(out, count)
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			fmt.Fprintln(out, i, j)
		}
	}
	out.Flush()
}

