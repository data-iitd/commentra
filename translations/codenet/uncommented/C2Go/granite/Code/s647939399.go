
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	c := make([]int, 256)
	i := 0
	for {
		a, _ := strconv.Atoi(read(r))
		m := read(r)
		b, _ := strconv.Atoi(read(r))
		if m == "?" {
			break
		}
		switch m {
		case "+":
			c[i] = a + b
		case "-":
			c[i] = a - b
		case "*":
			c[i] = a * b
		case "/":
			c[i] = a / b
		}
		i++
	}
	for j := 0; j < i; j++ {
		fmt.Println(c[j])
	}
}

func read(r *bufio.Reader) string {
	s, _ := r.ReadString('\n')
	return s[:len(s)-1]
}

