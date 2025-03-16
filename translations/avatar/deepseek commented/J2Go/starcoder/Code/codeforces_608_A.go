package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var n, s int
	fmt.Fscan(in, &n, &s)
	max := 0
	for n > 0 {
		var f, t int
		fmt.Fscan(in, &f, &t)
		if max < f+t {
			max = f + t
		}
		n--
	}
	fmt.Println(max)
}

