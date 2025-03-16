
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	var gen, st, tim int64
	var ans int64
	var beg, end int64
	var mid int64
	var k, x int64
	var ret int64
	var br *bufio.Reader
	var pw *bufio.Writer
	var S *bufio.Scanner
	var err error

	br = bufio.NewReader(os.Stdin)
	pw = bufio.NewWriter(os.Stdout)
	S = bufio.NewScanner(br)
	S.Split(bufio.ScanWords)

	S.Scan()
	gen, err = strconv.ParseInt(S.Text(), 10, 64)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	S.Scan()
	st, err = strconv.ParseInt(S.Text(), 10, 64)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	S.Scan()
	tim, err = strconv.ParseInt(S.Text(), 10, 64)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	gen /= tim
	beg = st - 1
	end = int64(math.Pow(10, 18))
	for beg < end {
		mid = (beg + end) / 2
		if get(mid) - get(st-1) > gen {
			end = mid - 1
		} else {
			beg = mid
		}
	}
	pw.WriteString(strconv.FormatInt(beg-st+1, 10))
	pw.Flush()
}

func get(a int64) int64 {
	var ret int64
	var now int64
	var t int64
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
	var mid int64
	for l <= r {
		mid = (l + r) / 2
		if mid > ans && mid*k <= x {
			ans = mid
		}
		if k*mid == x {
			return mid
		}
		if k*mid > x {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return -1
}

