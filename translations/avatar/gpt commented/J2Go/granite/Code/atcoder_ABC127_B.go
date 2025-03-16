
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
	r, d, x := readInt64(), readInt64(), readInt64()
	for i := 0; i < 10; i++ {
		x = r*x - d
		fmt.Fprintln(out, x)
	}
	out.Flush()
}

func readString() string {
	s, _ := in.ReadString('\n')
	return strings.TrimSpace(s)
}

func readInt() int {
	i, _ := strconv.Atoi(readString())
	return i
}

func readInt64() int64 {
	i, _ := strconv.ParseInt(readString(), 10, 64)
	return i
}

func readInt64s(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64()
	}
	return a
}

func readInt64s2(n int) [][]int64 {
	a := make([][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64s(2)
	}
	return a
}

func readInt64s3(n int) [][][]int64 {
	a := make([][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64s2(3)
	}
	return a
}

func readInt64s4(n int) [][][][]int64 {
	a := make([][][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64s3(4)
	}
	return a
}

func readFloat64() float64 {
	f, _ := strconv.ParseFloat(readString(), 64)
	return f
}

func readFloat64s(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readFloat64()
	}
	return a
}

func readBool() bool {
	s := readString()
	if s == "true" {
		return true
	} else {
		return false
	}
}

func readBools(n int) []bool {
	a := make([]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readBool()
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

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, mod(a, b)
	}
	return a
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
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

func nextPrime(n int) int {
	if n <= 1 {
		return 2
	}
	n++
	for!isPrime(n) {
		n++
	}
	return n
}

func isPerfectSquare(n int) bool {
	return int(math.Sqrt(float64(n)))*int(math.Sqrt(float64(n))) == n
}

func factors(n int) []int {
	a := make([]int, 0)
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			a = append(a, i)
			if i*i!= n {
				a = append(a, n/i)
			}
		}
	}
	return a
}

func divisors(n int) []int {
	a := make([]int, 0)
	for i := 1; i <= n; i++ {
		if n%i == 0 {
			a = append(a, i)
		}
	}
	return a
}

func digitSum(n int) int {
	a := 0
	for n > 0 {
		a += n % 10
		n /= 10
	}
	return a
}

func digitSumString(s string) int {
	a := 0
	for _, c := range s {
		a += int(c - '0')
	}
	return a
}

func isPalindrome(s string) bool {
	return s == reverseString(s)
}

func reverseString(s string) string {
	a := make([]byte, len(s))
	for i, c := range s {
		a[len(s)-1-i] = byte(c)
	}
	return string(a)
}

func isAnagram(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	a := make([]int, 26)
	for _, c := range s1 {
		a[c-'a']++
	}
	for _, c := range s2 {
		a[c-'a']--
	}
	for _, v := range a {
		if v!= 0 {
			return false
		}
	}
	return true
}

func isPermutation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	a := make([]int, 26)
	for _, c := range s1 {
		a[c-'a']++
	}
	for _, c := range s2 {
		a[c-'a']--
	}
	for _, v := range a {
		if v!= 0 {
			return false
		}
	}
	return true
}

func isSubsequence(s1, s2 string) bool {
	i, j := 0, 0
	for i < len(s1) && j < len(s2) {
		if s1[i] == s2[j] {
			i++
		}
		j++
	}
	return i == len(s1)
}

func isRotation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func isAnagram2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	a := make([]int, 26)
	for _, c := range s1 {
		a[c-'a']++
	}
	for _, c := range s2 {
		a[c-'a']--
	}
	for _, v := range a {
		if v!= 0 {
			return false
		}
	}
	return true
}

func isPermutation2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	a := make([]int, 26)
	for _, c := range s1 {
		a[c-'a']++
	}
	for _, c := range s2 {
		a[c-'a']--
	}
	for _, v := range a {
		if v!= 0 {
			return false
		}
	}
	return true
}

func isSubsequence2(s1, s2 string) bool {
	i, j := 0, 0
	for i < len(s1) && j < len(s2) {
		if s1[i] == s2[j] {
			i++
		}
		j++
	}
	return i == len(s1)
}

func isRotation2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func main() {
	r, d, x := readInt64(), readInt64(), readInt64()
	for i := 0; i < 10; i++ {
		x = r*x - d
		fmt.Println(x)
	}
}

func readString() string {
	s, _ := in.ReadString('\n')
	return strings.TrimSpace(s)
}

func readInt() int {
	i, _ := strconv.Atoi(readString())
	return i
}

func readInt64() int64 {
	i, _ := strconv.ParseInt(readString(), 10, 64)
	return i
}

func readInt64s(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64()
	}
	return a
}

func readInt64s2(n int) [][]int64 {
	a := make([][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64s(2)
	}
	return a
}

func readInt64s3(n int) [][][]int64 {
	a := make([][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64s2(3)
	}
	return a
}

func readInt64s4(n int) [][][][]int64 {
	a := make([][][][]int64, n)
	for i := 0; i < n; i++ {
		a[i] = readInt64s3(4)
	}
	return a
}

func readFloat64() float64 {
	f, _ := strconv.ParseFloat(readString(), 64)
	return f
}

func readFloat64s(n int) []float64 {
	a := make([]float64, n)
	for i := 0; i < n; i++ {
		a[i] = readFloat64()
	}
	return a
}

func readBool() bool {
	s := readString()
	if s == "true" {
		return true
	} else {
		return false
	}
}

func readBools(n int) []bool {
	a := make([]bool, n)
	for i := 0; i < n; i++ {
		a[i] = readBool()
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

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, mod(a, b)
	}
	return a
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
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

func nextPrime(n int) int {
	if n <= 1 {
		return 2
	}
	n++
	for!isPrime(n) {
		n++
	}
	return n
}

func isPerfectSquare(n int) bool {
	return int(math.Sqrt(float64(n)))*int(math.Sqrt(float64(n))) == n
}

func factors(n int) []int {
	a := make([]int, 0)
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			a = append(a, i)
			if i*i!= n {
				a = append(a, n/i)
			}
		}
	}
	return a
}

func divisors(n int) []int {
	a := make([]int, 0)
	for i := 1; i <= n; i++ {
		if n%i == 0 {
			a = append(a, i)
		}
	}
	return a
}

func digitSum(n int) int {
	a := 0
	for n > 0 {
		a += n % 10
		n /= 10
	}
	return a
}

func digitSumString(s string) int {
	a := 0
	for _, c := range s {
		a += int(c - '0')
	}
	return a
}

func isPalindrome(s string) bool {
	return s == reverseString(s)
}

func reverseString(s string) string {
	a := make([]byte, len(s))
	for i, c := range s {
		a[len(s)-1-i] = byte(c)
	}
	return string(a)
}

func isAnagram(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	a := make([]int, 26)
	for _, c := range s1 {
		a[c-'a']++
	}
	for _, c := range s2 {
		a[c-'a']--
	}
	for _, v := range a {
		if v!= 0 {
			return false
		}
	}
	return true
}

func isPermutation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	a := make([]int, 26)
	for _, c := range s1 {
		a[c-'a']++
	}
	for _, c := range s2 {
		a[c-'a']--
	}
	for _, v := range a {
		if v!= 0 {
			return false
		}
	}
	return true
}

func isSubsequence(s1, s2 string) bool {
	i, j := 0, 0
	for i < len(s1) && j < len(s2) {
		if s1[i] == s2[j] {
			i++
		}
		j++
	}
	return i == len(s1)
}

func isRotation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func isAnagram2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	a := make([]int, 26)
	for _, c := range s1 {
		a[c-'a']++
	}
	for _, c := range s2 {
		a[c-'a']--
	}
	for _, v := range a {
		if v!= 0 {
			return false
		}
		return true
	}
}

func isPermutation2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func isSubsequence2(s1, s2 string) bool {
	i, j := 0, 0
	for i < len(s1) && j < len(s2) {
		if s1[i] == s2[j] {
			i++
		}
		j++
	}
	return i == len(s1)
}

func isRotation2(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	return s1+s1 == s2
}

func main() {
	r, d, x := readInt64(), readInt64(), readInt64()
	for i := 0; i < 10; i++
	}
}