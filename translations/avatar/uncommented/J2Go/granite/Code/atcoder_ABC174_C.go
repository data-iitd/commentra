
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	fmt.Fprintln(w, solve())
	w.Flush()
}

func solve() int {
	K, _ := strconv.Atoi(read())
	if K%2 == 0 || K%5 == 0 {
		return -1
	}
	if K%7 == 0 {
		K /= 7
	}
	K *= 9
	ans := 1
	remainder := 10 % K
	for remainder!= 1 {
		ans++
		remainder = remainder*10 % K
	}
	return ans
}

func read() string {
	line, _ := r.ReadString('\n')
	return strings.TrimSpace(line)
}

