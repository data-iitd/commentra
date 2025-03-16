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

	var t int
	var s string
	var cnt int64
	var tmp int64
	fmt.Fscanf(reader, "%d\n", &t)
	for i := 0; i < t; i++ {
		fmt.Fscanf(reader, "%s\n", &s)
		cnt = 0
		tmp = 0
		for _, c := range s {
			if c == 'A' {
				tmp++
			} else if c == 'D' {
				cnt += tmp
			} else {
				tmp = 0
			}
		}
		fmt.Fprintln(writer, cnt)
	}
}

