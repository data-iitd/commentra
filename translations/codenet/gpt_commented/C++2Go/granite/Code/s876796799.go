
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n := readNum(reader)
	A := readNNums(reader, n)
	res := solve(n, A)

	fmt.Println(res)
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
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
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func solve(n int, A []int) int64 {
	pos := make([]int, n)

	for i := 0; i < n; i++ {
		pos[A[i]-1] = i
	}

	var left, right int

	var res int64

	set := make(map[int]bool)

	for i := 0; i < n; i++ {
		p := pos[i]

		it := right
		for it < n && A[it]-1 < p {
			it++
		}
		right = it

		it = left
		for it >= 0 && A[it]-1 > p {
			it--
		}
		left = it

		cnt := int64(p - left) * int64(right-p)

		res += cnt * int64(i+1)

		set[p] = true
	}

	return res
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func minInt64(a, b int64) int64 {
	if a <= b {
		return a
	}
	return b
}

func maxInt64(a, b int64) int64 {
	if a >= b {
		return a
	}
	return b
}

func abs(num int64) int64 {
	if num < 0 {
		return -num
	}
	return num
}

func unique(arr []int) []int {
	var res []int
	sort.Ints(arr)
	for i := 0; i < len(arr); i++ {
		if i == 0 || arr[i]!= arr[i-1] {
			res = append(res, arr[i])
		}
	}
	return res
}

func sum(arr []int) int {
	sum := 0
	for _, num := range arr {
		sum += num
	}
	return sum
}

func minSlice(arr []int) int {
	min := 1 << 30
	for _, num := range arr {
		min = minInt(min, num)
	}
	return min
}

func maxSlice(arr []int) int {
	max := -1 << 30
	for _, num := range arr {
		max = maxInt(max, num)
	}
	return max
}

func minInt(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func maxInt(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func pow(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a
	}
	return res
}

func powMod(a, b, mod int) int {
	res := 1
	for i := 0; i < b; i++ {
		res = (res * a) % mod
	}
	return res
}

func toArray(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = i + 1
	}
	return res
}

func reverse(arr []int) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func reverseRange(arr []int, start, end int) {
	for i, j := start, end-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func reverseString(str string) string {
	runes := []rune(str)
	reverse(runes)
	return string(runes)
}

func reverseRunes(runes []rune) {
	reverse(runes)
}

func isPalindrome(str string) bool {
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		if runes[i]!= runes[j] {
			return false
		}
	}
	return true
}

func isPermutation(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	count := make(map[byte]int)
	for _, c := range s1 {
		count[c]++
	}
	for _, c := range s2 {
		if count[c] == 0 {
			return false
		}
		count[c]--
	}
	return true
}

func isAnagram(s1, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	count := make(map[byte]int)
	for _, c := range s1 {
		count[c]++
	}
	for _, c := range s2 {
		if count[c] == 0 {
			return false
		}
		count[c]--
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

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
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
	if n <= 2 {
		return 2
	}
	for n = n + 1;!isPrime(n); n++ {
	}
	return n
}

func prevPrime(n int) int {
	if n <= 2 {
		return 2
	}
	for n = n - 1;!isPrime(n); n-- {
	}
	return n
}

func factorial(n int) int {
	res := 1
	for i := 2; i <= n; i++ {
		res *= i
	}
	return res
}

func factorialMod(n, mod int) int {
	res := 1
	for i := 2; i <= n; i++ {
		res = (res * i) % mod
	}
	return res
}

func binomial(n, k int) int {
	return factorial(n) / (factorial(k) * factorial(n-k))
}

func binomialMod(n, k, mod int) int {
	return factorialMod(n, mod) / (factorialMod(k, mod) * factorialMod(n-k, mod))
}

func isPerfectSquare(n int) bool {
	x := int(math.Sqrt(float64(n)))
	return x*x == n
}

func isPalindromic(num int) bool {
	s := fmt.Sprintf("%d", num)
	return isPalindrome(s)
}

func isPalindromicString(s string) bool {
	return isPalindrome(s)
}

func isPalindromicRunes(runes []rune) bool {
	return isPalindrome(string(runes))
}

func isPalindromicSlice(arr []int) bool {
	return isPalindrome(fmt.Sprintf("%v", arr))
}

func isPalindromicMatrix(matrix [][]int) bool {
	s := fmt.Sprintf("%v", matrix)
	return isPalindrome(s)
}

func isPalindromicMatrix2(matrix [][]int) bool {
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < i; j++ {
			if matrix[i][j]!= matrix[j][i] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix3(matrix [][]int) bool {
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix4(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0]); j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix5(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix6(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix7(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix8(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix9(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix10(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix11(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix12(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][len(matrix[0])-1-j] ||
				matrix[i][j]!= matrix[len(matrix)-1-i][j] ||
				matrix[i][j]!= matrix[i][len(matrix[0])-1-j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix13(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix14(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix15(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][j] {
				return false
			}
		}
	}
	return true
}

func isPalindromicMatrix16(matrix [][]int) bool {
	for i := 0; i < len(matrix)/2; i++ {
		for j := 0; j < len(matrix[0])/2; j++ {
			if matrix[i][j]!= matrix[len(matrix)-1-i][j] {
				return fals