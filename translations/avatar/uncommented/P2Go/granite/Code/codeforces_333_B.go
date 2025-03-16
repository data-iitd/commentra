
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	n, m := read2Int()
	b := make([]int, n*2)
	for i := 0; i < n*2; i++ {
		b[i] = 1
	}
	b[0], b[n-1], b[n], b[2*n-1] = 0, 0, 0, 0
	for i := 0; i < m; i++ {
		r, c := read2Int()
		b[r-1], b[n+c-1] = 0, 0
	}
	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}
	sum := 0
	for i := 0; i < n*2; i++ {
		sum += b[i]
	}
	fmt.Println(sum)
}

func read2Int() (int, int) {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	sp := strings.Split(s, " ")
	a, _ := strconv.Atoi(sp[0])
	b, _ := strconv.Atoi(sp[1])
	return a, b
}

func readInt() int {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	a, _ := strconv.Atoi(s)
	return a
}

func readString() string {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func readBytes() []byte {
	s, _ := in.ReadBytes('\n')
	return s[:len(s)-1]
}

func readInt64() int64 {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	a, _ := strconv.ParseInt(s, 10, 64)
	return a
}

func readFloat64() float64 {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	a, _ := strconv.ParseFloat(s, 64)
	return a
}

func readNInt64(n int) []int64 {
	res := make([]int64, n)
	for i := 0; i < n; i++ {
		res[i] = readInt64()
	}
	return res
}

func readNFloat64(n int) []float64 {
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = readFloat64()
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

func readNString(n int) []string {
	res := make([]string, n)
	for i := 0; i < n; i++ {
		res[i] = readString()
	}
	return res
}

func readUint64() uint64 {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	a, _ := strconv.ParseUint(s, 10, 64)
	return a
}

func readIntN(n int) []int {
	res := make([]int, n)
	x := 0
	buf := make([]byte, 10)
	for i := 0; i < n; i++ {
		for x < len(buf) && (buf[x] < '0' || buf[x] > '9') {
			if buf[x] == '\n' {
				x = 0
			}
			x++
		}
		res[i], _ = strconv.Atoi(string(buf[x:]))
		x = 0
	}
	return res
}

func readIntNN(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntN(m)
	}
	return res
}

func readIntNNN(n int, m int, k int) [][][]int {
	res := make([][][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntNN(m, k)
	}
	return res
}

func readBool() bool {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	b, _ := strconv.ParseBool(s)
	return b
}

func readBoolN(n int) []bool {
	res := make([]bool, n)
	for i := 0; i < n; i++ {
		res[i] = readBool()
	}
	return res
}

func readRunes() []rune {
	s, _ := in.ReadString('\n')
	s = s[:len(s)-1]
	return []rune(s)
}

func readStringN(n int) []string {
	res := make([]string, n)
	for i := 0; i < n; i++ {
		res[i] = readString()
	}
	return res
}

func readBytesN(n int) [][]byte {
	res := make([][]byte, n)
	for i := 0; i < n; i++ {
		res[i], _ = in.ReadBytes('\n')
	}
	return res
}

func readInt64N(n int) []int64 {
	res := make([]int64, n)
	for i := 0; i < n; i++ {
		res[i] = readInt64()
	}
	return res
}

func readInt64NN(n int, m int) [][]int64 {
	res := make([][]int64, n)
	for i := 0; i < n; i++ {
		res[i] = readInt64N(m)
	}
	return res
}

func readInt64NNN(n int, m int, k int) [][][]int64 {
	res := make([][][]int64, n)
	for i := 0; i < n; i++ {
		res[i] = readInt64NN(m, k)
	}
	return res
}

func readFloat64N(n int) []float64 {
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = readFloat64()
	}
	return res
}

func readFloat64NN(n int, m int) [][]float64 {
	res := make([][]float64, n)
	for i := 0; i < n; i++ {
		res[i] = readFloat64N(m)
	}
	return res
}

func readFloat64NNN(n int, m int, k int) [][][]float64 {
	res := make([][][]float64, n)
	for i := 0; i < n; i++ {
		res[i] = readFloat64NN(m, k)
	}
	return res
}

func readStringN(n int) []string {
	res := make([]string, n)
	for i := 0; i < n; i++ {
		res[i] = readString()
	}
	return res
}

func readStringNN(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringN(m)
	}
	return res
}

func readStringNNN(n int, m int, k int) [][][]string {
	res := make([][][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringNN(m, k)
	}
	return res
}

func readBoolN(n int) []bool {
	res := make([]bool, n)
	for i := 0; i < n; i++ {
		res[i] = readBool()
	}
	return res
}

func readBoolNN(n int, m int) [][]bool {
	res := make([][]bool, n)
	for i := 0; i < n; i++ {
		res[i] = readBoolN(m)
	}
	return res
}

func readBoolNNN(n int, m int, k int) [][][]bool {
	res := make([][][]bool, n)
	for i := 0; i < n; i++ {
		res[i] = readBoolNN(m, k)
	}
	return res
}

func readBytesN(n int) [][]byte {
	res := make([][]byte, n)
	for i := 0; i < n; i++ {
		res[i], _ = in.ReadBytes('\n')
	}
	return res
}

func readBytesNN(n int, m int) [][]byte {
	res := make([][]byte, n)
	for i := 0; i < n; i++ {
		res[i] = readBytesN(m)
	}
	return res
}

func readBytesNNN(n int, m int, k int) [][][]byte {
	res := make([][][]byte, n)
	for i := 0; i < n; i++ {
		res[i] = readBytesNN(m, k)
	}
	return res
}

func readRunesN(n int) [][]rune {
	res := make([][]rune, n)
	for i := 0; i < n; i++ {
		res[i], _ = in.ReadBytes('\n')
	}
	return res
}

func readRunesNN(n int, m int) [][]rune {
	res := make([][]rune, n)
	for i := 0; i < n; i++ {
		res[i] = readRunesN(m)
	}
	return res
}

func readRunesNNN(n int, m int, k int) [][][]rune {
	res := make([][][]rune, n)
	for i := 0; i < n; i++ {
		res[i] = readRunesNN(m, k)
	}
	return res
}

func readComplex64N(n int) []complex64 {
	res := make([]complex64, n)
	for i := 0; i < n; i++ {
		res[i] = readComplex64()
	}
	return res
}

func readComplex64NN(n int, m int) [][]complex64 {
	res := make([][]complex64, n)
	for i := 0; i < n; i++ {
		res[i] = readComplex64N(m)
	}
	return res
}

func readComplex64NNN(n int, m int, k int) [][][]complex64 {
	res := make([][][]complex64, n)
	for i := 0; i < n; i++ {
		res[i] = readComplex64NN(m, k)
	}
	return res
}

func readComplex128N(n int) []complex128 {
	res := make([]complex128, n)
	for i := 0; i < n; i++ {
		res[i] = readComplex128()
	}
	return res
}

func readComplex128NN(n int, m int) [][]complex128 {
	res := make([][]complex128, n)
	for i := 0; i < n; i++ {
		res[i] = readComplex128N(m)
	}
	return res
}

func readComplex128NNN(n int, m int, k int) [][][]complex128 {
	res := make([][][]complex128, n)
	for i := 0; i < n; i++ {
		res[i] = readComplex128NN(m, k)
	}
	return res
}

func readDurationN(n int) []time.Duration {
	res := make([]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDuration()
	}
	return res
}

func readDurationNN(n int, m int) [][]time.Duration {
	res := make([][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationN(m)
	}
	return res
}

func readDurationNNN(n int, m int, k int) [][][]time.Duration {
	res := make([][][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationNN(m, k)
	}
	return res
}

func readTimeN(n int) []time.Time {
	res := make([]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTime()
	}
	return res
}

func readTimeNN(n int, m int) [][]time.Time {
	res := make([][]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTimeN(m)
	}
	return res
}

func readTimeNNN(n int, m int, k int) [][][]time.Time {
	res := make([][][]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTimeNN(m, k)
	}
	return res
}

func readDurationN(n int) []time.Duration {
	res := make([]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDuration()
	}
	return res
}

func readDurationNN(n int, m int) [][]time.Duration {
	res := make([][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationN(m)
	}
	return res
}

func readDurationNNN(n int, m int, k int) [][][]time.Duration {
	res := make([][][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationNN(m, k)
	}
	return res
}

func readTimeN(n int) []time.Time {
	res := make([]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTime()
	}
	return res
}

func readTimeNN(n int, m int) [][]time.Time {
	res := make([][]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTimeN(m)
	}
	return res
}

func readTimeNNN(n int, m int, k int) [][][]time.Time {
	res := make([][][]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTimeNN(m, k)
	}
	return res
}

func readDurationN(n int) []time.Duration {
	res := make([]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDuration()
	}
	return res
}

func readDurationNN(n int, m int) [][]time.Duration {
	res := make([][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationN(m)
	}
	return res
}

func readDurationNNN(n int, m int, k int) [][][]time.Duration {
	res := make([][][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationNN(m, k)
	}
	return res
}

func readTimeN(n int) []time.Time {
	res := make([]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTime()
	}
	return res
}

func readTimeNN(n int, m int) [][]time.Time {
	res := make([][]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTimeN(m)
	}
	return res
}

func readTimeNNN(n int, m int, k int) [][][]time.Time {
	res := make([][][]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTimeNN(m, k)
	}
	return res
}

func readDurationN(n int) []time.Duration {
	res := make([]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDuration()
	}
	return res
}

func readDurationNN(n int, m int) [][]time.Duration {
	res := make([][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationN(m)
	}
	return res
}

func readDurationNNN(n int, m int, k int) [][][]time.Duration {
	res := make([][][]time.Duration, n)
	for i := 0; i < n; i++ {
		res[i] = readDurationNN(m, k)
	}
	return res
}

func readTimeN(n int) []time.Time {
	res := make([]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTime()
	}
	return res
}

func readTimeNN(n int, m int) [][]time.Time {
	res := make([][]time.Time, n)
	for i := 0; i < n; i++ {
		res[i] = readTimeN(m)
	}
	return res
}
