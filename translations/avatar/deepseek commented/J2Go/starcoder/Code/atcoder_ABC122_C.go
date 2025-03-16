package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define a constant for modulo operations
const mod = 1000000007

func main() {
	// Create a buffered reader to read input
	reader := bufio.NewReader(os.Stdin)

	// Read the length of the string and the number of queries
	n, q := readTwoNums(reader)

	// Read the string as a character array
	s := readNNums(reader, n)

	// Read the ranges for the queries and store them in a 2D array
	range_ := make([][]int, q)
	for i := 0; i < q; i++ {
		range_[i] = readNNums(reader, 2)
	}

	// Initialize arrays to count "AC" fragments and store cumulative sums
	frag := make([]int, n+1)
	rui := make([]int, n+1)

	// Process the string to find "AC" fragments
	for i := 2; i <= n; i++ {
		if s[i-2] == 'A' && s[i-1] == 'C' {
			// Increment the count of "AC" fragments at position i
			frag[i]++
		}
		// Update the cumulative sum array
		rui[i] = rui[i-1] + frag[i]
	}

	// Process the queries
	for i := 0; i < q; i++ {
		left, right := range_[i][0], range_[i][1]
		// Calculate the number of "AC" fragments in the given range
		fmt.Println(rui[right] - rui[left])
	}
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
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-':
		sign = -1
		i++
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

func readTwoStrings(reader *bufio.Reader) (a string, b string) {
	res := readNStrings(reader, 2)
	a, b = res[0], res[1]
	return
}

func readNStrings(reader *bufio.Reader, n int) []string {
	res := make([]string, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readString(bs, x, &res[i])
	}
	return res
}

func readString(bytes []byte, from int, val *string) int {
	i := from
	for i < len(bytes) && bytes[i] >''; i++ {
	}
	*val = string(bytes[from:i])
	return i
}

func readFloat(bytes []byte, from int, val *float64) int {
	i := from
	sign := 1
	if bytes[i] == '-':
		sign = -1
		i++
	var tmp float64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + float64(bytes[i]-'0')
		i++
	}
	if i < len(bytes) && bytes[i] == '.' {
		i++
	}
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + float64(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNFloats(reader *bufio.Reader, n int) []float64 {
	res := make([]float64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readFloat(bs, x, &res[i])
	}
	return res
}

func readFloat64(reader *bufio.Reader) float64 {
	bs, _ := reader.ReadBytes('\n')
	var val float64
	x := readFloat(bs, 0, &val)
	return val
}

func readNInt64Nums(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt64(bs, x, &res[i])
	}
	return res
}

func readInt64(bytes []byte, from int, val *int64) int {
	i := from
	sign := int64(1)
	if bytes[i] == '-':
		sign = -1
		i++
	tmp := int64(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int64(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt64(bs, x, &res[i])
	}
	return res
}

func readNInt32Nums(reader *bufio.Reader, n int) []int32 {
	res := make([]int32, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt32(bs, x, &res[i])
	}
	return res
}

func readInt32(bytes []byte, from int, val *int32) int {
	i := from
	sign := int32(1)
	if bytes[i] == '-':
		sign = -1
		i++
	tmp := int32(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int32(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNInt32s(reader *bufio.Reader, n int) []int32 {
	res := make([]int32, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt32(bs, x, &res[i])
	}
	return res
}

func readNInt16Nums(reader *bufio.Reader, n int) []int16 {
	res := make([]int16, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt16(bs, x, &res[i])
	}
	return res
}

func readInt16(bytes []byte, from int, val *int16) int {
	i := from
	sign := int16(1)
	if bytes[i] == '-':
		sign = -1
		i++
	tmp := int16(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int16(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNInt16s(reader *bufio.Reader, n int) []int16 {
	res := make([]int16, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt16(bs, x, &res[i])
	}
	return res
}

func readNInt8Nums(reader *bufio.Reader, n int) []int8 {
	res := make([]int8, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt8(bs, x, &res[i])
	}
	return res
}

func readInt8(bytes []byte, from int, val *int8) int {
	i := from
	sign := int8(1)
	if bytes[i] == '-':
		sign = -1
		i++
	tmp := int8(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int8(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNInt8s(reader *bufio.Reader, n int) []int8 {
	res := make([]int8, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readInt8(bs, x, &res[i])
	}
	return res
}

func readNUint64Nums(reader *bufio.Reader, n int) []uint64 {
	res := make([]uint64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint64(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	tmp := uint64(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readNUint64s(reader *bufio.Reader, n int) []uint64 {
	res := make([]uint64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint64(bs, x, &res[i])
	}
	return res
}

func readNUint32Nums(reader *bufio.Reader, n int) []uint32 {
	res := make([]uint32, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint32(bs, x, &res[i])
	}
	return res
}

func readUint32(bytes []byte, from int, val *uint32) int {
	i := from

	tmp := uint32(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint32(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readNUint32s(reader *bufio.Reader, n int) []uint32 {
	res := make([]uint32, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint32(bs, x, &res[i])
	}
	return res
}

func readNUint16Nums(reader *bufio.Reader, n int) []uint16 {
	res := make([]uint16, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint16(bs, x, &res[i])
	}
	return res
}

func readUint16(bytes []byte, from int, val *uint16) int {
	i := from

	tmp := uint16(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint16(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readNUint16s(reader *bufio.Reader, n int) []uint16 {
	res := make([]uint16, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint16(bs, x, &res[i])
	}
	return res
}

func readNUint8Nums(reader *bufio.Reader, n int) []uint8 {
	res := make([]uint8, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint8(bs, x, &res[i])
	}
	return res
}

func readUint8(bytes []byte, from int, val *uint8) int {
	i := from

	tmp := uint8(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint8(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readNUint8s(reader *bufio.Reader, n int) []uint8 {
	res := make([]uint8, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readUint8(bs, x, &res[i])
	}
	return res
}

func readNFloat64Nums(reader *bufio.Reader, n int) []float64 {
	res := make([]float64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readFloat64(bs, x, &res[i])
	}
	return res
}

func readNFloat32Nums(reader *bufio.Reader, n int) []float32 {
	res := make([]float32, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readFloat32(bs, x, &res[i])
	}
	return res
}

func readFloat32(bytes []byte, from int, val *float32) int {
	i := from
	sign := float32(1)
	if bytes[i] == '-':
		sign = -1
		i++
	tmp := float32(0)
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + float32(bytes[i]-'0')
		i++
	}
	if i < len(bytes) && bytes[i] == '.' {
		i++
	}
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + float32(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNFloat32s(reader *bufio.Reader, n int) []float32 {
	res := make([]float32, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readFloat32(bs, x, &res[i])
	}
	return res
}

func readNFloat64s(reader *bufio.Reader, n int) []float64 {
	res := make([]float64, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		x = readFloat64(bs, x, &res[i])
	}
	return res
}

func readNBools(reader *bufio.Reader, n int) []bool {
	res := make([]bool, n)
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		if bs[i] == '1' {
			res[i] = true
		} else if bs[i] == '0' {
			res[i] = false
		