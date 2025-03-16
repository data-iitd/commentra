
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	s := make([]byte, n)
	fmt.Fscanf(r, "%s\n", &s)
	sb := make([]byte, n-1)
	for i := 1; i < n; i++ {
		sb[i-1] = byte(int(s[i]) - int(s[i-1]))
	}
	if n == 2 {
		fmt.Fprintf(w, "%c\n", s[0])
		w.Flush()
		return
	}
	s = sb
	var ans int
	for i := 0; i < n-1; i++ {
		if s[i] == '1' {
			ans ^= 1
		}
	}
	if!contains(s, '1') {
		ans *= 2
	}
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

func contains(s []byte, c byte) bool {
	for _, v := range s {
		if v == c {
			return true
		}
	}
	return false
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func pow(a, b int) int {
	r := 1
	for i := 0; i < b; i++ {
		r *= a
	}
	return r
}

func readInt() int {
	s, _ := r.ReadString('\n')
	x, _ := strconv.Atoi(s)
	return x
}

func readInts() []int {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]int, 0)
	for _, num := range strings.Split(s, " ") {
		x, _ := strconv.Atoi(num)
		a = append(a, x)
	}
	return a
}

func readString() string {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func readStrings() []string {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]string, 0)
	for _, s2 := range strings.Split(s, " ") {
		a = append(a, s2)
	}
	return a
}

func readInt64() int64 {
	s, _ := r.ReadString('\n')
	x, _ := strconv.ParseInt(s, 10, 64)
	return x
}

func readInt64s() []int64 {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]int64, 0)
	for _, num := range strings.Split(s, " ") {
		x, _ := strconv.ParseInt(num, 10, 64)
		a = append(a, x)
	}
	return a
}

func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugf(format string, args...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func minInt(a...int) int {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxInt(a...int) int {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func minInt64(a...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxInt64(a...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func minStr(a...string) string {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxStr(a...string) string {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func readBool() bool {
	s, _ := r.ReadString('\n')
	b, _ := strconv.ParseBool(s)
	return b
}

func readBools() []bool {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]bool, 0)
	for _, s2 := range strings.Split(s, " ") {
		b, _ := strconv.ParseBool(s2)
		a = append(a, b)
	}
	return a
}

func readFloat64() float64 {
	s, _ := r.ReadString('\n')
	x, _ := strconv.ParseFloat(s, 64)
	return x
}

func readFloat64s() []float64 {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]float64, 0)
	for _, s2 := range strings.Split(s, " ") {
		x, _ := strconv.ParseFloat(s2, 64)
		a = append(a, x)
	}
	return a
}

func readLine() string {
	s, _ := r.ReadString('\n')
	return s[:len(s)-1]
}

func readLines(n int) []string {
	var lines []string
	for i := 0; i < n; i++ {
		lines = append(lines, readLine())
	}
	return lines
}

func main2() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	s := make([]byte, n)
	fmt.Fscanf(r, "%s\n", &s)
	sb := make([]byte, n-1)
	for i := 1; i < n; i++ {
		sb[i-1] = byte(int(s[i]) - int(s[i-1]))
	}
	if n == 2 {
		fmt.Fprintf(w, "%c\n", s[0])
		w.Flush()
		return
	}
	s = sb
	var ans int
	for i := 0; i < n-1; i++ {
		if s[i] == '1' {
			ans ^= 1
		}
	}
	if!contains(s, '1') {
		ans *= 2
	}
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

func contains(s []byte, c byte) bool {
	for _, v := range s {
		if v == c {
			return true
		}
	}
	return false
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func pow(a, b int) int {
	r := 1
	for i := 0; i < b; i++ {
		r *= a
	}
	return r
}

func readInt() int {
	s, _ := r.ReadString('\n')
	x, _ := strconv.Atoi(s)
	return x
}

func readInts() []int {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]int, 0)
	for _, num := range strings.Split(s, " ") {
		x, _ := strconv.Atoi(num)
		a = append(a, x)
	}
	return a
}

func readString() string {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func readStrings() []string {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]string, 0)
	for _, s2 := range strings.Split(s, " ") {
		a = append(a, s2)
	}
	return a
}

func readInt64() int64 {
	s, _ := r.ReadString('\n')
	x, _ := strconv.ParseInt(s, 10, 64)
	return x
}

func readInt64s() []int64 {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]int64, 0)
	for _, num := range strings.Split(s, " ") {
		x, _ := strconv.ParseInt(num, 10, 64)
		a = append(a, x)
	}
	return a
}

func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugf(format string, args...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func minInt(a...int) int {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxInt(a...int) int {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func minInt64(a...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxInt64(a...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func minStr(a...string) string {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxStr(a...string) string {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func readBool() bool {
	s, _ := r.ReadString('\n')
	b, _ := strconv.ParseBool(s)
	return b
}

func readBools() []bool {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]bool, 0)
	for _, s2 := range strings.Split(s, " ") {
		b, _ := strconv.ParseBool(s2)
		a = append(a, b)
	}
	return a
}

func readFloat64() float64 {
	s, _ := r.ReadString('\n')
	x, _ := strconv.ParseFloat(s, 64)
	return x
}

func readFloat64s() []float64 {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]float64, 0)
	for _, s2 := range strings.Split(s, " ") {
		x, _ := strconv.ParseFloat(s2, 64)
		a = append(a, x)
	}
	return a
}

func readLine() string {
	s, _ := r.ReadString('\n')
	return s[:len(s)-1]
}

func readLines(n int) []string {
	var lines []string
	for i := 0; i < n; i++ {
		lines = append(lines, readLine())
	}
	return lines
}

func main3() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	s := make([]byte, n)
	fmt.Fscanf(r, "%s\n", &s)
	sb := make([]byte, n-1)
	for i := 1; i < n; i++ {
		sb[i-1] = byte(int(s[i]) - int(s[i-1]))
	}
	if n == 2 {
		fmt.Fprintf(w, "%c\n", s[0])
		w.Flush()
		return
	}
	s = sb
	var ans int
	for i := 0; i < n-1; i++ {
		if s[i] == '1' {
			ans ^= 1
		}
	}
	if!contains(s, '1') {
		ans *= 2
	}
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

func contains(s []byte, c byte) bool {
	for _, v := range s {
		if v == c {
			return true
		}
	}
	return false
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func pow(a, b int) int {
	r := 1
	for i := 0; i < b; i++ {
		r *= a
	}
	return r
}

func readInt() int {
	s, _ := r.ReadString('\n')
	x, _ := strconv.Atoi(s)
	return x
}

func readInts() []int {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]int, 0)
	for _, num := range strings.Split(s, " ") {
		x, _ := strconv.Atoi(num)
		a = append(a, x)
	}
	return a
}

func readString() string {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func readStrings() []string {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]string, 0)
	for _, s2 := range strings.Split(s, " ") {
		a = append(a, s2)
	}
	return a
}

func readInt64() int64 {
	s, _ := r.ReadString('\n')
	x, _ := strconv.ParseInt(s, 10, 64)
	return x
}

func readInt64s() []int64 {
	s, _ := r.ReadString('\n')
	s = s[:len(s)-1]
	a := make([]int64, 0)
	for _, num := range strings.Split(s, " ") {
		x, _ := strconv.ParseInt(num, 10, 64)
		a = append(a, x)
	}
	return a
}

func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugf(format string, args...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func minInt(a...int) int {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxInt(a...int) int {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func minInt64(a...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxInt64(a...int64) int64 {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func minStr(a...string) string {
	m := a[0]
	for _, v := range a {
		if v < m {
			m = v
		}
	}
	return m
}

func maxStr(a...string) string {
	m := a[0]
	for _, v := range a {
		if v > m {
			m = v
		}
	}
	return m
}

func readBool() bool {
	s, _ := r.ReadString('\n')
	b, _ := strconv.ParseBool(s)
	return b
}

func readBools() []bool {
	s, _ := r.ReadString('\n')
	a := make([]bool, 0)
	for _, s2 := range strings.Split(s, " ") {
		b, _ := strconv.ParseBool(s2)
		a = append(a, b)
	}
	return a
}

func readFloat64() float64 {
	s, _ := r.ReadString('\n')
	x, _ := strconv.ParseFloat64(s)
	return x
}

func readFloat64s() []float64 {
	s, _ := r.ReadString('\n')
	a := make([]float64, 0)
	for _, s2 := range strings.Split(s, " ") {
		x, _ := strconv.ParseFloat64(s2)
		a = append(a, x)
	}
	return a
}

func readLine() string {
	s, _ := r.ReadString('\n')
	return s
}

func readLines(n int) {
	a := make([]int, 0)
	for i :=