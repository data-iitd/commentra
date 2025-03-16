
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n)
		res := solve(n, k, A)
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

func solve(n int, k int, A []int) int {
	mod := int(1e9 + 7)

	inv := func(x int) int {
		return pow(x, mod-2)
	}

	pow := func(a, b int) int {
		A := a
		R := 1

		for b > 0 {
			if b%2 == 1 {
				R = (R * A) % mod
			}
			A = (A * A) % mod
			b /= 2
		}
		return R
	}

	var ans1 int

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if A[i] > A[j] {
				ans1++
			}
		}
	}

	cnt := make([]int, 2005)

	for i := 0; i < n; i++ {
		cnt[A[i]]++
	}

	var ans2 int

	for i := 0; i < 2005; i++ {
		if cnt[i] > 0 {
			ans2 += cnt[i] * (n - cnt[i])
		}
	}

	ans2 = int(int64(ans2) * inv(k) * inv(k-1) % mod)

	ans := int(int64(ans1)*k + int64(ans2)) % mod

	return ans
}