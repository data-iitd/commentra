
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func readInt() int {
	bytes, _ := reader.ReadBytes('\n')
	return int(mustParseInt(bytes))
}

func readString() string {
	bytes, _ := reader.ReadBytes('\n')
	return string(bytes[:len(bytes)-1])
}

func readNInt64(n int) []int64 {
	res := make([]int64, n)
	bytes, _ := reader.ReadBytes('\n')
	getPos := 0
	getVal := int64(0)
	getNeg := false
	for i := 0; i < n; i++ {
		if bytes[getPos] == '-' {
			getNeg = true
			getPos++
		}
		for getPos < len(bytes) && bytes[getPos] >= '0' && bytes[getPos] <= '9' {
			getVal = getVal*10 + int64(bytes[getPos]-'0')
			getPos++
		}
		if getNeg {
			getVal = -getVal
		}
		res[i] = getVal
		getNeg = false
		getVal = 0
	}
	return res
}

func main() {
	n := readInt()
	a := make([]int, 1001)
	for i := 0; i < n; i++ {
		a[readInt()]++
	}
	max := 0
	for i := 1; i < 1001; i++ {
		if a[i] > max {
			max = a[i]
		}
	}
	if n%2 == 0 {
		if max <= n/2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		if max <= n/2+1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func mustParseInt(text []byte) int {
	res, err := strconv.Atoi(string(text))
	if err!= nil {
		panic(err)
	}
	return res
}

func mustParseInt64(text []byte) int64 {
	res, err := strconv.ParseInt(string(text), 10, 64)
	if err!= nil {
		panic(err)
	}
	return res
}

func mustParseFloat64(text []byte) float64 {
	res, err := strconv.ParseFloat(string(text), 64)
	if err!= nil {
		panic(err)
	}
	return res
}

func split(line []byte) []byte {
	return bytes.Split(line, []byte{' '})
}

func parseInt64s(text [][]byte) []int64 {
	res := make([]int64, len(text))
	for i, num := range text {
		res[i] = mustParseInt64(num)
	}
	return res
}

func parseInt(text [][]byte) []int {
	res := make([]int, len(text))
	for i, num := range text {
		res[i] = mustParseInt(num)
	}
	return res
}

func parseInt64(text []byte) int64 {
	return mustParseInt64(text)
}

func parseInt32(text []byte) int32 {
	return mustParseInt(text)
}

func parseInt16(text []byte) int16 {
	return mustParseInt(text)
}

func parseInt8(text []byte) int8 {
	return mustParseInt(text)
}

func parseInt64s(text []byte) []int64 {
	return parseInt64s(split(text))
}

func parseInt(text []byte) []int {
	return parseInt(split(text))
}

func parseInt64(text []byte) int64 {
	return parseInt64(split(text))
}

func parseInt32(text []byte) int32 {
	return parseInt32(split(text))
}

func parseInt16(text []byte) int16 {
	return parseInt16(split(text))
}

func parseInt8(text []byte) int8 {
	return parseInt8(split(text))
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	return parseInt8(line)
}

func readInt64s() []int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64s(line)
}

func readInts() []int {
	line, _ := reader.ReadBytes('\n')
	return parseInt(line)
}

func readInt64() int64 {
	line, _ := reader.ReadBytes('\n')
	return parseInt64(line)
}

func readInt32() int32 {
	line, _ := reader.ReadBytes('\n')
	return parseInt32(line)
}

func readInt16() int16 {
	line, _ := reader.ReadBytes('\n')
	return parseInt16(line)
}

func readInt8() int8 {
	line, _ := reader.ReadBytes('\n')
	re