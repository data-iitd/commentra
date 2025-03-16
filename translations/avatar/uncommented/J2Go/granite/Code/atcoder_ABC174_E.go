
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	n, k := readTwoNums()
	logsLength := readNNums(n)
	res := solve(n, k, logsLength)
	fmt.Println(res)
}

func readInt() int {
	res, _ := strconv.Atoi(readWord())
	return res
}

func readTwoNums() (int, int) {
	res := strings.Split(readWord(), " ")
	n, _ := strconv.Atoi(res[0])
	k, _ := strconv.Atoi(res[1])
	return n, k
}

func readNNums(n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := in.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64() uint64 {
	res, _ := strconv.ParseUint(readWord(), 10, 64)
	return res
}

func readInt64() int64 {
	res, _ := strconv.ParseInt(readWord(), 10, 64)
	return res
}

func readWord() string {
	res := readString()
	return res
}

func readString() string {
	x := 0
	bs, _ := in.ReadBytes('\n')
	for x < len(bs) && (bs[x] < 'a' || bs[x] > 'z') && bs[x]!= '-' {
		x++
	}
	return string(bs[x : x+1])
}

func solve(n int, k int, logsLength []int) int {
	l, r := 1, 1e9+1000
	for l < r {
		mid := (l + r) / 2
		if check(mid, logsLength, k) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func check(mid int, logsLength []int, k int) bool {
	for _, log := range logsLength {
		k -= (log + mid - 1) / mid - 1
	}
	return k >= 0
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

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := strings.Split(readString(reader), " ")
	readInt(res[0], 0, &a)
	readInt(res[1], 0, &b)
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := strings.Split(readString(reader), " ")
	readInt(res[0], 0, &a)
	readInt(res[1], 0, &b)
	readInt(res[2], 0, &c)
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

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := strings.Split(readString(reader), " ")
	readInt(res[0], 0, &a)
	readInt(res[1], 0, &b)
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := strings.Split(readString(reader), " ")
	readInt(res[0], 0, &a)
	readInt(res[1], 0, &b)
	readInt(res[2], 0, &c)
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

