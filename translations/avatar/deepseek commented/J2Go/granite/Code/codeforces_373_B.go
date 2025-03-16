

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	ans int64
)

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
	gen, st, tim := readInt64(), readInt64(), readInt64()
	gen /= tim
	beg, end := st-1, int64(1e18)
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

func readInt() int {
	res, err := strconv.Atoi(readToken())
	if err!= nil {
		panic(err)
	}
	return res
}

func readString() string {
	return readToken()
}

func readInt64() int64 {
	res, err := strconv.ParseInt(readToken(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return res
}

func readToken() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

