
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	r, _ := strconv.Atoi(nextString())
	d, _ := strconv.Atoi(nextString())
	x, _ := strconv.ParseInt(nextString(), 10, 64)
	for i := 0; i < 10; i++ {
		x = int64(r*int(x) - d)
		fmt.Fprintln(out, x)
	}
	out.Flush()
}

func nextString() string {
	sc := bufio.NewScanner(in)
	sc.Scan()
	return sc.Text()
}

func nextBytes() []byte {
	sc := bufio.NewScanner(in)
	sc.Scan()
	return sc.Bytes()
}

func nextInt() int {
	i, _ := strconv.Atoi(nextString())
	return i
}

func nextInt64() int64 {
	i, _ := strconv.ParseInt(nextString(), 10, 64)
	return i
}

func debugPrintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

func ReadString(reader *bufio.Reader) string {
	sc := bufio.NewScanner(reader)
	sc.Scan()
	return sc.Text()
}

func ReadBytes(reader *bufio.Reader) []byte {
	sc := bufio.NewScanner(reader)
	sc.Scan()
	return sc.Bytes()
}

func ReadInt(reader *bufio.Reader) int {
	i, _ := strconv.Atoi(ReadString(reader))
	return i
}

func ReadInt64(reader *bufio.Reader) int64 {
	i, _ := strconv.ParseInt(ReadString(reader), 10, 64)
	return i
}

func debugPrint(a...interface{}) {
	fmt.Fprint(os.Stderr, a...)
}

func debugPrintln(a...interface{}) {
	fmt.Fprintln(os.Stderr, a...)
}

func ReadStringSlice(reader *bufio.Reader) []string {
	return strings.Fields(ReadString(reader))
}

func ReadIntSlice(reader *bufio.Reader) []int {
	a := []int{}
	c := 1
	x := ReadInt(reader)
	for x!= 0 {
		a = append(a, x)
		x = ReadInt(reader)
		c++
	}
	return a[:c-1]
}

func ReadInt64Slice(reader *bufio.Reader) []int64 {
	a := []int64{}
	c := 1
	x := ReadInt64(reader)
	for x!= 0 {
		a = append(a, x)
		x = ReadInt64(reader)
		c++
	}
	return a[:c-1]
}

func ReadInt64Slice2(reader *bufio.Reader, n int) []int64 {
	a := []int64{}
	c := 0
	for c < n {
		x := ReadInt64(reader)
		a = append(a, x)
		c++
	}
	return a
}

func ReadIntSlice2(reader *bufio.Reader, n int) []int {
	a := []int{}
	c := 0
	for c < n {
		x := ReadInt(reader)
		a = append(a, x)
		c++
	}
	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func mod(a, b int) int {
	return a - b*int(math.Floor(float64(a)/float64(b)))
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func nextPermutation(a []int) bool {
	i := len(a) - 1
	for i > 0 && a[i-1] >= a[i] {
		i--
	}
	if i == 0 {
		return false
	}
	j := len(a) - 1
	for j >= 0 && a[j] <= a[i-1] {
		j--
	}
	a[i-1], a[j] = a[j], a[i-1]
	j = len(a) - 1
	for i < j {
		a[i], a[j] = a[j], a[i]
		i++
		j--
	}
	return true
}

func minIntSlice(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice2(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice2(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice3(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice3(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice4(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice4(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice5(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice5(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice6(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice6(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice7(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice7(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice8(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice8(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice9(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice9(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice10(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice10(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice11(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice11(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice12(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice12(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice13(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice13(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice14(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice14(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice15(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice15(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice16(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice16(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice17(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice17(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice18(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice18(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice19(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice19(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice20(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice20(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice21(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice21(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice22(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice22(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice23(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice23(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice24(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice24(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice25(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice25(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice26(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice26(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice27(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice27(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice28(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice28(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice29(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func maxIntSlice29(a []int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

func minIntSlice30(a []int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func 