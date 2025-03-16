package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of strings
	N := readInt()

	// Read the list of strings
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i] = readString()
	}

	// List of characters that can be selected
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a list to count occurrences of each character in'march'
	march_lis := make([]int, len(march))

	// Count the occurrences of characters in'march' in the list of strings
	for _, s := range S {
		if s[0] == strings.ToUpper(march[0]) {
			march_lis[0]++
		}
		if s[0] == strings.ToUpper(march[1]) {
			march_lis[1]++
		}
		if s[0] == strings.ToUpper(march[2]) {
			march_lis[2]++
		}
		if s[0] == strings.ToUpper(march[3]) {
			march_lis[3]++
		}
		if s[0] == strings.ToUpper(march[4]) {
			march_lis[4]++
		}
	}

	// Initialize the answer variable
	ans := 0

	// Calculate the number of combinations of three elements from march_lis
	for x, y, z := range combinations(march_lis, 3) {
		ans += x * y * z
	}

	// Print the final answer
	fmt.Println(ans)
}

// Function to read a single line of input
func readString() string {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	return s[:len(s)-1]
}

// Function to read a single integer
func readInt() int {
	i, _ := strconv.Atoi(readString())
	return i
}

// Function to read a single float
func readFloat() float64 {
	f, _ := strconv.ParseFloat(readString(), 64)
	return f
}

// Function to read a single line of input
func readLine(args...interface{}) {
	fmt.Fscan(os.Stdin, args...)
}

// Function to convert input to an integer
func parseInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

// Function to convert input to a list of integers
func parseIntSlice(s string) []int {
	return strings.Split(s, " ")
}

// Function to convert input to a list of integers
func parseInt64Slice(s string) []int64 {
	var arr []int64
	for _, ss := range strings.Split(s, " ") {
		if n, err := strconv.ParseInt(ss, 10, 64); err == nil {
			arr = append(arr, n)
		}
	}
	return arr
}

// Function to convert input to a list of floats
func parseFloatSlice(s string) []float64 {
	var arr []float64
	for _, ss := range strings.Split(s, " ") {
		if n, err := strconv.ParseFloat(ss, 64); err == nil {
			arr = append(arr, n)
		}
	}
	return arr
}

// Function to convert input to a list of strings
func parseStringSlice(s string) []string {
	return strings.Split(s, " ")
}

// Function to convert input to a list of strings
func parseString64Slice(s string) []string {
	var arr []string
	for _, ss := range strings.Split(s, " ") {
		arr = append(arr, ss)
	}
	return arr
}

// Function to convert input to a list of strings
func parseBoolSlice(s string) []bool {
	var arr []bool
	for _, ss := range strings.Split(s, " ") {
		if ss == "true" {
			arr = append(arr, true)
		} else if ss == "false" {
			arr = append(arr, false)
		}
	}
	return arr
}

// Function to convert input to a list of strings
func parseInt64(s string) int64 {
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

// Function to convert input to a list of strings
func parseFloat64(s string) float64 {
	i, _ := strconv.ParseFloat(s, 64)
	return i
}

// Function to convert input to a list of strings
func parseBool(s string) bool {
	b, _ := strconv.ParseBool(s)
	return b
}

// Function to create combinations from a list of tuples
func combinations(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr)-r+1; i++ {
			cur = append(cur, arr[i])
			helper(arr, i+1, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create combinations from a list of tuples
func combinationsWithReplacement(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr); i++ {
			cur = append(cur, arr[i])
			helper(arr, i, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create permutations from a list of tuples
func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}
	helper = func(arr []int, l int) {
		if l == len(arr)-1 {
			res = append(res, append([]int{}, arr...))
			return
		}
		for i := l; i < len(arr); i++ {
			arr[l], arr[i] = arr[i], arr[l]
			helper(arr, l+1)
			arr[l], arr[i] = arr[i], arr[l]
		}
	}
	helper(arr, 0)
	return res
}

// Function to create permutations from a list of tuples
func permutationsWithReplacement(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}
	helper = func(arr []int, l int) {
		if l == len(arr)-1 {
			res = append(res, append([]int{}, arr...))
			return
		}
		for i := l; i < len(arr); i++ {
			arr[l], arr[i] = arr[i], arr[l]
			helper(arr, l+1)
			arr[l], arr[i] = arr[i], arr[l]
		}
	}
	helper(arr, 0)
	return res
}

// Function to create combinations from a list of tuples
func combinationsWithReplacement(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr); i++ {
			cur = append(cur, arr[i])
			helper(arr, i, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create combinations from a list of tuples
func combinations(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr)-r+1; i++ {
			cur = append(cur, arr[i])
			helper(arr, i+1, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create combinations from a list of tuples
func combinationsWithReplacement(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr); i++ {
			cur = append(cur, arr[i])
			helper(arr, i, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create permutations from a list of tuples
func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}
	helper = func(arr []int, l int) {
		if l == len(arr)-1 {
			res = append(res, append([]int{}, arr...))
			return
		}
		for i := l; i < len(arr); i++ {
			arr[l], arr[i] = arr[i], arr[l]
			helper(arr, l+1)
			arr[l], arr[i] = arr[i], arr[l]
		}
	}
	helper(arr, 0)
	return res
}

// Function to create permutations from a list of tuples
func permutationsWithReplacement(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}
	helper = func(arr []int, l int) {
		if l == len(arr)-1 {
			res = append(res, append([]int{}, arr...))
			return
		}
		for i := l; i < len(arr); i++ {
			arr[l], arr[i] = arr[i], arr[l]
			helper(arr, l+1)
			arr[l], arr[i] = arr[i], arr[l]
		}
	}
	helper(arr, 0)
	return res
}

// Function to create combinations from a list of tuples
func combinationsWithReplacement(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr); i++ {
			cur = append(cur, arr[i])
			helper(arr, i, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create combinations from a list of tuples
func combinations(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr)-r+1; i++ {
			cur = append(cur, arr[i])
			helper(arr, i+1, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create combinations from a list of tuples
func combinationsWithReplacement(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr); i++ {
			cur = append(cur, arr[i])
			helper(arr, i, r-1, cur)
			cur = cur[:len(cur)-1]
		}
	}
	helper(arr, 0, r, []int{})
	return res
}

// Function to create permutations from a list of tuples
func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}
	helper = func(arr []int, l int) {
		if l == len(arr)-1 {
			res = append(res, append([]int{}, arr...))
			return
		}
		for i := l; i < len(arr); i++ {
			arr[l], arr[i] = arr[i], arr[l]
			helper(arr, l+1)
			arr[l], arr[i] = arr[i], arr[l]
		}
	}
	helper(arr, 0)
	return res
}

// Function to create permutations from a list of tuples
func permutationsWithReplacement(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}
	helper = func(arr []int, l int) {
		if l == len(arr)-1 {
			res = append(res, append([]int{}, arr...))
			return
		}
		for i := l; i < len(arr); i++ {
			arr[l], arr[i] = arr[i], arr[l]
			helper(arr, l+1)
			arr[l], arr[i] = arr[i], arr[l]
		}
	}
	helper(arr, 0)
	return res
}

// Function to create combinations from a list of tuples
func combinationsWithReplacement(arr []int, r int) [][]int {
	var helper func([]int, int, int, []int)
	res := [][]int{}
	helper = func(arr []int, l, r int, cur []int) {
		if r == 0 {
			res = append(res, append([]int{}, cur...))
			return
		}
		for i := l; i < len(arr); i++ {
			cur = append(cur, arr[i])
			helper(arr, i