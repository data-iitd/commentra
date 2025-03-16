
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declaring a private method to calculate the XOR operation on a given string with a specific character
func cal(s string, c byte) int {
	n := len(s)
	m := n - 1
	ans := 0

	for i := 0; i < n; i++ {
		if s[i] == c && (m&i) == i {
			ans ^= 1
		}
	}

	return ans
}

// Declaring a private method to read input and process it
func solve() {
	n := readInt()
	for i := 0; i < n; i++ {
		num := readInt()
		s := readString()

		sb := strings.Builder{}
		for i := 1; i < num; i++ {
			sb.WriteString(string(byte(abs(int(s[i]) - int(s[i-1])))))
		}

		if num == 2 {
			fmt.Println(sb.String()[0])
			continue
		}

		s = sb.String()

		if strings.Contains(s, "1") {
			fmt.Println(cal(s, '1'))
		} else {
			fmt.Println(cal(s, '2') * 2)
		}
	}
}

// Declaring a private method to read input from stdin
func readString() string {
	sc.Scan()
	return sc.Text()
}

// Declaring a private method to read input from stdin
func readInt() int {
	i, _ := strconv.Atoi(readString())
	return i
}

// Declaring a private method to read input from stdin
func readIntSlice(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readInt()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt64Slice(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt64() int64 {
	i, _ := strconv.ParseInt(readString(), 10, 64)
	return i
}

// Declaring a private method to read input from stdin
func readFloat64() float64 {
	f, _ := strconv.ParseFloat(readString(), 64)
	return f
}

// Declaring a private method to read input from stdin
func readFloat64Slice(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readFloat64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readByteSlice(n int) []byte {
	a := make([]byte, n)
	for i := 0; i < n; i++ {
		a[i] = readByte()
	}
	return a
}

// Declaring a private method to read input from stdin
func readByte() byte {
	return byte(readInt())
}

// Declaring a private method to read input from stdin
func readRuneSlice(n int) []rune {
	a := make([]rune, n)
	for i := 0; i < n; i++ {
		a[i] = readRune()
	}
	return a
}

// Declaring a private method to read input from stdin
func readRune() rune {
	return rune(readInt())
}

// Declaring a private method to read input from stdin
func readBool() bool {
	return readString() == "true"
}

// Declaring a private method to read input from stdin
func readBoolSlice(n int) []bool {
	a := make([]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readBool()
	}
	return a
}

// Declaring a private method to read input from stdin
func readFloat32Slice(n int) []float32 {
	a := make([]float32, n)
	for i := 0; i < n; i++ {
		a[i] = readFloat32()
	}
	return a
}

// Declaring a private method to read input from stdin
func readFloat32() float32 {
	return float32(readFloat64())
}

// Declaring a private method to read input from stdin
func readComplex64Slice(n int) []complex64 {
	a := make([]complex64, n)
	for i := 0; i < n; i++ {
		a[i] = readComplex64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readComplex64() complex64 {
	re := readFloat32()
	im := readFloat32()
	return complex(re, im)
}

// Declaring a private method to read input from stdin
func readComplex128Slice(n int) []complex128 {
	a := make([]complex128, n)
	for i := 0; i < n; i++ {
		a[i] = readComplex128()
	}
	return a
}

// Declaring a private method to read input from stdin
func readComplex128() complex128 {
	re := readFloat64()
	im := readFloat64()
	return complex(re, im)
}

// Declaring a private method to read input from stdin
func readUintSlice(n int) []uint {
	a := make([]uint, n)
	for i := 0; i < n; i++ {
		a[i] = readUint()
	}
	return a
}

// Declaring a private method to read input from stdin
func readUint() uint {
	i, _ := strconv.ParseUint(readString(), 10, 32)
	return uint(i)
}

// Declaring a private method to read input from stdin
func readUint64Slice(n int) []uint64 {
	a := make([]uint64, n)
	for i := 0; i < n; i++ {
		a[i] = readUint64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readUint64() uint64 {
	i, _ := strconv.ParseUint(readString(), 10, 64)
	return uint64(i)
}

// Declaring a private method to read input from stdin
func readUint16Slice(n int) []uint16 {
	a := make([]uint16, n)
	for i := 0; i < n; i++ {
		a[i] = readUint16()
	}
	return a
}

// Declaring a private method to read input from stdin
func readUint16() uint16 {
	i, _ := strconv.ParseUint(readString(), 10, 16)
	return uint16(i)
}

// Declaring a private method to read input from stdin
func readUint8Slice(n int) []uint8 {
	a := make([]uint8, n)
	for i := 0; i < n; i++ {
		a[i] = readUint8()
	}
	return a
}

// Declaring a private method to read input from stdin
func readUint8() uint8 {
	i, _ := strconv.ParseUint(readString(), 10, 8)
	return uint8(i)
}

// Declaring a private method to read input from stdin
func readInt16Slice(n int) []int16 {
	a := make([]int16, n)
	for i := 0; i < n; i++ {
		a[i] = readInt16()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt16() int16 {
	i, _ := strconv.ParseInt(readString(), 10, 16)
	return int16(i)
}

// Declaring a private method to read input from stdin
func readInt8Slice(n int) []int8 {
	a := make([]int8, n)
	for i := 0; i < n; i++ {
		a[i] = readInt8()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt8() int8 {
	i, _ := strconv.ParseInt(readString(), 10, 8)
	return int8(i)
}

// Declaring a private method to read input from stdin
func readInt32Slice(n int) []int32 {
	a := make([]int32, n)
	for i := 0; i < n; i++ {
		a[i] = readInt32()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt32() int32 {
	i, _ := strconv.ParseInt(readString(), 10, 32)
	return int32(i)
}

// Declaring a private method to read input from stdin
func readInt64Slice(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt64() int64 {
	i, _ := strconv.ParseInt(readString(), 10, 64)
	return int64(i)
}

// Declaring a private method to read input from stdin
func readRuneSlice(n int) []rune {
	a := make([]rune, n)
	for i := 0; i < n; i++ {
		a[i] = readRune()
	}
	return a
}

// Declaring a private method to read input from stdin
func readRune() rune {
	return rune(readInt())
}

// Declaring a private method to read input from stdin
func readFloat32Slice(n int) []float32 {
	a := make([]float32, n)
	for i := 0; i < n; i++ {
		a[i] = readFloat32()
	}
	return a
}

// Declaring a private method to read input from stdin
func readFloat32() float32 {
	return float32(readFloat64())
}

// Declaring a private method to read input from stdin
func readFloat64Slice(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readFloat64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readFloat64() float64 {
	i, _ := strconv.ParseFloat(readString(), 64)
	return float64(i)
}

// Declaring a private method to read input from stdin
func readComplex64Slice(n int) []complex64 {
	a := make([]complex64, n)
	for i := 0; i < n; i++ {
		a[i] = readComplex64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readComplex64() complex64 {
	re := readFloat32()
	im := readFloat32()
	return complex(re, im)
}

// Declaring a private method to read input from stdin
func readComplex128Slice(n int) []complex128 {
	a := make([]complex128, n)
	for i := 0; i < n; i++ {
		a[i] = readComplex128()
	}
	return a
}

// Declaring a private method to read input from stdin
func readComplex128() complex128 {
	re := readFloat64()
	im := readFloat64()
	return complex(re, im)
}

// Declaring a private method to read input from stdin
func readStringSlice(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = readString()
	}
	return a
}

// Declaring a private method to read input from stdin
func readString() string {
	sc.Scan()
	return sc.Text()
}

// Declaring a private method to read input from stdin
func readStringArray(n int) [n]string {
	a := [n]string{}
	for i := 0; i < n; i++ {
		a[i] = readString()
	}
	return a
}

// Declaring a private method to read input from stdin
func readIntSlice(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readInt()
	}
	return a
}

// Declaring a private method to read input from stdin
func readIntArray(n int) [n]int {
	a := [n]int{}
	for i := 0; i < n; i++ {
		a[i] = readInt()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt64Slice(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt64Array(n int) [n]int64 {
	a := [n]int64{}
	for i := 0; i < n; i++ {
		a[i] = readInt64()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt16Slice(n int) []int16 {
	a := make([]int16, n)
	for i := 0; i < n; i++ {
		a[i] = readInt16()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt16Array(n int) [n]int16 {
	a := [n]int16{}
	for i := 0; i < n; i++ {
		a[i] = readInt16()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt8Slice(n int) []int8 {
	a := make([]int8, n)
	for i := 0; i < n; i++ {
		a[i] = readInt8()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt8Array(n int) [n]int8 {
	a := [n]int8{}
	for i := 0; i < n; i++ {
		a[i] = readInt8()
	}
	return a
}

// Declaring a private method to read input from stdin
func readInt32Slice(n int) []int32 {
	a := make([]int32, n)
	for i := 0; i < n; i++ {
		a[i] = readInt32()
	}
	return a
}

// Dec