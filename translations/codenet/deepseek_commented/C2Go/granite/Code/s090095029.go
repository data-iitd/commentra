
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(nextString(reader))
	m, _ := strconv.Atoi(nextString(reader))
	r0 := make([]bool, n)
	for i := 0; i < n; i++ {
		r0[i] = false
	}
	r1 := make([]int, n)
	nr1 := 0
	for i := 0; i < m; i++ {
		a, _ := strconv.Atoi(nextString(reader))
		b, _ := strconv.Atoi(nextString(reader))
		if a > b {
			t := a
			a = b
			b = t
		}
		if a == 1 {
			r0[b-1] = true
		}
		if b == n {
			r1[nr1] = a - 1
			nr1++
		}
	}
	res := false
	for i := 0; i < nr1; i++ {
		if r0[r1[i]] {
			res = true
			break
		}
	}
	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

func nextString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	for i := 0; i < len(str); i++ {
		if str[i] == '\n' {
			return str[0 : i]
		}
	}
	return str
}

