package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

/*********** I/O ***********/

var (
	// ReadString returns a WORD string.
	ReadString func() string
	stdout     *bufio.Writer
)

// init initializes the ReadString function and the stdout writer.
func init() {
	ReadString = newReadString(os.Stdin)
	stdout = bufio.NewWriter(os.Stdout)
}

// newReadString creates a new function to read strings from the provided io.Reader.
func newReadString(ior io.Reader) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+11))
	// Split sets the split function for the Scanner. The default split function is ScanLines.
	// Split panics if it is called after scanning has started.
	r.Split(bufio.ScanWords)

	return func() string {
		if !r.Scan() {
			panic("Scan failed")
		}
		return r.Text()
	}
}

// ReadInt returns an integer by reading from the input.
func ReadInt() int {
	return int(readInt64())
}

// readInt64 reads an integer from the input and returns it as int64.
func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}

// ReadIntSlice returns a slice of integers of length n.
func ReadIntSlice(n int) []int {
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = ReadInt()
	}
	return b
}

// ReadRuneSlice returns a slice of runes from the input string.
func ReadRuneSlice() []rune {
	return []rune(ReadString())
}

/*********** DP sub-functions ***********/

// ChMin updates the value pointed by updatedValue if the target is smaller.
func ChMin(updatedValue *int, target int) bool {
	if *updatedValue > target {
		*updatedValue = target
		return true
	}
	return false
}

// ChMax updates the value pointed by updatedValue if the target is larger.
func ChMax(updatedValue *int, target int) bool {
	if *updatedValue < target {
		*updatedValue = target
		return true
	}
	return false
}

// GetNthBit returns the nth bit value of a number.
func GetNthBit(num, nth int) int {
	return num >> uint(nth) & 1
}

/*********** Arithmetic ***********/

// Max returns the maximum integer from a set of integers.
func Max(integers ...int) int {
	m := integers[0]
	for i, integer := range integers {
		if i == 0 {
			continue
		}
		if m < integer {
			m = integer
		}
	}
	return m
}

// Min returns the minimum integer from a set of integers.
func Min(integers ...int) int {
	m := integers[0]
	for i, integer := range integers {
		if i == 0 {
			continue
		}
		if m > integer {
			m = integer
		}
	}
	return m
}

// CeilInt returns the smallest integer greater than or equal to a/b.
func CeilInt(a, b int) int {
	res := a / b
	if a%b > 0 {
		res++
	}
	return res
}

// FloorInt returns the largest integer less than or equal to a/b.
func FloorInt(a, b int) int {
	res := a / b
	return res
}

// PowInt calculates a raised to the power of e using binary exponentiation.
func PowInt(a, e int) int {
	if a < 0 || e < 0 {
		panic(errors.New("[argument error]: PowInt does not accept negative integers"))
	}

	if e == 0 {
		return 1
	}

	if e%2 == 0 {
		halfE := e / 2
		half := PowInt(a, halfE)
		return half * half
	}

	return a * PowInt(a, e-1)
}

// AbsInt returns the absolute value of an integer.
func AbsInt(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// Gcd returns the Greatest Common Divisor of two natural numbers using the Euclidean Algorithm.
func Gcd(a, b int) int {
	if a <= 0 || b <= 0 {
		panic(errors.New("[argument error]: Gcd only accepts two NATURAL numbers"))
	}
	if a < b {
		a, b = b, a
	}

	// Euclidean Algorithm
	for b > 0 {
		div := a % b
		a, b = b, div
	}

	return a
}

// Lcm returns the Least Common Multiple of two natural numbers.
func Lcm(a, b int) int {
	if a <= 0 || b <= 0 {
		panic(errors.New("[argument error]: Gcd only accepts two NATURAL numbers"))
	}

	// Calculate LCM using GCD
	gcd := Gcd(a, b)
	return (a / gcd) * b
}

/*********** Utilities ***********/

// DeleteElement removes an element at index i from a slice and returns a new slice.
func DeleteElement(s []int, i int) []int {
	if i < 0 || len(s) <= i {
		panic(errors.New("[index error]"))
	}
	// Create a new slice excluding the element at index i
	n := make([]int, 0, len(s)-1)
	n = append(n, s[:i]...)
	n = append(n, s[i+1:]...)
	return n
}

// Concat concatenates two rune slices and returns a new slice.
func Concat(s, t []rune) []rune {
	n := make([]rune, 0, len(s)+len(t))
	n = append(n, s...)
	n = append(n, t...)
	return n
}

// UpperRune converts a rune to uppercase.
func UpperRune(r rune) rune {
	str := strings.ToUpper(string(r))
	return []rune(str)[0]
}

// LowerRune converts a rune to lowercase.
func LowerRune(r rune) rune {
	str := strings.ToLower(string(r))
	return []rune(str)[0]
}

// ToggleRune toggles the case of a rune.
func ToggleRune(r rune) rune {
	var str string
	if 'a' <= r && r <= 'z' {
		str = strings.ToUpper(string(r))
	} else if 'A' <= r && r <= 'Z' {
		str = strings.ToLower(string(r))
	} else {
		str = string(r)
	}
	return []rune(str)[0]
}

// ToggleString toggles the case of each character in a string.
func ToggleString(s string) string {
	inputRunes := []rune(s)
	outputRunes := make([]rune, 0, len(inputRunes))
	for _, r := range inputRunes {
		outputRunes = append(outputRunes, ToggleRune(r))
	}
	return string(outputRunes)
}

// Strtoi converts a string to an integer, panicking on error.
func Strtoi(s string) int {
	if i, err := strconv.Atoi(s); err != nil {
		panic(errors.New("[argument error]: Strtoi only accepts integer string"))
	} else {
		return i
	}
}

/*********** Permutation ***********/

// CalcFactorialPatterns generates all permutations of a slice of runes.
func CalcFactorialPatterns(elements []rune) [][]rune {
	copiedResidual := make([]rune, len(elements))
	copy(copiedResidual, elements)
	return factorialRecursion([]rune{}, copiedResidual)
}

// factorialRecursion is a helper function for generating permutations recursively.
func factorialRecursion(interim, residual []rune) [][]rune {
	if len(residual) == 0 {
		return [][]rune{interim}
	}

	res := [][]rune{}
	for idx, elem := range residual {
		copiedInterim := make([]rune, len(interim))
		copy(copiedInterim, interim)
		copiedInterim = append(copiedInterim, elem)
		copiedResidual := genDeletedSlice(idx, residual)
		res = append(res, factorialRecursion(copiedInterim, copiedResidual)...)
	}

	return res
}

// genDeletedSlice creates a new slice by removing the element at delId from S.
func genDeletedSlice(delId int, S []rune) []rune {
	res := []rune{}
	res = append(res, S[:delId]...)
	res = append(res, S[delId+1:]...)
	return res
}

// CalcDuplicatePatterns generates all combinations of elements with repetition.
func CalcDuplicatePatterns(elements []rune, digit int) [][]rune {
	return duplicateRecursion([]rune{}, elements, digit)
}

// duplicateRecursion is a helper function for generating combinations recursively.
func duplicateRecursion(interim, elements []rune, digit int) [][]rune {
	if len(interim) == digit {
		return [][]rune{interim}
	}

	res := [][]rune{}
	for i := 0; i < len(elements); i++ {
		copiedInterim := make([]rune, len(interim))
		copy(copiedInterim, interim)
		copiedInterim = append(copiedInterim, elements[i])
		res = append(res, duplicateRecursion(copiedInterim, elements, digit)...)
	}

	return res
}

/*********** Binary Search ***********/

// GeneralLowerBound finds the lower bound index of a key in a sorted slice.
func GeneralLowerBound(s []int, key int) int {
	isOK := func(index, key int) bool {
		return s[index] >= key
	}

	ng, ok := -1, len(s)
	for int(math.Abs(float64(ok-ng))) > 1 {
		mid := (ok + ng) / 2
		if isOK(mid, key) {
			ok = mid
		} else {
			ng = mid
		}
	}

	return ok
}

// GeneralUpperBound finds the upper bound index of a key in a sorted slice.
func GeneralUpperBound(s []int, key int) int {
	isOK := func(index, key int) bool {
		return s[index] > key
	}

	ng, ok := -1, len(s)
	for int(math.Abs(float64(ok-ng))) > 1 {
		mid := (ok + ng) / 2
		if isOK(mid, key) {
			ok = mid
		} else {
			ng = mid
		}
	}

	return ok
}

/*********** Union Find ***********/

// InitParents initializes the parent array for union-find structure.
func InitParents(parents []int, maxNodeId int) {
	for i := 0; i <= maxNodeId; i++ {
		parents[i] = i
	}
}

// unite merges two sets identified by x and y.
func unite(x, y int, parents []int) {
	xp, yp := root(x, parents), root(y, parents)
	if xp == yp {
		return
	}

	parents[xp] = yp
}

// same checks if two elements belong to the same set.
func same(x, y int, parents []int) bool {
	return root(x, parents) == root(y, parents)
}

// root finds the root of the set containing x.
func root(x int, parents []int) int {
	if parents[x] == x {
		return x
	}

	parents[x] = root(parents[x], parents)
	return parents[x]
}

/*********** Factorization, Prime Number ***********/

// TrialDivision performs prime factorization of integer N.
func TrialDivision(n int) map[int]int {
	if n <= 1 {
		panic(errors.New("[argument error]: TrialDivision only accepts a NATURAL number"))
	}

	p := map[int]int{}
	for i := 2; i*i <= n; i++ {
		exp := 0
		for n%i == 0 {
			exp++
			n /= i
		}

		if exp == 0 {
			continue
		}
		p[i] = exp
	}
	if n > 1 {
		p[n] = 1
	}

	return p
}

// IsPrime checks if an integer is a prime number.
func IsPrime(n int) bool {
	if n == 1 {
		return false
	}

	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}

	return true
}

/*********** Inverse Element ***********/

// CalcNegativeMod calculates the positive equivalent of a negative value modulo m.
func CalcNegativeMod(val, m int) int {
	res := val % m
	if res < 0 {
		res += m
	}
	return res
}

// modpow calculates a^e mod m using binary exponentiation.
func modpow(a, e, m int) int {
	if e == 0 {
		return 1
	}

	if e%2 == 0 {
		halfE := e / 2
		half := modpow(a, halfE, m)
		return half * half % m
	}

	return a * modpow(a, e-1, m) % m
}

// CalcModInv calculates the modular inverse of a modulo m using Fermat's little theorem.
func CalcModInv(a, m int) int {
	return modpow(a, m-2, m)
}

/********** heap package (Integer Priority Queue) **********/

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

// Push adds an element to the heap.
func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

// Pop removes and returns the top element from the heap.
func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

/********** sort package (snippets) **********/
// Example usage of sort package
// sort.Sort(sort.IntSlice(s))
// sort.Sort(sort.Reverse(sort.IntSlice(s)))
// sort.Sort(sort.Float64Slice(s))
// sort.Sort(sort.StringSlice(s))

// struct sort
type Mono struct {
	key, value int
}
type MonoList []*Mono

func (ml MonoList) Len() int {
	return len(ml)
}
func (ml MonoList) Swap(i, j int) {
	ml[i], ml[j] = ml[j], ml[i]
}
func (ml MonoList) Less(i, j int) bool {
	return ml[i].value < ml[j].value
}

// Example usage of struct sorting
// oddCountList, evenCountList := make(MonoList, 1e5+1), make(MonoList, 1e5+1)
// for i := 0; i <= 1e5; i++ {
// 	oddCountList[i] = &Mono{key: i, value: oddMemo[i]}
// 	evenCountList[i] = &Mono{key: i, value: evenMemo[i]}
// }
// sort.Sort(sort.Reverse(oddCountList))		// DESC sort
// sort.Sort(sort.Reverse(evenCountList))	// DESC sort

/********** copy function (snippets) **********/
// Example of copying a slice
// a = []int{0, 1, 2}
// b = make([]int, len(a))
// copy(b, a)

/********** I/O usage **********/

// Example usage of I/O functions
// str := ReadString()
// i := ReadInt()
// X := ReadIntSlice(n)
// S := ReadRuneSlice()

/********** String Split **********/

// Example of splitting a string into substrings
// strs := strings.Split(string(runeSlice), "+")

/*******************************************************************/

// Constants for the program
const MOD = 1000000000 + 7
const ALPHABET_NUM = 26

var n, x int
var A []int

// main function where the program execution starts
func main() {
	// Read input values for n and x
	n, x = ReadInt(), ReadInt()
	A = ReadIntSlice(n)

	// Sort the array A
	sort.Sort(sort.IntSlice(A))

	// Initialize answer variable
	ans := 0
	// Count how many elements can be taken from A without exceeding x
	for i := 0; i < n; i++ {
		if x >= A[i] {
			ans++
			x -= A[i]
		} else {
			break
		}
	}
	// Adjust answer if all elements are taken and there is still remaining x
	if ans == n && x > 0 {
		ans--
	}
	// Print the final answer
	fmt.Println(ans)
}
