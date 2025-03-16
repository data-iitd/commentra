
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	TIME = 0
	VAL  = 1
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, T := readTwoNums(reader)
	timeValue := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		timeValue[i] = make([]int, 2)
	}
	timeValue[0][TIME] = -1
	timeValue[0][VAL] = -1
	for i := 1; i <= N; i++ {
		timeValue[i][TIME], timeValue[i][VAL] = readTwoNums(reader)
	}
	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, T+1)
	}
	for t := 0; t <= T; t++ {
		dp[0][t] = 0
	}
	for n := 1; n <= N; n++ {
		dp[n][0] = 0
		for t := 1; t <= T; t++ {
			if timeValue[n][TIME] > t {
				dp[n][t] = dp[n-1][t]
			} else {
				dp[n][t] = max(dp[n-1][t], timeValue[n][VAL]+dp[n-1][t-timeValue[n][TIME]])
			}
		}
	}
	valAcum := timeValue[N][VAL]
	t := T - 1
	maxVal := valAcum + dp[N-1][t]
	for n := N - 1; n > 0; n-- {
		valAcum += timeValue[n][VAL]
		t -= timeValue[n+1][TIME]
		if t < 0 {
			break
		} else {
			maxVal = max(maxVal, valAcum+dp[n-1][t])
		}
	}
	fmt.Println(maxVal)
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

func max64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func pow(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a
	}
	return res
}

func pow3(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a * a * a
	}
	return res
}

func pow64(a, b int) int64 {
	var res int64 = 1
	for i := 0; i < b; i++ {
		res *= int64(a)
	}
	return res
}

func pow364(a, b int) int64 {
	var res int64 = 1
	for i := 0; i < b; i++ {
		res *= int64(a * a * a)
	}
	return res
}

varrdi2 struct {
	buf []byte
	cur int
}

func init() {
	rdi2.buf = make([]byte, 1000000)
}

func readString() string {
	rdi2.cur = 0
	var length int
	for i := 0; i < 1000000; i++ {
		if rdi2.buf[i] =='' {
			length = i
			break
		}
	}
	params := rdi2.buf[:length]
	rdi2.cur = length + 1
	return string(params)
}

func readInt() int {
	res := 0
	sign := 1
	if rdi2.buf[rdi2.cur] == '-' {
		sign = -1
		rdi2.cur++
	}
	for ; rdi2.buf[rdi2.cur] >= '0' && rdi2.buf[rdi2.cur] <= '9'; rdi2.cur++ {
		res = res*10 + int(rdi2.buf[rdi2.cur]-'0')
	}
	return res * sign
}

func read64() int64 {
	res := int64(0)
	sign := int64(1)
	if rdi2.buf[rdi2.cur] == '-' {
		sign = -1
		rdi2.cur++
	}
	for ; rdi2.buf[rdi2.cur] >= '0' && rdi2.buf[rdi2.cur] <= '9'; rdi2.cur++ {
		res = res*10 + int64(rdi2.buf[rdi2.cur]-'0')
	}
	return res * sign
}

func readNInt64s(n int) []int64 {
	res := make([]int64, n)
	for i := 0; i < n; i++ {
		res[i] = read64()
	}
	return res
}

func readNInt(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = readInt()
	}
	return res
}

func readUint64() uint64 {
	res := uint64(0)
	for ; rdi2.buf[rdi2.cur] >= '0' && rdi2.buf[rdi2.cur] <= '9'; rdi2.cur++ {
		res = res*10 + uint64(rdi2.buf[rdi2.cur]-'0')
	}
	return res
}

func readNUint64s(n int) []uint64 {
	res := make([]uint64, n)
	for i := 0; i < n; i++ {
		res[i] = readUint64()
	}
	return res
}

func readNNums(n int) []int {
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

func max64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func pow(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a
	}
	return res
}

func pow3(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a * a * a
	}
	return res
}

func pow64(a, b int) int64 {
	var res int64 = 1
	for i := 0; i < b; i++ {
		res *= int64(a)
	}
	return res
}

func pow364(a, b int) int64 {
	var res int64 = 1
	for i := 0; i < b; i++ {
		res *= int64(a * a * a)
	}
	return res
}

var rdi2 struct {
	buf []byte
	cur int
}

func init() {
	rdi2.buf = make([]byte, 1000000)
}

func readString() string {
	rdi2.cur = 0
	var length int
	for i := 0; i < 1000000; i++ {
		if rdi2.buf[i] =='' {
			length = i
			break
		}
	}
	params := rdi2.buf[:length]
	rdi2.cur = length + 1
	return string(params)
}

func readInt() int {
	res := 0
	sign := 1
	if rdi2.buf[rdi2.cur] == '-' {
		sign = -1
		rdi2.cur++
	}
	for ; rdi2.buf[rdi2.cur] >= '0' && rdi2.buf[rdi2.cur] <= '9'; rdi2.cur++ {
		res = res*10 + int(rdi2.buf[rdi2.cur]-'0')
	}
	return res * sign
}

func read64() int64 {
	res := int64(0)
	sign := int64(1)
	if rdi2.buf[rdi2.cur] == '-' {
		sign = -1
		rdi2.cur++
	}
	for ; rdi2.buf[rdi2.cur] >= '0' && rdi2.buf[rdi2.cur] <= '9'; rdi2.cur++ {
		res = res*10 + int64(rdi2.buf[rdi2.cur]-'0')
	}
	return res * sign
}

func readNInt64s(n int) []int64 {
	res := make([]int64, n)
	for i := 0; i < n; i++ {
		res[i] = read64()
	}
	return res
}

func readNInt(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = readInt()
	}
	return res
}

func readUint64() uint64 {
	res := uint64(0)
	for ; rdi2.buf[rdi2.cur] >= '0' && rdi2.buf[rdi2.cur] <= '9'; rdi2.cur++ {
		res = res*10 + uint64(rdi2.buf[rdi2.cur]-'0')
	}
	return res
}

func readNUint64s(n int) []uint64 {
	res := make([]uint64, n)
	for i := 0; i < n; i++ {
		res[i] = readUint64()
	}
	return res
}

func readNNums(n int) []int {
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
		for j := 0; j < len(a); j++ {
			res = max(res, a[j] )
		}
	}
	return res
}

func minInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			res = min(res, a[j] )
		}
	}
	return res
}

func max64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			res = max64(res, a[j] )
		}
	}
	return res
}

func min64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			res = min64(res, a[j] )
		}
	}
	return res
}

func maxInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			res = maxInt(res, a[j] )
		}
	}
	return res
}

func minInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			res = minInt(res, a[j] )
		}
	}
	return res
}

func max64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			res = max64(res, a[j] )
		}
	}
	return res
}

func min64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for j := 0; j < len(a); j++ {
			res = min64(res, a[j] )
		}
	}
	return res
}

func maxInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		for