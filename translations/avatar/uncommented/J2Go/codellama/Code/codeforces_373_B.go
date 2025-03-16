package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func get(a int64) int64 {
	var ret int64 = 0
	var now int64 = 1
	var t int64 = 1
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

func binarySearch(k, l, r, x int64) int64 {
	if r >= l {
		mid := l + (r-l)/2 + 1
		if mid > ans && mid*k <= x {
			ans = mid
		}

		if k*mid == x {
			return mid
		}

		if k*mid > x {
			return binarySearch(k, l, mid-1, x)
		}

		return binarySearch(k, mid+1, r, x)
	}

	return -1
}

func main() {
	var gen, st, tim int64
	var err error
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	gen, err = strconv.ParseInt(scanner.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	scanner.Scan()
	st, err = strconv.ParseInt(scanner.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	scanner.Scan()
	tim, err = strconv.ParseInt(scanner.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	gen /= tim
	beg := st - 1
	end := int64(1e18)
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

