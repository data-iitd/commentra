
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	n, m := readTwoNums(reader)
	out := make([]int, n)
	comp := make([]int, n)
	for i := 0; i < n; i++ {
		comp[i] = i + 2
	}

	for i := 0; i < m; i++ {
		l, r, x := readThreeNums(reader)
		t := l
		for t <= r {
			nextVal := comp[t-1]
			if out[t-1] == 0 && t!= x {
				out[t-1] = x
			}
			comp[t-1] = r + 1
			if t >= x {
				comp[t-1] = x
			}
			t = nextVal
		}
	}
	fmt.Println(strings.Trim(fmt.Sprint(out), "[]"))
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readLine(reader)
	if len(res) > 0 {
		a, _ = strconv.Atoi(res[0])
		b, _ = strconv.Atoi(res[1])
		c, _ = strconv.Atoi(res[2])
	}
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readLine(reader)
	if len(res) > 0 {
		a, _ = strconv.Atoi(res[0])
		b, _ = strconv.Atoi(res[1])
	}
	return
}

func readLine(reader *bufio.Reader) []string {
	buf, _, _ := reader.ReadLine()
	return strToString(buf)
}

func strToString(input string) []string {
	return strings.Split(input, " ")
}

