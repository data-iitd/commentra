package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var ans int64

func get(a int64) int64 {
	var ret, now, t int64
	ret = 0
	now = 1
	t = 1
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
		mid := l + (r-l)/2
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var gen, st, tim int64
	fmt.Fscan(reader, &gen, &st, &tim)
	gen /= tim
	beg := st - 1
	end := int64(math.Pow(10, 18))
	for {
		med := (beg + end) / 2 + 1
		if get(med) - get(st-1) > gen {
			end = med - 1
		} else {
			beg = med
		}
		if beg == end {
			fmt.Fprintln(writer, beg-st+1)
			break
		}
	}
}

