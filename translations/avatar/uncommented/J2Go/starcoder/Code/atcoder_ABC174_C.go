package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var K int
	fmt.Fscan(reader, &K)

	if K%2 == 0 || K%5 == 0 {
		fmt.Fprintln(writer, -1)
		return
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

	fmt.Fprintln(writer, ans)
}

