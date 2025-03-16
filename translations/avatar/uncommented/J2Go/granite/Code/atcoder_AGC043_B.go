
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
	n, _ := strconv.Atoi(read())
	s := read()
	sb := strings.Builder{}
	for i := 1; i < n; i++ {
		sb.WriteString(strconv.Itoa(int(s[i]-s[i-1])))
	}
	if n == 2 {
		fmt.Println(sb.String()[0])
		return
	}
	s = sb.String()
	if strings.Contains(s, "1") {
		fmt.Println(cal(s, '1'))
		return
	}
	fmt.Println(cal(s, '2') * 2)
}

func cal(s string, c byte) int {
	n := len(s)
	ans := 0
	for i := 0; i < n; i++ {
		if s[i] == c && (n-1)&i == i {
			ans ^= 1
		}
	}
	return ans
}

func read() string {
	s := make([]byte, 0)
	for {
		c, _ := in.ReadByte()
		if c =='' || c == '\n' {
			break
		}
		s = append(s, c)
	}
	return string(s)
}

func readInt() int {
	s := read()
	res, _ := strconv.Atoi(s)
	return res
}

func readInt64() int64 {
	s := read()
	res, _ := strconv.ParseInt(s, 10, 64)
	return res
}

func readFloat64() float64 {
	s := read()
	res, _ := strconv.ParseFloat(s, 64)
	return res
}

func readArray(f func(string) string) []string {
	res := make([]string, 0)
	for {
		s := read()
		if s == "" {
			break
		}
		res = append(res, f(s))
	}
	return res
}

func readStringArray() []string {
	return readArray(func(s string) string { return s })
}

func readInt64Array() []int64 {
	return readArray(func(s string) string {
		res, _ := strconv.ParseInt(s, 10, 64)
		return strconv.FormatInt(res, 10)
	})
}

func readFloat64Array() []float64 {
	return readArray(func(s string) string {
		res, _ := strconv.ParseFloat(s, 64)
		return strconv.FormatFloat(res, 'f', 6, 64)
	})
}

func readIntMatrix(n int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray()
	}
	return res
}

func readStringMatrix(n int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray()
	}
	return res
}

func readIntMatrix2(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray2(m)
	}
	return res
}

func readStringMatrix2(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray2(m)
	}
	return res
}

func readIntArray() []int {
	return readIntArray2(0)
}

func readStringArray() []string {
	return readStringArray2(0)
}

func readIntArray2(m int) []int {
	s := readStringArray2(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray2(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array2(m int) []int64 {
	s := readStringArray2(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = append(res, i)
	}
	return res
}

func readFloat64Array2(m int) []float64 {
	s := readStringArray2(m)
	res := make([]float64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseFloat(s2, 64)
		res = append(res, i)
	}
	return res
}

func readIntMatrix3(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray3(m)
	}
	return res
}

func readStringMatrix3(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray3(m)
	}
	return res
}

func readIntArray3(m int) []int {
	s := readStringArray3(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray3(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array3(m int) []int64 {
	s := readStringArray3(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = append(res, i)
	}
	return res
}

func readFloat64Array3(m int) []float64 {
	s := readStringArray3(m)
	res := make([]float64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseFloat(s2, 64)
		res = append(res, i)
	}
	return res
}

func readIntMatrix4(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray4(m)
	}
	return res
}

func readStringMatrix4(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray4(m)
	}
	return res
}

func readIntArray4(m int) []int {
	s := readStringArray4(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray4(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array4(m int) []int64 {
	s := readStringArray4(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = append(res, i)
	}
	return res
}

func readFloat64Array4(m int) []float64 {
	s := readStringArray4(m)
	res := make([]float64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseFloat(s2, 64)
		res = append(res, i)
	}
	return res
}

func readIntMatrix5(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray5(m)
	}
	return res
}

func readStringMatrix5(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray5(m)
	}
	return res
}

func readIntArray5(m int) []int {
	s := readStringArray5(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray5(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array5(m int) []int64 {
	s := readStringArray5(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = append(res, i)
	}
	return res
}

func readFloat64Array5(m int) []float64 {
	s := readStringArray5(m)
	res := make([]float64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseFloat(s2, 64)
		res = append(res, i)
	}
	return res
}

func readIntMatrix6(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray6(m)
	}
	return res
}

func readStringMatrix6(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray6(m)
	}
	return res
}

func readIntArray6(m int) []int {
	s := readStringArray6(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray6(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array6(m int) []int64 {
	s := readStringArray6(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = append(res, i)
	}
	return res
}

func readFloat64Array6(m int) []float64 {
	s := readStringArray6(m)
	res := make([]float64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseFloat(s2, 64)
		res = append(res, i)
	}
	return res
}

func readIntMatrix7(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray7(m)
	}
	return res
}

func readStringMatrix7(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray7(m)
	}
	return res
}

func readIntArray7(m int) []int {
	s := readStringArray7(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray7(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array7(m int) []int64 {
	s := readStringArray7(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = append(res, i)
	}
	return res
}

func readFloat64Array7(m int) []float64 {
	s := readStringArray7(m)
	res := make([]float64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseFloat(s2, 64)
		res = append(res, i)
	}
	return res
}

func readIntMatrix8(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray8(m)
	}
	return res
}

func readStringMatrix8(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray8(m)
	}
	return res
}

func readIntArray8(m int) []int {
	s := readStringArray8(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray8(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array8(m int) []int64 {
	s := readStringArray8(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = append(res, i)
	}
	return res
}

func readFloat64Array8(m int) []float64 {
	s := readStringArray8(m)
	res := make([]float64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseFloat(s2, 64)
		res = append(res, i)
	}
	return res
}

func readIntMatrix9(n int, m int) [][]int {
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = readIntArray9(m)
	}
	return res
}

func readStringMatrix9(n int, m int) [][]string {
	res := make([][]string, n)
	for i := 0; i < n; i++ {
		res[i] = readStringArray9(m)
	}
	return res
}

func readIntArray9(m int) []int {
	s := readStringArray9(m)
	res := make([]int, 0)
	for _, s2 := range s {
		i, _ := strconv.Atoi(s2)
		res = append(res, i)
	}
	return res
}

func readStringArray9(m int) []string {
	s := readArray(func(s string) string { return s })
	if m > 0 && len(s)!= m {
		panic("invalid array length")
	}
	return s
}

func readInt64Array9(m int) []int64 {
	s := readStringArray9(m)
	res := make([]int64, 0)
	for _, s2 := range s {
		i, _ := strconv.ParseInt(s2, 10, 64)
		res = a