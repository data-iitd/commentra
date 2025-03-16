
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	n, k := readInt(), readInt()
	a := readIntSlice(n)
	sort.Ints(a)
	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}
	fmt.Println(ans)
}

func readInt() int {
	i, _ := strconv.Atoi(read())
	return i
}

func readIntSlice(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readInt()
	}
	return a
}

func read() string {
	s, _ := in.ReadString('\n')
	return strings.TrimSpace(s)
}

func readStringSlice(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = read()
	}
	return a
}

func readInts(a []int) {
	for i := 0; i < len(a); i++ {
		a[i] = readInt()
	}
}

func readFloat64() float64 {
	f, _ := strconv.ParseFloat(read(), 64)
	return f
}

func readFloat64Slice(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readFloat64()
	}
	return a
}

func readBool() bool {
	b, _ := strconv.ParseBool(read())
	return b
}

func readBoolSlice(n int) []bool {
	a := make([]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readBool()
	}
	return a
}

func readBytes() []byte {
	return []byte(read())
}

func readString() string {
	return read()
}

func readStringSlice(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = readString()
	}
	return a
}

func readLine() string {
	str, _ := in.ReadString('\n')
	return strings.TrimSpace(str)
}

func readTemplate(s string) string {
	str, _ := in.ReadString(s[0])
	return strings.TrimSpace(str)
}

func readTemplateLine(s string) string {
	str, _ := in.ReadString('\n')
	return strings.TrimSpace(strings.Replace(str, s, "", 1))
}

func readLineSlice() []string {
	str, _ := in.ReadString('\n')
	return strings.Fields(str)
}

func readLineIntSlice() []int {
	a := readLineSlice()
	b := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		b[i], _ = strconv.Atoi(a[i])
	}
	return b
}

func readLineInt64Slice() []int64 {
	a := readLineSlice()
	b := make([]int64, len(a))
	for i := 0; i < len(a); i++ {
		b[i], _ = strconv.ParseInt(a[i], 10, 64)
	}
	return b
}

func readLineFloat64Slice() []float64 {
	a := readLineSlice()
	b := make([]float64, len(a))
	for i := 0; i < len(a); i++ {
		b[i], _ = strconv.ParseFloat(a[i], 64)
	}
	return b
}

func readLineBoolSlice() []bool {
	a := readLineSlice()
	b := make([]bool, len(a))
	for i := 0; i < len(a); i++ {
		b[i], _ = strconv.ParseBool(a[i])
	}
	return b
}

func readLineStringSlice() []string {
	a := readLineSlice()
	b := make([]string, len(a))
	for i := 0; i < len(a); i++ {
		b[i] = a[i]
	}
	return b
}

func readLineBytesSlice() [][]byte {
	a := readLineSlice()
	b := make([][]byte, len(a))
	for i := 0; i < len(a); i++ {
		b[i] = []byte(a[i])
	}
	return b
}

func readLineInt() int {
	a, _ := strconv.Atoi(readLine())
	return a
}

func readLineInt64() int64 {
	a, _ := strconv.ParseInt(readLine(), 10, 64)
	return a
}

func readLineFloat64() float64 {
	a, _ := strconv.ParseFloat(readLine(), 64)
	return a
}

func readLineBool() bool {
	a, _ := strconv.ParseBool(readLine())
	return a
}

func readLineString() string {
	return readLine()
}

func readLineBytes() []byte {
	return []byte(readLine())
}

func readNInt64s(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readLineInt64()
	}
	return a
}

func readNInt(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readLineInt()
	}
	return a
}

func readNFloat64s(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readLineFloat64()
	}
	return a
}

func readNBools(n int) []bool {
	a := make([]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readLineBool()
	}
	return a
}

func readNStrings(n int) []string {
	a := make([]string, n)
	for i := 0; i < n; i++ {
		a[i] = readLineString()
	}
	return a
}

func readNBytes(n int) [][]byte {
	a := make([][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = readLineBytes()
	}
	return a
}

func read2DInt(n, m int) [][]int {
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = readLineIntSlice()
	}
	return a
}

func read2DInt64(n, m int) [][]int64 {
	a := make([][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readLineInt64Slice()
	}
	return a
}

func read2DFloat64(n, m int) [][]float64 {
	a := make([][]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readLineFloat64Slice()
	}
	return a
}

func read2DString(n, m int) [][]string {
	a := make([][]string, n)
	for i := 0; i < n; i++ {
		a[i] = readLineStringSlice()
	}
	return a
}

func read2DBytes(n, m int) [][][]byte {
	a := make([][][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = readLineBytesSlice()
	}
	return a
}

func read3DInt(n, m, l int) [][][]int {
	a := make([][][]int, n)
	for i := 0; i < n; i++ {
		a[i] = read2DInt(m, l)
	}
	return a
}

func read3DInt64(n, m, l int) [][][]int64 {
	a := make([][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = read2DInt64(m, l)
	}
	return a
}

func read3DFloat64(n, m, l int) [][][]float64 {
	a := make([][][]float64, n)
	for i := 0; i < n; i++ {
		a[i] = read2DFloat64(m, l)
	}
	return a
}

func read3DString(n, m, l int) [][][]string {
	a := make([][][]string, n)
	for i := 0; i < n; i++ {
		a[i] = read2DString(m, l)
	}
	return a
}

func read3DBytes(n, m, l int) [][][][]byte {
	a := make([][][][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = read2DBytes(m, l)
	}
	return a
}

func readMatrixInt(n int) [][]int {
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = readLineIntSlice()
	}
	return a
}

func readMatrixInt64(n int) [][]int64 {
	a := make([][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readLineInt64Slice()
	}
	return a
}

func readMatrixFloat64(n int) [][]float64 {
	a := make([][]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readLineFloat64Slice()
	}
	return a
}

func readMatrixString(n int) [][]string {
	a := make([][]string, n)
	for i := 0; i < n; i++ {
		a[i] = readLineStringSlice()
	}
	return a
}

func readMatrixBytes(n int) [][][]byte {
	a := make([][][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = readLineBytesSlice()
	}
	return a
}

func readMatrixRunes(n int) [][][]rune {
	a := make([][][]rune, n)
	for i := 0; i < n; i++ {
		a[i] = readLineRunesSlice()
	}
	return a
}

func readMatrixBool(n int) [][]bool {
	a := make([][]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readLineBoolSlice()
	}
	return a
}

func readMatrixInt64s(n int) [][][]int64 {
	a := make([][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixInt64(n)
	}
	return a
}

func readMatrixFloat64s(n int) [][][]float64 {
	a := make([][][]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixFloat64(n)
	}
	return a
}

func readMatrixStrings(n int) [][][]string {
	a := make([][][]string, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixString(n)
	}
	return a
}

func readMatrixBytes(n int) [][][][]byte {
	a := make([][][][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixBytes(n)
	}
	return a
}

func readMatrixRunes(n int) [][][][]rune {
	a := make([][][][]rune, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixRunes(n)
	}
	return a
}

func readMatrixBools(n int) [][][]bool {
	a := make([][][]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixBool(n)
	}
	return a
}

func read4DInt(n, m, l, o int) [][][][]int {
	a := make([][][][]int, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixInt(m, l, o)
	}
	return a
}

func read4DInt64(n, m, l, o int) [][][][][]int64 {
	a := make([][][][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixInt64(m, l, o)
	}
	return a
}

func read4DFloat64(n, m, l, o int) [][][][][]float64 {
	a := make([][][][][]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixFloat64(m, l, o)
	}
	return a
}

func read4DString(n, m, l, o int) [][][][][]string {
	a := make([][][][][]string, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixString(m, l, o)
	}
	return a
}

func read4DBytes(n, m, l, o int) [][][][][][]byte {
	a := make([][][][][][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixBytes(m, l, o)
	}
	return a
}

func read4DRunes(n, m, l, o int) [][][][][][]rune {
	a := make([][][][][][]rune, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixRunes(m, l, o)
	}
	return a
}

func read4DBool(n, m, l, o int) [][][][][]bool {
	a := make([][][][][]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixBool(m, l, o)
	}
	return a
}

func read5DInt(n, m, l, o, p int) [][][][][][]int {
	a := make([][][][][][][]int, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixInt(m, l, o, p)
	}
	return a
}

func read5DInt64(n, m, l, o, p int) [][][][][][][]int64 {
	a := make([][][][][][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixInt64(m, l, o, p)
	}
	return a
}

func read5DFloat64(n, m, l, o, p int) [][][][][][][]float64 {
	a := make([][][][][][][]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixFloat64(m, l, o, p)
	}
	return a
}

func read5DString(n, m, l, o, p int) [][][][][][][]string {
	a := make([][][][][][][]string, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixString(m, l, o, p)
	}
	return a
}

func read5DBytes(n, m, l, o, p int) [][][][][][][][]byte {
	a := make([][][][][][][][]byte, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixBytes(m, l, o, p)
	}
	return a
}

func read5DRunes(n, m, l, o, p int) [][][][][][][][]rune {
	a := make([][][][][][][][]rune, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixRunes(m, l, o, p)
	}
	return a
}

func read5DBool(n, m, l, o, p int) [][][][][][][][][]bool {
	a := make([][][][][][][][][]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixBool(m, l, o, p)
	}
	return a
}

func read6DInt(n, m, l, o, p, q int) [][][][][][][][][]int {
	a := make([][][][][][][][][]int, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixInt(m, l, o, p, q)
	}
	return a
}

func read6DInt64(n, m, l, o, p, q int) [][][][][][][][][]int64 {
	a := make([][][][][][][][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readMatrixInt64(m, l, o, p, q)
	}
	return a
}

func read6DFloat64(n, m, l, o, p, q int) [][][][][][][][][]float64 {
	a := make([][][][][][][][][]float64, n)
	for 