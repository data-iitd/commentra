
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	sc = bufio.NewScanner(os.Stdin)
)

func main() {
	buf := make([]byte, 0)
	sc.Buffer(buf, 101000)
	sc.Split(bufio.ScanWords)

	N := nextInt64()
	min := int64(1e18)
	for i := 0; i < 5; i++ {
		if i == 0 {
			min = nextInt64()
		} else {
			min = int64(math.Min(float64(min), float64(nextInt64())))
		}
	}
	fmt.Println(int64(math.Ceil(float64(N)/float64(min))) + 4)
}

func nextInt() int {
	sc.Scan()
	intVal, _ := strconv.Atoi(sc.Text())
	return intVal
}

func nextInt64() int64 {
	sc.Scan()
	intVal, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return intVal
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func min(x, y int64) int64 {
	return int64(math.Min(float64(x), float64(y)))
}

func max(x, y int64) int64 {
	return int64(math.Max(float64(x), float64(y)))
}

func pow(x, n int64) int64 {
	ret := int64(1)
	for i := 0; i < n; i++ {
		ret *= x
	}
	return ret
}

func abs(x int64) int64 {
	return int64(math.Abs(float64(x)))
}

func mod(x, m int64) int64 {
	return ((x % m) + m) % m
}

func gcd(x, y int64) int64 {
	return int64(math.Gcd(float64(x), float64(y)))
}

func lcm(x, y int64) int64 {
	return x / gcd(x, y) * y
}

func isPrime(n int64) bool {
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

func nextPermutation(nums []int) bool {
	if len(nums) <= 1 {
		return false
	}
	i := len(nums) - 1
	for i > 0 && nums[i-1] >= nums[i] {
		i--
	}
	if i == 0 {
		return false
	}
	j := len(nums) - 1
	for j >= 0 && nums[j] <= nums[i-1] {
		j--
	}
	nums[i-1], nums[j] = nums[j], nums[i-1]
	j = len(nums) - 1
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
	return true
}

func nextPermutation2(nums []int) bool {
	i := len(nums) - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		return false
	}
	j := len(nums) - 1
	for j >= 0 && nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	j = len(nums) - 1
	for i < j {
		nums[i], nums[j] = nums[j], nums[i]
		i++
		j--
	}
	return true
}

func fact(n int64) int64 {
	ret := int64(1)
	for i := int64(1); i <= n; i++ {
		ret *= i
	}
	return ret
}

func nPr(n, r int64) int64 {
	return fact(n) / fact(n-r)
}

func nCr(n, r int64) int64 {
	return fact(n) / fact(n-r) / fact(r)
}

func isPalindrome(s string) bool {
	return s == reverse(s)
}

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < len(runes)/2; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func isqrt(n int64) int64 {
	x := int64(math.Sqrt(float64(n)))
	if x*x == n {
		return x
	} else if x*x < n {
		return x + 1
	} else {
		return x - 1
	}
}

func cdiv(a, b int64) int64 {
	return a / b + int64(a%b!= 0)
}

func sqrt(n int64) int64 {
	return int64(math.Sqrt(float64(n)))
}

func pow2(n int64) int64 {
	return n * n
}

func pow3(n int64) int64 {
	return n * n * n
}

func pow5(n int64) int64 {
	return n * n * n * n
}

func pow6(n int64) int64 {
	return n * n * n * n * n
}

func pow7(n int64) int64 {
	return n * n * n * n * n * n
}

func pow8(n int64) int64 {
	return n * n * n * n * n * n * n
}

func pow9(n int64) int64 {
	return n * n * n * n * n * n * n * n
}

func minInt(a...int) int {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxInt(a...int) int {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minInt64(a...int64) int64 {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxInt64(a...int64) int64 {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minInt64Ptr(a...*int64) int64 {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxInt64Ptr(a...*int64) int64 {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minFloat64(a...float64) float64 {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxFloat64(a...float64) float64 {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minFloat64Ptr(a...*float64) float64 {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxFloat64Ptr(a...*float64) float64 {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minStr(a...string) string {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxStr(a...string) string {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minStrPtr(a...*string) string {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxStrPtr(a...*string) string {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minBool(a...bool) bool {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxBool(a...bool) bool {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minBoolPtr(a...*bool) bool {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxBoolPtr(a...*bool) bool {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minDuration(a...time.Duration) time.Duration {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxDuration(a...time.Duration) time.Duration {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minDurationPtr(a...*time.Duration) time.Duration {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxDurationPtr(a...*time.Duration) time.Duration {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minTime(a...time.Time) time.Time {
	ret := a[0]
	for _, v := range a {
		if v.Before(ret) {
			ret = v
		}
	}
	return ret
}

func maxTime(a...time.Time) time.Time {
	ret := a[0]
	for _, v := range a {
		if v.After(ret) {
			ret = v
		}
	}
	return ret
}

func minTimePtr(a...*time.Time) time.Time {
	ret := *a[0]
	for _, v := range a {
		if v.Before(ret) {
			ret = *v
		}
	}
	return ret
}

func maxTimePtr(a...*time.Time) time.Time {
	ret := *a[0]
	for _, v := range a {
		if v.After(ret) {
			ret = *v
		}
	}
	return ret
}

func minComplex64(a...complex64) complex64 {
	ret := a[0]
	for _, v := range a {
		if real(v) < real(ret) || (real(v) == real(ret) && imag(v) < imag(ret)) {
			ret = v
		}
	}
	return ret
}

func maxComplex64(a...complex64) complex64 {
	ret := a[0]
	for _, v := range a {
		if real(v) > real(ret) || (real(v) == real(ret) && imag(v) > imag(ret)) {
			ret = v
		}
	}
	return ret
}

func minComplex128(a...complex128) complex128 {
	ret := a[0]
	for _, v := range a {
		if real(v) < real(ret) || (real(v) == real(ret) && imag(v) < imag(ret)) {
			ret = v
		}
	}
	return ret
}

func maxComplex128(a...complex128) complex128 {
	ret := a[0]
	for _, v := range a {
		if real(v) > real(ret) || (real(v) == real(ret) && imag(v) > imag(ret)) {
			ret = v
		}
	}
	return ret
}

func minComplex64Ptr(a...*complex64) complex64 {
	ret := *a[0]
	for _, v := range a {
		if real(*v) < real(ret) || (real(*v) == real(ret) && imag(*v) < imag(ret)) {
			ret = *v
		}
	}
	return ret
}

func maxComplex64Ptr(a...*complex64) complex64 {
	ret := *a[0]
	for _, v := range a {
		if real(*v) > real(ret) || (real(*v) == real(ret) && imag(*v) > imag(ret)) {
			ret = *v
		}
	}
	return ret
}

func minComplex128Ptr(a...*complex128) complex128 {
	ret := *a[0]
	for _, v := range a {
		if real(*v) < real(ret) || (real(*v) == real(ret) && imag(*v) < imag(ret)) {
			ret = *v
		}
	}
	return ret
}

func maxComplex128Ptr(a...*complex128) complex128 {
	ret := *a[0]
	for _, v := range a {
		if real(*v) > real(ret) || (real(*v) == real(ret) && imag(*v) > imag(ret)) {
			ret = *v
		}
	}
	return ret
}

func minUint(a...uint) uint {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxUint(a...uint) uint {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minUint8(a...uint8) uint8 {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxUint8(a...uint8) uint8 {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minUint16(a...uint16) uint16 {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxUint16(a...uint16) uint16 {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minUint32(a...uint32) uint32 {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxUint32(a...uint32) uint32 {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minUint64(a...uint64) uint64 {
	ret := a[0]
	for _, v := range a {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func maxUint64(a...uint64) uint64 {
	ret := a[0]
	for _, v := range a {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func minUintPtr(a...*uint) uint {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxUintPtr(a...*uint) uint {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minUint8Ptr(a...*uint8) uint8 {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxUint8Ptr(a...*uint8) uint8 {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minUint16Ptr(a...*uint16) uint16 {
	ret := *a[0]
	for _, v := range a {
		if *v < ret {
			ret = *v
		}
	}
	return ret
}

func maxUint16Ptr(a...*uint16) uint16 {
	ret := *a[0]
	for _, v := range a {
		if *v > ret {
			ret = *v
		}
	}
	return ret
}

func minUint32(