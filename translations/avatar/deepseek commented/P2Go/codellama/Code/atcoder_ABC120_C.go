package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	// Read input string from the user
	s := readLine()

	// Check if all characters in the string are the same
	if len(s) == 1 {
		fmt.Println(0)
		return
	}

	// Count the frequency of each character in the string
	a := make(map[rune]int)
	for _, c := range s {
		a[c]++
	}

	// Calculate the answer as twice the minimum frequency of any character
	ans := 0
	for _, v := range a {
		if ans == 0 || v < ans {
			ans = v
		}
	}
	ans *= 2

	// Print the answer and exit
	fmt.Println(ans)
}

func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readLines() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
	var lines []string
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return lines
}

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var ints []int
	for scanner.Scan() {
		ints = append(ints, toInt(scanner.Text()))
	}
	return ints
}

func toInt(s string) int {
	x, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return x
}

func toInt64(s string) int64 {
	x, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		panic(err)
	}
	return x
}

func toFloat64(s string) float64 {
	x, err := strconv.ParseFloat(s, 64)
	if err != nil {
		panic(err)
	}
	return x
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

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func sum(a []int) int {
	var ret int
	for _, v := range a {
		ret += v
	}
	return ret
}

func sortInts(a []int) {
	sort.Ints(a)
}

func sortStrings(a []string) {
	sort.Strings(a)
}

func reverse(a []int) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseStrings(a []string) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func uniqueInts(a []int) []int {
	sortInts(a)
	j := 0
	for i := 1; i < len(a); i++ {
		if a[j] != a[i] {
			a[j+1] = a[i]
			j++
		}
	}
	return a[:j+1]
}

func uniqueStrings(a []string) []string {
	sortStrings(a)
	j := 0
	for i := 1; i < len(a); i++ {
		if a[j] != a[i] {
			a[j+1] = a[i]
			j++
		}
	}
	return a[:j+1]
}

func intsToString(a []int) string {
	var builder strings.Builder
	for i, v := range a {
		if i > 0 {
			builder.WriteRune(' ')
		}
		builder.WriteString(strconv.Itoa(v))
	}
	return builder.String()
}

func stringsToString(a []string) string {
	var builder strings.Builder
	for i, v := range a {
		if i > 0 {
			builder.WriteRune(' ')
		}
		builder.WriteString(v)
	}
	return builder.String()
}

func intsToBytes(a []int) []byte {
	n := len(a)
	b := make([]byte, 8*n)
	for i, v := range a {
		binary.LittleEndian.PutUint64(b[i*8:], uint64(v))
	}
	return b
}

func bytesToInts(b []byte) []int {
	n := len(b) / 8
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = int(binary.LittleEndian.Uint64(b[i*8:]))
	}
	return a
}

func intsToInt64s(a []int) []int64 {
	n := len(a)
	b := make([]int64, n)
	for i, v := range a {
		b[i] = int64(v)
	}
	return b
}

func int64sToInts(b []int64) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v)
	}
	return a
}

func intsToFloat64s(a []int) []float64 {
	n := len(a)
	b := make([]float64, n)
	for i, v := range a {
		b[i] = float64(v)
	}
	return b
}

func float64sToInts(b []float64) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v)
	}
	return a
}

func intsToRuneSlice(a []int) []rune {
	n := len(a)
	b := make([]rune, n)
	for i, v := range a {
		b[i] = rune(v)
	}
	return b
}

func runesToInts(b []rune) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v)
	}
	return a
}

func intsToByteSlice(a []int) []byte {
	n := len(a)
	b := make([]byte, n)
	for i, v := range a {
		b[i] = byte(v)
	}
	return b
}

func bytesToInts(b []byte) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v)
	}
	return a
}

func intsToFloat64Slice(a []int) []float64 {
	n := len(a)
	b := make([]float64, n)
	for i, v := range a {
		b[i] = float64(v)
	}
	return b
}

func float64sToInts(b []float64) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v)
	}
	return a
}

func intsToBoolSlice(a []int) []bool {
	n := len(a)
	b := make([]bool, n)
	for i, v := range a {
		b[i] = v != 0
	}
	return b
}

func boolSliceToInts(b []bool) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		if v {
			a[i] = 1
		}
	}
	return a
}

func intsToComplex128Slice(a []int) []complex128 {
	n := len(a)
	b := make([]complex128, n)
	for i, v := range a {
		b[i] = complex(float64(v), 0)
	}
	return b
}

func complex128sToInts(b []complex128) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(real(v))
	}
	return a
}

func intsToRuneSlice2(a []int) [][]rune {
	n := len(a)
	b := make([][]rune, n)
	for i, v := range a {
		b[i] = []rune(strconv.Itoa(v))
	}
	return b
}

func runesSliceToInts(b [][]rune) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i], _ = strconv.Atoi(string(v))
	}
	return a
}

func intsToByteSlice2(a []int) [][]byte {
	n := len(a)
	b := make([][]byte, n)
	for i, v := range a {
		b[i] = []byte(strconv.Itoa(v))
	}
	return b
}

func bytesSliceToInts(b [][]byte) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i], _ = strconv.Atoi(string(v))
	}
	return a
}

func intsToFloat64Slice2(a []int) [][]float64 {
	n := len(a)
	b := make([][]float64, n)
	for i, v := range a {
		b[i] = []float64{float64(v)}
	}
	return b
}

func float64sSliceToInts(b [][]float64) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v[0])
	}
	return a
}

func intsToBoolSlice2(a []int) [][]bool {
	n := len(a)
	b := make([][]bool, n)
	for i, v := range a {
		b[i] = []bool{v != 0}
	}
	return b
}

func boolSlicesToInts(b [][]bool) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		if v[0] {
			a[i] = 1
		}
	}
	return a
}

func intsToComplex128Slice2(a []int) [][]complex128 {
	n := len(a)
	b := make([][]complex128, n)
	for i, v := range a {
		b[i] = []complex128{complex(float64(v), 0)}
	}
	return b
}

func complex128sSliceToInts(b [][]complex128) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(real(v[0]))
	}
	return a
}

func intsToRuneSlice3(a []int) [][][]rune {
	n := len(a)
	b := make([][][]rune, n)
	for i, v := range a {
		b[i] = [][]rune{[]rune(strconv.Itoa(v))}
	}
	return b
}

func runesSlicesToInts(b [][][]rune) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i], _ = strconv.Atoi(string(v[0]))
	}
	return a
}

func intsToByteSlice3(a []int) [][][]byte {
	n := len(a)
	b := make([][][]byte, n)
	for i, v := range a {
		b[i] = [][]byte{[]byte(strconv.Itoa(v))}
	}
	return b
}

func bytesSlicesToInts(b [][][]byte) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i], _ = strconv.Atoi(string(v[0]))
	}
	return a
}

func intsToFloat64Slice3(a []int) [][][]float64 {
	n := len(a)
	b := make([][][]float64, n)
	for i, v := range a {
		b[i] = [][]float64{{float64(v)}}
	}
	return b
}

func float64sSlicesToInts(b [][][]float64) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v[0][0])
	}
	return a
}

func intsToBoolSlice3(a []int) [][][]bool {
	n := len(a)
	b := make([][][]bool, n)
	for i, v := range a {
		b[i] = [][]bool{{v != 0}}
	}
	return b
}

func boolSlicesToInts2(b [][][]bool) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		if v[0][0] {
			a[i] = 1
		}
	}
	return a
}

func intsToComplex128Slice3(a []int) [][][]complex128 {
	n := len(a)
	b := make([][][]complex128, n)
	for i, v := range a {
		b[i] = [][]complex128{{complex(float64(v), 0)}}
	}
	return b
}

func complex128sSlicesToInts(b [][][]complex128) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(real(v[0][0]))
	}
	return a
}

func intsToRuneSlice4(a []int) [][][][]rune {
	n := len(a)
	b := make([][][][]rune, n)
	for i, v := range a {
		b[i] = [][][]rune{{[]rune(strconv.Itoa(v))}}
	}
	return b
}

func runesSlicesToInts2(b [][][][]rune) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i], _ = strconv.Atoi(string(v[0][0]))
	}
	return a
}

func intsToByteSlice4(a []int) [][][][]byte {
	n := len(a)
	b := make([][][][]byte, n)
	for i, v := range a {
		b[i] = [][][]byte{{[]byte(strconv.Itoa(v))}}
	}
	return b
}

func bytesSlicesToInts2(b [][][][]byte) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i], _ = strconv.Atoi(string(v[0][0]))
	}
	return a
}

func intsToFloat64Slice4(a []int) [][][][]float64 {
	n := len(a)
	b := make([][][][]float64, n)
	for i, v := range a {
		b[i] = [][][]float64{{{float64(v)}}}
	}
	return b
}

func float64sSlicesToInts2(b [][][][]float64) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(v[0][0][0])
	}
	return a
}

func intsToBoolSlice4(a []int) [][][][]bool {
	n := len(a)
	b := make([][][][]bool, n)
	for i, v := range a {
		b[i] = [][][]bool{{{v != 0}}}
	}
	return b
}

func boolSlicesToInts3(b [][][][]bool) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		if v[0][0][0] {
			a[i] = 1
		}
	}
	return a
}

func intsToComplex128Slice4(a []int) [][][][]complex128 {
	n := len(a)
	b := make([][][][]complex128, n)
	for i, v := range a {
		b[i] = [][][]complex128{{{complex(float64(v), 0)}}}
	}
	return b
}

func complex128sSlicesToInts2(b [][][][]complex128) []int {
	n := len(b)
	a := make([]int, n)
	for i, v := range b {
		a[i] = int(real(v[0][0][0]))
	}
	return a
}

func intsToRuneSlice5(a []int) [][][][][]rune {
	n := len(a)
	b := make([][][][][]rune, n)
	for i, v := range a {
		b[i] = [][][][]rune{{[][]rune{[]rune(strconv.Itoa(v))}}}
	}
	return b
}

func runesSlicesToInts3(b [][][][][]rune) []int {
	n := len(b)
	a := make([]int, n)
	for i, v 