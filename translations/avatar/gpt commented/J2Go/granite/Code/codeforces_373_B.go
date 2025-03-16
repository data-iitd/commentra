
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	gen int64
	st  int64
	tim int64
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	gen, _ = strconv.ParseInt(read(reader), 10, 64)
	st, _ = strconv.ParseInt(read(reader), 10, 64)
	tim, _ = strconv.ParseInt(read(reader), 10, 64)
	gen /= tim
	beg := st - 1
	end := int64(1e18)
	for {
		med := (beg + end) / 2 + 1
		if get(med)-get(st-1) > gen {
			end = med - 1
		} else {
			beg = med
		}
		if beg == end {
			fmt.Println(beg - st + 1)
			break
		}
	}
}

func read(reader *bufio.Reader) string {
	s, _, _ := reader.ReadLine()
	return string(s)
}

func get(a int64) int64 {
	ret := int64(0)
	now := int64(1)
	t := int64(1)
	for {
		if now*10 > a {
			ret += (a - now + 1) * t
			break
		}
		ret += now * 9 * t
		now *= 10
		t++
	}
	return ret
}

// 