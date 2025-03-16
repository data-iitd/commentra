
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	mod = int(1e9 + 7)
	dx  = []int{-1, 0, 1, 0}
	dy  = []int{0, -1, 0, 1}
)

var (
	n int64
	k int64
	a []int64
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := 1
	for tc > 0 {
		tc--
		n, k = readTwoNums(reader)
		a = readNNums(reader, int(n))
		sort(a)
		res := solve(n, k, a)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}
	fmt.Print(buf.String())
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func solve(n int64, k int64, a []int64) int64 {
	const inf = 1e18
	l, r := -inf, inf
	for l+1 < r {
		mid := (l + r) / 2
		if check(mid, n, k, a) {
			l = mid
		} else {
			r = mid
		}
	}
	return l
}

func check(x int64, n int64, k int64, a []int64) bool {
	var tot int64
	for i := int64(0); i < n; i++ {
		num := a[i]
		if num >= 0 {
			l, r := int64(0), n
			for l+1 < r {
				mid := (l + r) / 2
				if num*a[mid] < x {
					l = mid
				} else {
					r = mid
				}
			}
			tot += r
		} else {
			l, r := int64(0), n
			for l+1 < r {
				mid := (l + r) / 2
				if num*a[mid] >= x {
					l = mid
				} else {
					r = mid
				}
			}
			tot += n - l
		}
		if num*num < x {
			tot--
		}
	}
	return tot/2 < k
}

func sort(arr []int64) {
	sort2(arr, 0, len(arr)-1)
}

func sort2(arr []int64, l, r int) {
	if l >= r {
		return
	}
	mid := (l + r) / 2
	sort2(arr, l, mid)
	sort2(arr, mid+1, r)
	tmp := make([]int64, r-l+1)
	var j int
	for i := l; i <= mid; i++ {
		for j < len(arr) && arr[j] < arr[mid] {
			j++
		}
		tmp[i-l] = j
	}
	for i := mid + 1; i <= r; i++ {
		tmp[i-l] = len(arr)
	}
	j--
	for i := r; i > mid; i-- {
		for j >= 0 && arr[j] > arr[i] {
			j--
		}
		tmp[i-l] = j
	}
	for i := l; i <= r; i++ {
		arr[i] = arr[tmp[i-l]]
	}
}