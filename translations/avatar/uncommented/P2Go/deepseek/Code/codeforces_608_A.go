package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, s int
	fmt.Fscan(reader, &n, &s)
	c := 0
	for i := 0; i < n; i++ {
		var f, t int
		fmt.Fscan(reader, &f, &t)
		x := t - (s - f)
		if x > c {
			c = x
		}
	}
	fmt.Println(s + c)
}

