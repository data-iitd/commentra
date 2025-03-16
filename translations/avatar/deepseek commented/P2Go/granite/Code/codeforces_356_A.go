

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, m := readTwoInt64s(reader)
	out := make([]int64, n)
	comp := make([]int64, n)
	for i := int64(0); i < n; i++ {
		out[i] = 0
		comp[i] = i + 2
	}

	for i := 0; i < int(m); i++ {
		l, r, x := readFourInt64s(reader)
		t := l
		for t <= r {
			nextVal := comp[t-1]
			if out[t-1] == 0 && t!= x {
				out[t-1] = x
			}
			comp[t-1] = r + 1
			if t >= x {
				comp[t-1] = x
			}
			t = nextVal
		}
	}

	for _, val := range out {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
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

func readTwoInt64s(reader *bufio.Reader) (a int64, b int64) {
	res := readNInt64s(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeInt64s(reader *bufio.Reader) (a int64, b int64, c int64) {
	res := readNInt64s(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readInt(s, pos, &res[i]) + 1
	}

	return res
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' || s[i] == '\r' {
			return s[:i]
		}
	}
	return s
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

func readInt64s(bytes []byte, from int, val *[]int64) int {
	isSpace := func(c byte) bool {
		return c =='' || c == '\n' || c == '\r' || c == '\t' || c == -1
	}
	var res []int64

	i := from
	for i < len(bytes) &&!isSpace(bytes[i]) {
		i = readInt64(bytes, i, &res[0])
	}
	*val = res

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

func readInt64s(bytes []byte, from int, val *[]int64) int {
	isSpace := func(c byte) bool {
		return c =='' || c == '\n' || c == '\r' || c == '\t' || c == -1
	}
	var res []int64

	i := from
	for i < len(bytes) &&!isSpace(bytes[i]) {
		i = readInt64(bytes, i, &res[0])
	}
	*val = res

	return i
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, m := readTwoInt64s(reader)
	out := make([]int64, n)
	comp := make([]int64, n)
	for i := int64(0); i < n; i++ {
		out[i] = 0
		comp[i] = i + 2
	}

	for i := 0; i < int(m); i++ {
		l, r, x := readFourInt64s(reader)
		t := l
		for t <= r {
			nextVal := comp[t-1]
			if out[t-1] == 0 && t!= x {
				out[t-1] = x
			}
			comp[t-1] = r + 1
			if t >= x {
				comp[t-1] = x
			}
			t = nextVal
		}
	}

	for _, val := range out {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
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

func readTwoInt64s(reader *bufio.Reader) (a int64, b int64) {
	res := readNInt64s(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeInt64s(reader *bufio.Reader) (a int64, b int64, c int64) {
	res := readNInt64s(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readInt(s, pos, &res[i]) + 1
	}

	return res
}

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' || s[i] == '\r' {
			return s[:i]
		}
	}
	return s
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

func readInt64s(bytes []byte, from int, val *[]int64) int {
	isSpace := func(c byte) bool {
		return c =='' || c == '\n' || c == '\r' || c == '\t' || c == -1
	}
	var res []int64

	i := from
	for i < len(bytes) &&!isSpace(bytes[i]) {
		i = readInt64(bytes, i, &res[0])
	}
	*val = res

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

func readInt64s(bytes []byte, from int, val *[]int64) int {
	isSpace := func(c byte) bool {
		return c =='' || c == '\n' || c == '\r' || c == '\t' || c == -1
	}
	var res []int64

	i := from
	for i < len(bytes) &&!isSpace(bytes[i]) {
		i = readInt64(bytes, i, &res[0])
	}
	*val = res

	return i
}

