package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"reflect"
	"sort"
	"strconv"
	"strings"
	// "regexp"
)

// Define a structure for sorting pairs
type pair struct {
	index  int64
	p1, p2 interface{}
}
type pairs []pair

// Implement sort.Interface for pairs
func (slice pairs) Len() int {
	return len(slice)
}

func (slice pairs) Less(i, j int) bool {
	return slice[i].index < slice[j].index
}

func (slice pairs) Swap(i, j int) {
	slice[i], slice[j] = slice[j], slice[i]
}

// Define a structure for sorting int64 slices
type Int64Slice []int64

// Implement sort.Interface for Int64Slice
func (slice Int64Slice) Len() int {
	return len(slice)
}

func (slice Int64Slice) Less(i, j int) bool {
	return slice[i] < slice[j]
}

func (slice Int64Slice) Swap(i, j int) {
	slice[i], slice[j] = slice[j], slice[i]
}

// Utility functions for sorting int64 slices
func Int64s(a []int64)                    { sort.Sort(Int64Slice(a)) }
func Int64sSliceAreSorted(a []int64) bool { return sort.IsSorted(Int64Slice(a)) }

// Constants for buffer sizes and infinity value
const (
	initialBufSize = 1e4
	maxBufSize     = 1e8
	INF            = 1e8
)

// Global variables for input/output handling and direction vectors
var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
	di      = []int64{-1, 0, 1, 0} // Direction vectors for row movement
	dj      = []int64{0, -1, 0, 1} // Direction vectors for column movement
)

func main() {
	// Set up the scanner buffer and read three integers A, B, C
	buf := make([]byte, initialBufSize)
	scanner.Buffer(buf, maxBufSize)
	scanner.Split(bufio.ScanWords)
	A, B, C := readInt(), readInt(), readInt()
	
	// Check if C is within the range [A, B] and print the result
	if C >= A && C <= B {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

/*==========================================
 *             Library Functions
 *==========================================*/

// NextPermutation generates the next lexicographical permutation of the given sort.Interface
func NextPermutation(x sort.Interface) bool {
	n := x.Len() - 1
	if n < 1 {
		return false
	}
	j := n - 1
	// Find the rightmost ascent
	for ; !x.Less(j, j+1); j-- {
		if j == 0 {
			return false
		}
	}
	l := n
	// Find the rightmost successor to the pivot
	for !x.Less(j, l) {
		l--
	}
	x.Swap(j, l) // Swap the pivot with its successor
	// Reverse the suffix
	for k, l := j+1, n; k < l; {
		x.Swap(k, l)
		k++
		l--
	}
	return true
}

// doubleAry initializes a 2D slice with a given height, width, and initial value
func doubleAry(h int64, w int64, init int64) (res [][]int64) {
	res = make([][]int64, h)
	for i := int64(0); i < h; i++ {
		res[i] = make([]int64, w)
		for j := int64(0); j < w; j++ {
			res[i][j] = init
		}
	}
	return
}

// aryEq checks if two int64 slices are equal
func aryEq(a []int64, b []int64) bool {
	return reflect.DeepEqual(a, b)
}

// clone creates a copy of an int64 slice
func clone(n []int64) (r []int64) {
	r = make([]int64, len(n))
	for i := 0; i < len(n); i++ {
		r[i] = n[i]
	}
	return
}

// write writes a string to the output buffer
func write(s string) {
	writer.WriteString(s)
}

// print flushes the output buffer
func print() {
	writer.Flush()
}

// readLine reads a line from the input
func readLine() (s string) {
	if scanner.Scan() {
		s = scanner.Text()
	}
	return s
}

// readInt reads an int64 from the input
func readInt() (read int64) {
	scanner.Scan()
	read, err := strconv.ParseInt(scanner.Text(), 10, 64)
	if err != nil {
		panic(err)
	}
	return
}

// readFloat reads a float64 from the input
func readFloat() (read float64) {
	scanner.Scan()
	read, err := strconv.ParseFloat(scanner.Text(), 64)
	if err != nil {
		panic(err)
	}
	return
}

// readRunes reads a string and returns its runes
func readRunes() (read []rune) {
	scanner.Scan()
	for _, v := range scanner.Text() {
		read = append(read, v)
	}
	return
}

// readString reads a string from the input
func readString() (read string) {
	scanner.Scan()
	read = scanner.Text()
	return
}

// readStrings reads a string and returns its characters as a slice of strings
func readStrings() (read []string) {
	scanner.Scan()
	for _, v := range scanner.Text() {
		read = append(read, string(v))
	}
	return
}

// s2i converts a string to int64
func s2i(s string) int64 {
	var intVal, e = strconv.ParseInt(s, 10, 64)
	if e != nil {
		panic(e)
	}
	return intVal
}

// i2s converts an int64 to string
func i2s(i int64) string {
	var strVal = strconv.FormatInt(i, 10)
	return strVal
}

// s2f converts a string to float64
func s2f(s string) float64 {
	var floatVal, e = strconv.ParseFloat(s, 64)
	if e != nil {
		panic(e)
	}
	return floatVal
}

// abs returns the absolute value of an int64
func abs(i int64) int64 {
	return int64(math.Abs(float64(i)))
}

// max returns the maximum value from a variadic list of int64
func max(a ...int64) int64 {
	ans := int64(0)
	for i, v := range a {
		if i == 0 {
			ans = v
		}
		if ans < v {
			ans = v
		}
	}
	return ans
}

// min returns the minimum value from a variadic list of int64
func min(a ...int64) int64 {
	ans := int64(0)
	for i, v := range a {
		if i == 0 {
			ans = v
		}
		if ans > v {
			ans = v
		}
	}
	return ans
}

// sum calculates the sum of an int64 slice
func sum(i []int64) int64 {
	sum := int64(0)
	for _, val := range i {
		sum += val
	}
	return sum
}

// split splits a string into fields
func split(s string) []string {
	return strings.Fields(s)
}

// strAry2intAry converts a slice of strings to a slice of int64
func strAry2intAry(strs []string) []int64 {
	var ret = make([]int64, 0, len(strs))
	for _, str := range strs {
		var intVal = s2i(str)
		ret = append(ret, intVal)
	}
	return ret
}

// intAry2strAry converts a slice of int64 to a slice of strings
func intAry2strAry(nums []int64) []string {
	var ret = make([]string, 0, len(nums))
	for _, num := range nums {
		var strVal = i2s(num)
		ret = append(ret, strVal)
	}
	return ret
}

// ary2str joins a slice of strings into a single string
func ary2str(strs []string) string {
	return strings.Join(strs, " ")
}

// reverse reverses an int64 slice
func reverse(res []int64) []int64 {
	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}
	return res
}

// reverseStr reverses a string slice
func reverseStr(res []string) []string {
	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}
	return res
}

// ini initializes the first element of a slice with a given value
func ini(res []int, init int) {
	if len(res) == 0 {
		return
	}
	res[0] = init
	for i := 0; i < len(res); i++ {
		copy(res[i:], res[:i])
	}
}

// Uncomment the following function to see a regex example
// func regexpExample() {
//     // Your code here!
//     var str = "13:20"
//     r := regexp.MustCompile(`(\d+):(\d+)`)
//     fmt.Println(r.FindStringSubmatch(str))
// }

// Uncomment the following struct and function to see a stable sort example
// type Country struct {
//     gold int
//     silver int
//     blonze int
// }

// // Example of stable sorting
// func stableSortExample() []Country{
//     var country = []Country {
//         {gold:1, silver:2, blonze:3},
//         {gold:1, silver:2, blonze:3},
//         {gold:1, silver:3, blonze:2},
//         {gold:1, silver:3, blonze:3},
//     }
//     sort.SliceStable(country, func(i, j int) bool { return country[i].blonze > country[j].blonze })
//     sort.SliceStable(country, func(i, j int) bool { return country[i].silver > country[j].silver })
//     sort.SliceStable(country, func(i, j int) bool { return country[i].gold > country[j].gold })
//     return country
// }
