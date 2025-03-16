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

// The main function is the entry point of the program.
func main() {
	// Initialize an Io struct and call its Flush method to ensure that all output is written before the program exits.
	io := NewIo()
	defer io.Flush()

	// Read the number n from the standard input.
	n := io.Int()

	// Initialize an array aa of length n to store the input integers.
	aa := make([]int, n)

	// Read n integers from the standard input and store them in the aa array using a for loop.
	for i := 0; i < n; i++ {
		aa[i] = io.Int()
	}

	// Compute the cumulative sum of the aa array using the CumSum function.
	cumsum := CumSum(aa)

	// Initialize a variable ans to store the answer.
	ans := 2020202020

	// Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
	for i := 1; i < len(cumsum)-1; i++ {
		// Compute the absolute difference between the last cumulative sum and the current cumulative sum.
		diff1 := abs(cumsum[len(cumsum)-1] - cumsum[i])

		// Compute the difference between the current cumulative sum and the first cumulative sum.
		diff2 := cumsum[i] - cumsum[0]

		// Keep the minimum of these two differences as the answer.
		ans = min(ans, diff1, diff2)
	}

	// Print the answer using the PrintLn method of the Io struct.
	fmt.Println(ans)
}

// NewIo initializes an Io struct.
func NewIo() *Io {
	return &Io{
		reader:    bufio.NewReader(os.Stdin),
		writer:    bufio.NewWriter(os.Stdout),
		tokens:    []string{},
		nextToken: 0,
	}
}

// The Io struct represents the standard input and output streams.
type Io struct {
	reader    *bufio.Reader
	writer    *bufio.Writer
	tokens    []string
	nextToken int
}

// The Flush method of the Io struct ensures that all output is written before the program exits.
func (io *Io) Flush() {
	err := io.writer.Flush()
	if err != nil {
		panic(err)
	}
}

// The NextLine method of the Io struct reads a line from the standard input and returns it as a string.
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

// The Next method of the Io struct reads a token from the standard input and returns it as a string.
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

// The Int method of the Io struct reads an integer from the standard input and returns it.
func (io *Io) Int() int {
	i, err := strconv.Atoi(io.Next())
	if err != nil {
		panic(err)
	}
	return i
}

// The PrintLn method of the Io struct prints a line to the standard output.
func (io *Io) PrintLn(a ...interface{}) {
	fmt.Fprintln(io.writer, a...)
}

// The Printf method of the Io struct prints a formatted line to the standard output.
func (io *Io) Printf(format string, a ...interface{}) {
	fmt.Fprintf(io.writer, format, a...)
}

// The PrintIntLn method of the Io struct prints an integer array to the standard output.
func (io *Io) PrintIntLn(a []int) {
	io.PrintLn(a)
}

// The PrintStringLn method of the Io struct prints a string array to the standard output.
func (io *Io) PrintStringLn(a []string) {
	io.PrintLn(a)
}

// The Log method logs a message to the standard error stream.
func Log(name string, value interface{}) {
	fmt.Fprintf(os.Stderr, "%s=%+v\n", name, value)
}

// The Abs function returns the absolute value of an integer.
func Abs(a int) int {
	if a >= 0 {
		return a
	} else {
		return -a
	}
}

// The Pow function returns the result of raising a to the power of b.
func Pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

// The Min function returns the minimum of a list of integers.
func Min(nums ...int) int {
	if len(nums) == 0 {
		panic("funciton min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

// The Max function returns the maximum of a list of integers.
func Max(nums ...int) int {
	if len(nums) == 0 {
		panic("funciton max() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}
	return res
}

// The SortAsc function sorts an integer slice in ascending order.
func SortAsc(a []int) []int {
	sort.Ints(a)
	return a
}

// The SortDesc function sorts an integer slice in descending order.
func SortDesc(a []int) []int {
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	return a
}

// The GCD function returns the greatest common divisor of a and b.
func GCD(a, b int) int {
	if b == 0 {
		return a
	}
	return GCD(b, a%b)
}

// The LCM function returns the least common multiple of a and b.
func LCM(a, b int) int {
	if a == 0 && b == 0 {
		return 0
	}
	return a * b / GCD(a, b)
}

// The CumSum function computes the cumulative sum of an integer slice.
func CumSum(nums []int) []int {
	sums := []int{0}

	for i := 0; i < len(nums); i++ {
		sums = append(sums, sums[i]+nums[i])
	}
	return sums
}

// The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
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

// The Permutations function returns all permutations of a slice.
func Permutations(nums []int) [][]int {
	size := len(nums)
	result := make([][]int, 0, Fact(size))

	for _, n := range nums {
		rest := remove(nums, n)
		lists := Permutations(rest)
		for _, list := range lists {
			lists = append(lists, append(list, n))
			result = append(result, lists...)
		}
	}
	return result
}

// The remove function removes the first occurrence of x from a slice.
func remove(nums []int, x int) []int {
	result := make([]int, 0, len(nums)-1)
	for _, n := range nums {
		if n != x {
			result = append(result, n)
		}
	}
	return result
}

// The PowerSet function returns all subsets of a slice.
func PowerSet(nums []int) [][]int {
	size := len(nums)
	result := make([][]int, 0, Pow(2, size))

	idx := 0
	result = append(result, []int{})
	idx++

	for _, n := range nums {
		max := idx
		for i := 0; i < max; i++ {
			result = append(result, copyAndAppend(result[i], n))
			idx++
		}
	}

	return result
}

// The copyAndAppend function returns a copy of x with y appended to it.
func copyAndAppend(x, y []int) []int {
	dst := make([]int, len(x)+1)
	copy(dst, x)
	dst[len(x)] = y
	return dst
}

// The Combination function returns all combinations of size r from a slice.
func Combination(nums []int, r int) [][]int {
	size := len(nums)
	result := make([][]int, 0, CombinationCount(int64(len(nums)), int64(r), 10e10))
	bi := (1 << uint(r)) - 1
	max := 1 << uint(size)
	idx := 0

	for bi < max {
		flags := bi
		s := []int{}
		for i := 0; i < size; i++ {
			if flags%2 != 0 {
				s = append(s, nums[i])
			}
			flags /= 2
		}
		result = append(result, s)
		idx++
		bi = Combination2NextIndex(bi)
	}
	return result
}

// The CombinationCount function returns the number of combinations of size r from a slice.
func CombinationCount(n, m, maxInput int64) int64 {
	memo := map[int64]map[int64]int64{}
	for i := int64(1); i <= maxInput*maxInput; i++ {
		memo[i] = map[int64]int64{}
	}
	return combinationCount(n, m, memo)
}
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

// The Fact function returns the factorial of n.
func Fact(n int) int {
	if n == 0 {
		return 1
	} else {
		return n * Fact(n-1)
	}
}

// The Divisors function returns all divisors of n.
func Divisors(n int) []int {
	divisors := map[int]bool{}
	for i := 1; i < int(math.Sqrt(float64(n)))+1; i++ {
		if n%i == 0 {
	