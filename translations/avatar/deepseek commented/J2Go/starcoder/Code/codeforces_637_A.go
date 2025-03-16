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
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	var ara []int
	var mapa map[int]int
	var max int

	n, _ = strconv.Atoi(readLine(in))
	ara = make([]int, n)
	mapa = make(map[int]int)

	for i := 0; i < n; i++ {
		ara[i], _ = strconv.Atoi(readLine(in))
		if _, ok := mapa[ara[i]];!ok {
			mapa[ara[i]] = 1
		} else {
			mapa[ara[i]]++
		}
	}

	max = 0
	for _, v := range mapa {
		max = max(max, v)
	}

	mm := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]];!ok {
			mm[ara[i]] = 1
			if mm[ara[i]] == max {
				fmt.Fprintln(out, ara[i])
				break
			}
		} else {
			mm[ara[i]]++
			if mm[ara[i]] == max {
				fmt.Fprintln(out, ara[i])
				break
			}
		}
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func readLine(in *bufio.Reader) string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := in.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return strings.TrimSpace(string(buf))
}

func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

