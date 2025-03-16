package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		gen, st, tim int64
	)
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d %d", &gen, &st, &tim)
	gen /= tim
	beg, end := int64(1), int64(1e18)
	for {
		med := (beg + end) / 2 + 1
		if get(med) - get(st-1) > gen {
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

func get(a int64) int64 {
	ret := int64(0)
	now := int64(1)
	t := int64(1)
	for {
		if now*10 > a {
			ret += (a - now + 1) * t
			break
		}
		ret += now*9*t
		now *= 10
		t++
	}
	return ret
}

