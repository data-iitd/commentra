
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases
	t, _ := strconv.Atoi(readLine())

	// Run the solution function for each test case
	for i := 0; i < t; i++ {
		solution()
	}
}

// ReadLine reads a single line from stdin.
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _ := buf.ReadString('\n')
	return strings.TrimSpace(line)
}

// ReadString reads a single word from stdin.
func readString() string {
	buf := bufio.NewReader(os.Stdin)
	line, _ := buf.ReadString('\n')
	return strings.TrimSpace(line)
}

// ReadInt reads a single integer from stdin.
func readInt() int {
	i, _ := strconv.Atoi(readLine())
	return i
}

// ReadInts reads multiple integers from stdin.
func readInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.Atoi(readLine())
	}
	return ints
}

// ReadInt64s reads multiple integers from stdin.
func readInt64s(n int) []int64 {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.ParseInt(readLine(), 10, 64)
	}
	return ints
}

// ReadFloat64s reads multiple float64s from stdin.
func readFloat64s(n int) []float64 {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		floats[i], _ = strconv.ParseFloat(readLine(), 64)
	}
	return floats
}

// ReadStrings reads multiple strings from stdin.
func readStrings(n int) []string {
	strings := make([]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readString()
	}
	return strings
}

// ReadFloat reads a single float64 from stdin.
func readFloat() float64 {
	f, _ := strconv.ParseFloat(readLine(), 64)
	return f
}

// ReadFloats reads multiple float64s from stdin.
func readFloats(n int) []float64 {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		floats[i], _ = strconv.ParseFloat(readLine(), 64)
	}
	return floats
}

// ReadInt64 reads a single int64 from stdin.
func readInt64() int64 {
	i, _ := strconv.ParseInt(readLine(), 10, 64)
	return i
}

// ReadInt64s reads multiple int64s from stdin.
func readInt64s(n int) []int64 {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.ParseInt(readLine(), 10, 64)
	}
	return ints
}

// ReadIntPair reads a pair of integers from stdin.
func readIntPair() (int, int) {
	line := readLine()
	i, j := 0, 0
	fmt.Sscanf(line, "%d %d", &i, &j)
	return i, j
}

// ReadInt64Pair reads a pair of int64s from stdin.
func readInt64Pair() (int64, int64) {
	line := readLine()
	i, j := int64(0), int64(0)
	fmt.Sscanf(line, "%d %d", &i, &j)
	return i, j
}

// ReadFloat64Pair reads a pair of float64s from stdin.
func readFloat64Pair() (float64, float64) {
	line := readLine()
	i, j := float64(0), float64(0)
	fmt.Sscanf(line, "%f %f", &i, &j)
	return i, j
}

// ReadStringPair reads a pair of strings from stdin.
func readStringPair() (string, string) {
	line := readLine()
	i, j := "", ""
	fmt.Sscanf(line, "%s %s", &i, &j)
	return i, j
}

// ReadStringTriplet reads a triplet of strings from stdin.
func readStringTriplet() (string, string, string) {
	line := readLine()
	i, j, k := "", "", ""
	fmt.Sscanf(line, "%s %s %s", &i, &j, &k)
	return i, j, k
}

// ReadIntTriplet reads a triplet of integers from stdin.
func readIntTriplet() (int, int, int) {
	line := readLine()
	i, j, k := 0, 0, 0
	fmt.Sscanf(line, "%d %d %d", &i, &j, &k)
	return i, j, k
}

// ReadInt64Triplet reads a triplet of int64s from stdin.
func readInt64Triplet() (int64, int64, int64) {
	line := readLine()
	i, j, k := int64(0), int64(0), int64(0)
	fmt.Sscanf(line, "%d %d %d", &i, &j, &k)
	return i, j, k
}

// ReadFloat64Triplet reads a triplet of float64s from stdin.
func readFloat64Triplet() (float64, float64, float64) {
	line := readLine()
	i, j, k := float64(0), float64(0), float64(0)
	fmt.Sscanf(line, "%f %f %f", &i, &j, &k)
	return i, j, k
}

// ReadIntSlice reads a slice of integers from stdin.
func readIntSlice(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.Atoi(readLine())
	}
	return ints
}

// ReadInt64Slice reads a slice of int64s from stdin.
func readInt64Slice(n int) []int64 {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.ParseInt(readLine(), 10, 64)
	}
	return ints
}

// ReadFloat64Slice reads a slice of float64s from stdin.
func readFloat64Slice(n int) []float64 {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		floats[i], _ = strconv.ParseFloat(readLine(), 64)
	}
	return floats
}

// ReadStringSlice reads a slice of strings from stdin.
func readStringSlice(n int) []string {
	strings := make([]string, n)
	for i := 0; i < n; i++ {
		strings[i] = readString()
	}
	return strings
}

// ReadFloatSlice reads a slice of float64s from stdin.
func readFloatSlice(n int) []float64 {
	floats := make([]float64, n)
	for i := 0; i < n; i++ {
		floats[i], _ = strconv.ParseFloat(readLine(), 64)
	}
	return floats
}

// ReadInt64Slice reads a slice of int64s from stdin.
func readInt64Slice(n int) []int64 {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.ParseInt(readLine(), 10, 64)
	}
	return ints
}

// ReadInt64s reads multiple int64s from stdin.
func readInt64s(n int) []int64 {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.ParseInt(readLine(), 10, 64)
	}
	return ints
}

// ReadIntPairSlice reads a slice of pairs of integers from stdin.
func readIntPairSlice(n int) [][2]int {
	pairs := make([][2]int, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b := 0, 0
		fmt.Sscanf(line, "%d %d", &a, &b)
		pairs[i] = [2]int{a, b}
	}
	return pairs
}

// ReadInt64PairSlice reads a slice of pairs of int64s from stdin.
func readInt64PairSlice(n int) [][2]int64 {
	pairs := make([][2]int64, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b := int64(0), int64(0)
		fmt.Sscanf(line, "%d %d", &a, &b)
		pairs[i] = [2]int64{a, b}
	}
	return pairs
}

// ReadFloat64PairSlice reads a slice of pairs of float64s from stdin.
func readFloat64PairSlice(n int) [][2]float64 {
	pairs := make([][2]float64, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b := float64(0), float64(0)
		fmt.Sscanf(line, "%f %f", &a, &b)
		pairs[i] = [2]float64{a, b}
	}
	return pairs
}

// ReadStringPairSlice reads a slice of pairs of strings from stdin.
func readStringPairSlice(n int) [][2]string {
	pairs := make([][2]string, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b := "", ""
		fmt.Sscanf(line, "%s %s", &a, &b)
		pairs[i] = [2]string{a, b}
	}
	return pairs
}

// ReadStringTripletSlice reads a slice of triplets of strings from stdin.
func readStringTripletSlice(n int) [][3]string {
	triplets := make([][3]string, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b, c := "", "", ""
		fmt.Sscanf(line, "%s %s %s", &a, &b, &c)
		triplets[i] = [3]string{a, b, c}
	}
	return triplets
}

// ReadIntTripletSlice reads a slice of triplets of integers from stdin.
func readIntTripletSlice(n int) [][3]int {
	triplets := make([][3]int, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b, c := 0, 0, 0
		fmt.Sscanf(line, "%d %d %d", &a, &b, &c)
		triplets[i] = [3]int{a, b, c}
	}
	return triplets
}

// ReadInt64TripletSlice reads a slice of triplets of int64s from stdin.
func readInt64TripletSlice(n int) [][3]int64 {
	triplets := make([][3]int64, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b, c := int64(0), int64(0), int64(0)
		fmt.Sscanf(line, "%d %d %d", &a, &b, &c)
		triplets[i] = [3]int64{a, b, c}
	}
	return triplets
}

// ReadFloat64TripletSlice reads a slice of triplets of float64s from stdin.
func readFloat64TripletSlice(n int) [][3]float64 {
	triplets := make([][3]float64, n)
	for i := 0; i < n; i++ {
		line := readLine()
		a, b, c := float64(0), float64(0), float64(0)
		fmt.Sscanf(line, "%f %f %f", &a, &b, &c)
		triplets[i] = [3]float64{a, b, c}
	}
	return triplets
}

// ReadIntSliceSlice reads a slice of slices of integers from stdin.
func readIntSliceSlice(n int) [][]int {
	slices := make([][]int, n)
	for i := 0; i < n; i++ {
		slices[i] = readIntSlice(readInt())
	}
	return slices
}

// ReadInt64SliceSlice reads a slice of slices of int64s from stdin.
func readInt64SliceSlice(n int) [][]int64 {
	slices := make([][]int64, n)
	for i := 0; i < n; i++ {
		slices[i] = readInt64Slice(readInt())
	}
	return slices
}

// ReadFloat64SliceSlice reads a slice of slices of float64s from stdin.
func readFloat64SliceSlice(n int) [][]float64 {
	slices := make([][]float64, n)
	for i := 0; i < n; i++ {
		slices[i] = readFloat64Slice(readInt())
	}
	return slices
}

// ReadStringSliceSlice reads a slice of slices of strings from stdin.
func readStringSliceSlice(n int) [][]string {
	slices := make([][]string, n)
	for i := 0; i < n; i++ {
		slices[i] = readStringSlice(readInt())
	}
	return slices
}

// ReadFloatSliceSlice reads a slice of slices of float64s from stdin.
func readFloatSliceSlice(n int) [][]float64 {
	slices := make([][]float64, n)
	for i := 0; i < n; i++ {
		slices[i] = readFloatSlice(readInt())
	}
	return slices
}

// ReadInt64SliceSlice reads a slice of slices of int64s from stdin.
func readInt64SliceSlice(n int) [][]int64 {
	slices := make([][]int64, n)
	for i := 0; i < n; i++ {
		slices[i] = readInt64Slice(readInt())
	}
	return slices
}

// ReadInt64s reads multiple int64s from stdin.
func readInt64s(n int) []int64 {
	ints := make([]int64, n)
	for i := 0; i < n; i++ {
		ints[i], _ = strconv.ParseInt(readLine(), 10, 64)
	}
	return ints
}

// ReadIntPair reads a pair of integers from stdin.
func readIntPair() (int, int) {
	line := readLine()
	i, j := 0, 0
	fmt.Sscanf(line, "%d %d", &i, &j)
	return i, j
}

// ReadInt64Pair reads a pair of int64s from stdin.
func readInt64Pair() (int64, int64) {
	line := readLine()
	i, j := int64(0), int64(0)
	fmt.Sscanf(line, "%d %d", &i, &j)
	return i, j
}

// ReadFloat64Pair reads a pair of float64s from stdin.
func readFloat64Pair() (float64, float64) {
	line := readLine()
	i, j := float64(0), float64(0)
	fmt.Sscanf(line, "%f %f", &i, &j)
	return i, j
}

