package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Initialize input/output handling
	io := NewIo()
	defer io.Flush()

	// Read the number of elements
	n := io.Int()

	// Create a slice to hold the input integers
	aa := make([]int, n)

	// Read each integer and store it in the slice
	for i := 0; i < n; i++ {
		aa[i] = io.Int()
	}

	// Compute the cumulative sum of the input integers
	cumsum := CumSum(aa)

	// Initialize the answer with a large value
	ans := 2020202020

	// Iterate through the cumulative sums to find the minimum difference
	for i := 1; i < len(cumsum)-1; i++ {
		ans = Min(ans, Abs(cumsum[len(cumsum)-1]-cumsum[i]-(cumsum[i]-cumsum[0])))
	}

	// Output the final answer
	fmt.Println(ans)
}

// Io struct for handling input and output
type Io struct {
	reader    *bufio.Reader
	writer    *bufio.Writer
	tokens    []string
	nextToken int
}

// NewIo initializes a new Io instance
func NewIo() *Io {
	return &Io{
		reader: bufio.NewReader(os.Stdin),
		writer: bufio.NewWriter(os.Stdout),
	}
}

// Flush writes any buffered data to the output
func (io *Io) Flush() {
	err := io.writer.Flush()
	if err != nil {
		panic(err)
	}
}

// NextLine reads a full line from input
func (io *Io) NextLine() string {
	var buffer []byte
	for {
		line, isPrefix, err := io.reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buffer = append(buffer, line...)
		if !isPrefix {
			break
		}
	}
	return string(buffer)
}

// Next retrieves the next token from the input
func (io *Io) Next() string {
	for io.nextToken >= len(io.tokens) {
		line := io.NextLine()
		io.tokens = strings.Fields(line)
		io.nextToken = 0
	}
	r := io.tokens[io.nextToken]
	io.nextToken++
	return r
}

// Int converts the next token to an integer
func (io *Io) Int() int {
	i, err := strconv.Atoi(io.Next())
	if err != nil {
		panic(err)
	}
	return i
}

// Float converts the next token to a float64
func (io *Io) Float() float64 {
	i, err := strconv.ParseFloat(io.Next(), 64)
	if err != nil {
		panic(err)
	}
	return i
}

// PrintLn prints a line to the output
func (io *Io) PrintLn(a ...interface{}) {
	fmt.Fprintln(io.writer, a...)
}

// Printf formats and prints to the output
func (io *Io) Printf(format string, a ...interface{}) {
	fmt.Fprintf(io.writer, format, a...)
}

// PrintIntLn prints a slice of integers to the output
func (io *Io) PrintIntLn(a []int) {
	b := []interface{}{}
	for _, x := range a {
		b = append(b, x)
	}
	io.PrintLn(b...)
}

// PrintStringLn prints a slice of strings to the output
func (io *Io) PrintStringLn(a []string) {
	b := []interface{}{}
	for _, x := range a {
		b = append(b, x)
	}
	io.PrintLn(b...)
}

// Log prints a variable to stderr for debugging
func Log(name string, value interface{}) {
	fmt.Fprintf(os.Stderr, "%s=%+v\n", name, value)
}

// Abs returns the absolute value of an integer
func Abs(a int) int {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// Pow calculates p raised to the power of q
func Pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

// Min returns the minimum value from a list of integers
func Min(nums ...int) int {
	if len(nums) == 0 {
		panic("function min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

// Max returns the maximum value from a list of integers
func Max(nums ...int) int {
	if len(nums) == 0 {
		panic("function max() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}
	return res
}

// SortAsc sorts a slice of integers in ascending order
func SortAsc(a []int) []int {
	sort.Ints(a)
	return a
}

// SortDesc sorts a slice of integers in descending order
func SortDesc(a []int) []int {
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	return a
}

// GCD computes the greatest common divisor of two integers
func GCD(a, b int) int {
	if b == 0 {
		return a
	}
	return GCD(b, a%b)
}

// LCM computes the least common multiple of two integers
func LCM(a, b int) int {
	if a == 0 && b == 0 {
		return 0
	}
	return a * b / GCD(a, b)
}

// CumSum computes the cumulative sum of a slice of integers
func CumSum(nums []int) []int {
	sums := []int{0}

	for i := 0; i < len(nums); i++ {
		sums = append(sums, sums[i]+nums[i])
	}
	return sums
}

// BisectLeft performs a binary search to find the leftmost index of a target in a sorted slice
func BisectLeft(nums []int, left, right int, target int) int {
	if left == right {
		if nums[left] == target {
			return left
		} else if nums[left] < target {
			return left + 1
		} else {
			return left
		}
	}

	mid := (left + right) / 2
	if nums[mid] == target {
		return mid
	}

	if nums[mid] > target {
		return BisectLeft(nums, left, mid, target)
	} else if nums[mid] < target {
		return BisectLeft(nums, mid+1, right, target)
	}
	return 0
}

// Permutations generates all permutations of a slice of integers
func Permutations(nums []int) [][]int {
	n := len(nums)
	if n == 0 {
		return [][]int{}
	}
	ans := [][]int{}

	for _, n := range nums {
		rest := remove(nums, n)
		lists := Permutations(rest)
		if len(lists) == 0 {
			lists = [][]int{nil}
		}

		for i := 0; i < len(lists); i++ {
			lists[i] = append(lists[i], n)
			ans = append(ans, lists[i])
		}
	}
	return ans
}

// remove removes a target integer from a slice
func remove(nums []int, target int) []int {
	result := []int{}
	for i := 0; i < len(nums); i++ {
		if nums[i] != target {
			result = append(result, nums[i])
		}
	}
	return result
}

// PowerSet generates the power set of a slice of integers
func PowerSet(nums []int) [][]int {
	size := Pow(2, len(nums))
	result := make([][]int, size)

	idx := 0
	result[idx] = []int{}
	idx++

	for _, n := range nums {
		max := idx
		for i := 0; i < max; i++ {
			result[idx] = copyAndAppend(result[i], n)
			idx++
		}
	}

	return result
}

// copyAndAppend creates a new slice by appending an integer to an existing slice
func copyAndAppend(nums []int, n int) []int {
	dst := make([]int, len(nums)+1)
	copy(dst, nums)
	dst[len(nums)] = n
	return dst
}

// Combination generates all combinations of k elements from a slice of integers
func Combination(nums []int, k int) [][]int {
	size := len(nums)
	result := make([][]int, CombinationCount(int64(len(nums)), int64(k), 10e10))
	bi := (1 << uint(k)) - 1
	max := 1 << uint(size)
	idx := 0

	for bi < max {
		flags := bi
		s := []int{}
		for _, n := range nums {
			if flags%2 != 0 {
				s = append(s, n)
			}
			flags /= 2
		}
		result[idx] = s
		idx++
		bi = Combination2NextIndex(bi)
	}
	return result
}

// Combination2NextIndex computes the next combination index
func Combination2NextIndex(n int) int {
	smallest := n & -n
	ripple := n + smallest
	newSmallest := ripple & -ripple
	ones := ((newSmallest / smallest) >> 1) - 1
	return ripple | ones
}

// CombinationCount calculates nCm using memoization to reduce computation time
func CombinationCount(n, m, maxInput int64) int64 {
	memo := map[int64]map[int64]int64{}
	for i := int64(1); i <= maxInput*maxInput; i++ {
		memo[int64(i)] = map[int64]int64{}
	}
	return combinationCount(n, m, memo)
}

// combinationCount is a helper function for calculating combinations with memoization
func combinationCount(n, m int64, memo map[int64]map[int64]int64) int64 {
	if n == m || m == 0 {
		return 1
	}

	left, lOK := memo[n-1][m-1]
	right, rOK := memo[n-1][m]

	if lOK && rOK {
		return left + right
	}

	if lOK {
		right = combinationCount(n-1, m, memo)
		memo[n-1][m] = right
		return left + right
	}

	if rOK {
		left = combinationCount(n-1, m-1, memo)
		memo[n-1][m-1] = left
		return left + right
	}

	left = combinationCount(n-1, m-1, memo)
	right = combinationCount(n-1, m, memo)
	memo[n-1][m-1] = left
	memo[n-1][m] = right
	return left + right
}

// Fact computes the factorial of a number
func Fact(n int) int {
	if n == 0 {
		return 1
	} else {
		return n * Fact(n-1)
	}
}

// Divisors returns all divisors of a given integer
func Divisors(n int) []int {
	divisors := map[int]bool{}
	for i := 1; i < int(math.Sqrt(float64(n)))+1; i++ {
		if n%i == 0 {
			divisors[i] = true
			if i != n {
				divisors[n/i] = true
			}
		}
	}
	ans := []int{}
	for k := range divisors {
		ans = append(ans, k)
	}
	return ans
}
