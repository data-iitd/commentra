
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	ans int64
)

func get(a int64) int64 {
	ret := int64(0)
	now := int64(1)
	t := int64(1)
	for {
		if now*10 > a {
			ret += (a - now + 1) * t
			break
		}
		ret += now * 9 * t
		now *= 10
		t++
	}
	return ret
}

func binarySearch(k, l, r, x int64) int64 {
	if r >= l {
		mid := l + (r-l)/2
		if mid > ans && mid*k <= x {
			ans = mid
		}

		if k*mid == x {
			return mid
		}

		if k*mid > x {
			return binarySearch(k, l, mid-1, x)
		}

		return binarySearch(k, mid+1, r, x)
	}

	return -1
}

func main() {
	gen, st, tim := readInt64(), readInt64(), readInt64()
	gen /= tim
	beg, end := st-1, int64(1e18)
	for {
		med := (beg + end) / 2 + 1
		if get(med)-get(st-1) > gen {
			end = med - 1
		} else {
			beg = med
		}
		if beg == end {
			fmt.Println(beg - st + 1)
			break
		}
	}
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int64
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var str string
	sc.Scan()
	str = sc.Text()
	return str
}

func readStrings(n int) []string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var strs []string
	for i := 0; i < n; i++ {
		sc.Scan()
		strs = append(strs, sc.Text())
	}
	return strs
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func pow(n, p int) int {
	ret := 1
	for i := 0; i < p; i++ {
		ret *= n
	}
	return ret
}

func abs(x int) int {
	return int(math.Abs(float64(x)))
}

func allCombinations(str string) [][]string {
	var res [][]string
	if len(str) == 0 {
		res = append(res, []string{})
		return res
	}

	sub := allCombinations(str[1:])
	for i := range sub {
		res = append(res, sub[i])
	}

	char := string(str[0])
	for i := range sub {
		res = append(res, append([]string{char}, sub[i]...))
	}

	return res
}

func isPalindrome(str string) bool {
	n := len(str)
	for i := 0; i < n/2; i++ {
		if str[i]!= str[n-i-1] {
			return false
		}
	}
	return true
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
	num := n
	for {
		num++
		if isPrime(num) {
			return num
		}
	}
}

func prevPrime(n int) int {
	num := n
	for {
		num--
		if isPrime(num) {
			return num
		}
	}
}

func numDigits(n int) int {
	return len(strconv.Itoa(n))
}

func isPerfectSquare(n int) bool {
	x := int(math.Sqrt(float64(n)))
	return x*x == n
}

func factors(n int) []int {
	var res []int
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			res = append(res, i)
			if i!= n/i {
				res = append(res, n/i)
			}
		}
	}
	return res
}

func sumFactors(n int) int {
	var res int
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			res += i
			if i!= n/i {
				res += n/i
			}
		}
	}
	return res
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

func combinations(n, r int) int {
	return factorial(n) / (factorial(r) * factorial(n-r))
}

func permutations(n, r int) int {
	return factorial(n) / factorial(n-r)
}

func factorial(n int) int {
	res := 1
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

func toBase26(num int) string {
	var res string
	for num > 0 {
		rem := num % 26
		if rem == 0 {
			res = "Z" + res
			num -= 26
		} else {
			res = string('A'+rem-1) + res
		}
		num /= 26
	}
	return res
}

func toDecimal(s string) int {
	var res int
	for i := 0; i < len(s); i++ {
		res = res*26 + int(s[i]-'A'+1)
	}
	return res
}

func main() {
	gen, st, tim := readInt64(), readInt64(), readInt64()
	gen /= tim
	beg, end := st-1, int64(1e18)
	for {
		med := (beg + end) / 2 + 1
		if get(med)-get(st-1) > gen {
			end = med - 1
		} else {
			beg = med
		}
		if beg == end {
			fmt.Println(beg - st + 1)
			break
		}
	}
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int64
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var str string
	sc.Scan()
	str = sc.Text()
	return str
}

func readStrings(n int) []string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var strs []string
	for i := 0; i < n; i++ {
		sc.Scan()
		strs = append(strs, sc.Text())
	}
	return strs
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func pow(n, p int) int {
	res := 1
	for i := 0; i < p; i++ {
		res *= n
	}
	return res
}

func abs(x int) int {
	return int(math.Abs(float64(x)))
}

func allCombinations(str string) [][]string {
	var res [][]string
	if len(str) == 0 {
		res = append(res, []string{})
		return res
	}

	sub := allCombinations(str[1:])
	for i := range sub {
		res = append(res, sub[i])
	}

	char := string(str[0])
	for i := range sub {
		res = append(res, append([]string{char}, sub[i]...))
	}

	return res
}

func isPalindrome(str string) bool {
	n := len(str)
	for i := 0; i < n/2; i++ {
		if str[i]!= str[n-i-1] {
			return false
		}
	}
	return true
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
	num := n
	for {
		num++
		if isPrime(num) {
			return num
		}
	}
}

func prevPrime(n int) int {
	num := n
	for {
		num--
		if isPrime(num) {
			return num
		}
	}
}

func numDigits(n int) int {
	return len(strconv.Itoa(n))
}

func isPerfectSquare(n int) bool {
	x := int(math.Sqrt(float64(n)))
	return x*x == n
}

func factors(n int) []int {
	var res []int
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			res = append(res, i)
			if i!= n/i {
				res = append(res, n/i)
			}
		}
	}
	return res
}

func sumFactors(n int) int {
	var res int
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			res += i
			if i!= n/i {
				res += n/i
			}
		}
	}
	return res
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

func combinations(n, r int) int {
	return factorial(n) / (factorial(r) * factorial(n-r))
}

func permutations(n, r int) int {
	return factorial(n) / factorial(n-r)
}

func factorial(n int) int {
	res := 1
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

func toBase26(num int) string {
	var res string
	for num > 0 {
		rem := num % 26
		if rem == 0 {
			res = "Z" + res
			num -= 26
		} else {
			res = string('A'+rem-1) + res
		}
		num /= 26
	}
	return res
}

func toDecimal(s string) int {
	var res int
	for i := 0; i < len(s); i++ {
		res = res*26 + int(s[i]-'A'+1)
	}
	return res
}