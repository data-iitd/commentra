
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	const mod = 100000007
	reader := bufio.NewReader(os.Stdin)
	n, k := readTwoNums(reader)
	res := solve(n, k)
	fmt.Println(res)
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
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

func solve(n int, k int) int64 {
	var l, r int
	var seg []int

	for l <= n {
		r = n / (n / l)
		seg = append(seg, r-l+1)
		l = r + 1
	}

	q := len(seg)
	dp := make([]int64, k*(q+1))

	for j := 1; j <= q; j++ {
		dp[j] = int64(seg[j-1]) + dp[j-1]
	}

	for i := 1; i < k; i++ {
		for j := 1; j <= q; j++ {
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1]+dp[(i-1)*(q+1)+q-j+1]*int64(seg[j-1])
			dp[i*(q+1)+j] %= mod
		}
	}

	return dp[k*(q+1)-1]
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

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readOneNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readInt64(bytes []byte, from int, val *int64) int {
	i := from
	var sign int64 = 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int64(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
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

func readInt32(bytes []byte, from int, val *int32) int {
	i := from
	sign := int32(1)
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int32
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int32(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readInt16(bytes []byte, from int, val *int16) int {
	i := from
	sign := int16(1)
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int16
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int16(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readInt8(bytes []byte, from int, val *int8) int {
	i := from
	sign := int8(1)
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int8
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int8(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readUint16(bytes []byte, from int, val *uint16) int {
	i := from

	var tmp uint16
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint16(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readUint32(bytes []byte, from int, val *uint32) int {
	i := from

	var tmp uint32
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint32(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readUint8(bytes []byte, from int, val *uint8) int {
	i := from

	var tmp uint8
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint8(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readByte(bytes []byte, from int, val *byte) int {
	*val = bytes[from]
	return from + 1
}

func readBytes(reader *bufio.Reader) []byte {
	res := make([]byte, 0)
	for {
		line, prefix, err := reader.ReadLine()
		if err!= nil {
			return res
		}
		res = append(res, line...)
		if prefix == false {
			break
		}
	}
	return res
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int) int {
	return a + b - max(a, b)
}

func maxInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func max64(a, b int64) int64 {
	if a >= b {
		return a
	}
	return b
}

func min64(a, b int64) int64 {
	return a + b - max64(a, b)
}

func maxInt64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}
