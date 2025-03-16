
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var an [20]int
	var L int
	for scanner.Scan() {
		an[0], L = nextInt(scanner.Text()), nextInt(scanner.Text())
		if L == 0 {
			break
		}
		aj, end := an[0], 0
		for k := 1; k < 21; k++ {
			a1, a2 := make([]int, L), make([]int, L)
			aj1, aj2 := aj, aj
			for i := L - 1; i >= 0; i-- {
				a1[i], aj1 = aj1%10, aj1/10
				a2[i], aj2 = aj2%10, aj2/10
			}
			for i := 1; i < L; i++ {
				for j := 1; j < L; j++ {
					if a1[j-1] < a1[j] {
						a1[j-1], a1[j] = a1[j], a1[j-1]
					}
					if a2[j-1] > a2[j] {
						a2[j-1], a2[j] = a2[j], a2[j-1]
					}
				}
			}
			d, max, min := 1, 0, 0
			for i := L - 1; i >= 0; i-- {
				max += a1[i] * d
				min += a2[i] * d
				d *= 10
			}
			def := max - min
			for i := 0; i < k; i++ {
				if def == an[i] {
					fmt.Printf("%d %d %d\n", i, def, k-i)
					end = 1
					break
				}
			}
			if end == 1 {
				break
			}
			an[k] = def
			aj = def
		}
	}
}

func nextInt(sc string) int {
	i, _ := strconv.Atoi(sc)
	return i
}

func nextString(sc string) string {
	return sc
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

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	tmp := pow(x, n/2)
	if n%2 == 0 {
		return tmp * tmp
	} else {
		return tmp * tmp * x
	}
}

func abs(x int) int {
	return max(x, -x)
}

func allDiff(str string) bool {
	for i := 0; i < len(str); i++ {
		for j := i + 1; j < len(str); j++ {
			if str[i] == str[j] {
				return false
			}
		}
	}
	return true
}

func divisors(n int) []int {
	res := make([]int, 0)
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			res = append(res, i)
			if i!= n/i {
				res = append(res, n/i)
			}
		}
	}
	sort.Ints(res)
	return res
}

func p(format string, a...interface{}) {
	fmt.Fprintf(os.Stdout, format, a...)
}

func e(v...interface{}) {
	fmt.Fprintln(os.Stderr, v...)
}

func readString() string {
	sc := bufio.NewScanner(os.Stdin)
	if sc.Scan() {
		return sc.Text()
	}
	return ""
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	if sc.Scan() {
		i, _ := strconv.Atoi(sc.Text())
		return i
	}
	panic("ReadInt")
}

func readFloat() float64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	if sc.Scan() {
		f, _ := strconv.ParseFloat(sc.Text(), 32)
		return f
	}
	panic("ReadFloat")
}

func readStringSlice(n int) []string {
	s := make([]string, n)
	for i := 0; i < n; i++ {
		s[i] = readString()
	}
	return s
}

func readIntSlice(n int) []int {
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[i] = readInt()
	}
	return s
}

func readInt64Slice(n int) []int64 {
	s := make([]int64, n)
	for i := 0; i < n; i++ {
		s[i] = readInt64()
	}
	return s
}

func readFloatSlice(n int) []float64 {
	s := make([]float64, n)
	for i := 0; i < n; i++ {
		s[i] = readFloat()
	}
	return s
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	if sc.Scan() {
		i, _ := strconv.ParseInt(sc.Text(), 10, 64)
		return i
	}
	panic("ReadInt64")
}

func debugPrintf(format string, a...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...)
}

func combination(n, r int) int {
	if n < r {
		return 0
	}
	r = min(r, n-r)
	res := 1
	for i := 0; i < r; i++ {
		res *= n - i
		res /= i + 1
	}
	return res
}

func permutations(n int) int {
	if n == 0 {
		return 0
	}
	return fact(n)
}

func fact(n int) int {
	res := 1
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

func gcd(x, y int) int {
	for y!= 0 {
		x, y = y, x%y
	}
	return x
}

func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

func popCount(n int) int {
	res := 0
	for n > 0 {
		res += n & 1
		n >>= 1
	}
	return res
}

func powInt(n, p int) int {
	res := 1
	for p > 0 {
		if p%2 == 1 {
			res *= n
		}
		n *= n
		p /= 2
	}
	return res
}

func powMod(n, p, mod int) int {
	res := 1
	for p > 0 {
		if p%2 == 1 {
			res = (res * n) % mod
		}
		n = (n * n) % mod
		p /= 2
	}
	return res
}

func powMod64(n, p, mod int64) int64 {
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res = (res * n) % mod
		}
		n = (n * n) % mod
		p /= 2
	}
	return res
}

func modInv(n, mod int) int {
	return powMod(n, mod-2, mod)
}

func modInv64(n, mod int64) int64 {
	return powMod64(n, mod-2, mod)
}

func modInv32(n int32, mod int32) int32 {
	return powMod(int(n), int(mod-2), int(mod))
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

func factorialMod32(n int32, mod int32) int32 {
	res := int32(1)
	for i := int32(2); i <= n; i++ {
		res = (res * i) % mod
	}
	return res
}

func modPow(x, n, mod int) int {
	y := 1
	for n > 0 {
		if n%2 == 1 {
			y = (y * x) % mod
		}
		x = (x * x) % mod
		n /= 2
	}
	return y
}

func modPow32(x int32, n int32, mod int32) int32 {
	y := int32(1)
	for n > 0 {
		if n%2 == 1 {
			y = (y * x) % mod
		}
		x = (x * x) % mod
		n /= 2
	}
	return y
}

func modPow64(x int64, n int64, mod int64) int64 {
	y := int64(1)
	for n > 0 {
		if n%2 == 1 {
			y = (y * x) % mod
		}
		x = (x * x) % mod
		n /= 2
	}
	return y
}

func modPowInt64(x int64, n int64) int64 {
	y := int64(1)
	for n > 0 {
		if n%2 == 1 {
			y *= x
		}
		x *= x
		n /= 2
	}
	return y
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

func extGCD(a, b int) (x, y int) {
	if b == 0 {
		return 1, 0
	}
	x1, y1 := extGCD(b, a%b)
	return y1, x1 - (a/b)*y1
}

func modInvByExtGCD(a, mod int) int {
	x, _ := extGCD(a, mod)
	return positiveMod(x, mod)
}

func modInvByFermat(a, mod int) int {
	return powMod(a, mod-2, mod)
}

func modC(n, k, mod int) int {
	return modMul(modFactorial(n, mod), modInvByFermat(modMul(modFactorial(k, mod), modFactorial(n-k, mod), mod), mod))
}

func modFactorial(n, mod int) int {
	res := 1
	for i := 1; i <= n; i++ {
		res = modMul(res, i, mod)
	}
	return res
}

func modMul(a, b, mod int) int {
	res := int64(a) * int64(b)
	return int(res % int64(mod))
}

func modAdd(a, b, mod int) int {
	res := int64(a) + int64(b)
	return int(res % int64(mod))
}

func modSub(a, b, mod int) int {
	res := int64(a) - int64(b)
	return int(res % int64(mod))
}

func positiveMod(a, mod int) int {
	res := a % mod
	if res < 0 {
		res += mod
	}
	return res
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min4(a, b, c, d int) int {
	return min(min3(a, b, c), d)
}

func max4(a, b, c, d int) int {
	return max(max3(a, b, c), d)
}

func formatInt(num int) string {
	return strconv.Itoa(num)
}

func formatInt64(num int64) string {
	return strconv.FormatInt(num, 10)
}

func formatInt32(num int32) string {
	return strconv.FormatInt(int64(num), 10)
}

func formatFloat(num float64, digit int) string {
	return strings.TrimRight(fmt.Sprintf("%."+strconv.Itoa(digit)+"f", num), "0")
}

func formatUInt64(num uint64) string {
	return strconv.FormatUint(num, 10)
}

func formatUInt32(num uint32) string {
	return strconv.FormatUint(uint64(num), 10)
}

func formatChar(c byte) string {
	return string(c)
}

func formatString(str string) string {
	return str
}

func formatBool(b bool) string {
	return strconv.FormatBool(b)
}

func formatSliceInt(s []int) string {
	res := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		res[i] = strconv.Itoa(s[i])
	}
	return strings.Join(res, " ")
}

func formatSliceString(s []string) string {
	return strings.Join(s, " ")
}

func formatSliceInt64(s []int64) string {
	res := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		res[i] = strconv.FormatInt(s[i], 10)
	}
	return strings.Join(res, " ")
}

func formatSliceInt32(s []int32) string {
	res := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		res[i] = strconv.FormatInt(int64(s[i]), 10)
	}
	return strings.Join(res, " ")
}

func formatSliceBool(s []bool) string {
	res := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		res[i] = strconv.FormatBool(s[i])
	}
	return strings.Join(res, " ")
}

func formatSliceChar(s []byte) string {
	res := make([]string, len(s))
	for i := 0; i < len(s); i++ {
		res[i] = string(s[i])
	}
	return strings.Join(res, " ")
}

func formatSliceAny(s interface{}) string {
	if reflect.TypeOf(s).Kind() == reflect.Slice {
		v := reflect.ValueOf(s)
		res := make([]string, v.Len())
		for i := 0; i < v.Len(); i++ {
			res[i] = fmt.Sprintf("%v", v.Index(i).Interface())
		}
		return strings.Join(res, " ")
	}
	return fmt.Sprintf("%v", s)
}

func formatMap(m interface{}) string {
	v := reflect.ValueOf(m)
	res := make([]string, v.Len())
	for i, key := range v.MapKeys() {
		res[i] = fmt.Sprintf("%v: %v", key.Interface(), v.MapIndex(key).Interface())
	}
	return strings.Join(res, " ")
}

func formatMapOfSliceInt(m map[string][]int) string {
	res := make([]string, len(m))
	i := 0
	for k, v := range m {
		res[i] = fmt.Sprintf("%v: %v", k, v)
		i++
	}
	return strings.Join(res, " ")
}

func formatMapOfSliceInt64(m map[string][]int64) string {
	res := make([]string, len(m))
	i := 0
	for k, v := range m {
		res[i] = fmt.Sprintf("%v: %v", k, v)
		i++
	}
	return strings.Join(res, " ")
}

func formatMapOfSliceInt32(m map[string][]int32) string {
	res := make([]string, len(m))
	i := 0
	for k, v := range m {
		res[i] = fmt.Sprintf("%v: %v", k, v)
		i++
	}
	return strings.Join(res, " ")
}

func formatMapOfSliceString(m map[string]string) string {
	res := make([]string, len(m))
	i := 0
	for k, v := range m {
		res[i] = fmt.Sprintf("%v: %v", k, v)
		i++
	}
	return strings.Join(res, " ")
}

func formatMapOfSliceBool(m map[string]bool) string {
	res := make([]string, len(m))
	i := 0
	for k, v := range m {
		res[i] = fmt.Sprintf("%v: %v"