
package main

import (
	"bufio"
	"fmt"
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
	k, _ := strconv.Atoi(read())
	if k%2 == 0 || k%5 == 0 {
		return -1
	}
	if k%7 == 0 {
		k /= 7
	}
	k *= 9
	ans := 1
	for remainder := 10 % k; remainder!= 1; ans++ {
		remainder = remainder*10 % k
	}
	return ans
}

func read() string {
	line, _ := r.ReadString('\n')
	return strings.TrimSpace(line)
}

