
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var gen, st, tim int64
	fmt.Scan(&gen, &st, &tim)
	gen /= tim
	beg := st - 1
	end := int64(1e18)
	for beg != end {
		med := (beg + end) / 2
		if get(med) - get(st-1) > gen {
			end = med - 1
		} else {
			beg = med
		}
	}
	fmt.Println(beg - st + 1)
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