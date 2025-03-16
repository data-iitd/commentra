
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	line, _, err := r.ReadLine()
	if err!= nil {
		panic(err)
	}
	fields := bytes.Split(line, []byte{' '})
	n, m := int(mustParseInt(fields[0])), int(mustParseInt(fields[1]))
	r0 := make([]bool, n)
	for i := 0; i < n; i++ {
		r0[i] = false
	}
	r1 := make([]int, n)
	nr1 := 0
	for i := 0; i < m; i++ {
		line, _, err := r.ReadLine()
		if err!= nil {
			panic(err)
		}
		fields := bytes.Split(line, []byte{' '})
		a, b := int(mustParseInt(fields[0])), int(mustParseInt(fields[1]))
		if a > b {
			a, b = b, a
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

func mustParseInt(b []byte) int64 {
	n, err := strconv.ParseInt(string(b), 10, 64)
	if err!= nil {
		panic(err)
	}
	return n
}

