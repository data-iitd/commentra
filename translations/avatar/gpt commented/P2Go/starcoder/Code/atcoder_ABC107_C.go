package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// ReadInt reads a single integer from stdin.
func ReadInt() int {
	var n int
	fmt.Scanf("%d", &n)
	return n
}

// ReadInts reads multiple integers from stdin.
func ReadInts() []int {
	var ns []int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		ns = append(ns, n)
	}
	return ns
}

// ReadInt64s reads multiple integers from stdin.
func ReadInt64s() []int64 {
	var ns []int64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		ns = append(ns, n)
	}
	return ns
}

// ReadFloat64s reads multiple float64s from stdin.
func ReadFloat64s() []float64 {
	var ns []float64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n, _ := strconv.ParseFloat(scanner.Text(), 64)
		ns = append(ns, n)
	}
	return ns
}

// ReadStrings reads multiple strings from stdin.
func ReadStrings() []string {
	var ss []string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		ss = append(ss, scanner.Text())
	}
	return ss
}

// ReadString reads a single string from stdin.
func ReadString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// ReadFloat reads a single float64 from stdin.
func ReadFloat() float64 {
	var n float64
	fmt.Scanf("%f", &n)
	return n
}

// ReadInt64 reads a single int64 from stdin.
func ReadInt64() int64 {
	var n int64
	fmt.Scanf("%d", &n)
	return n
}

// ReadInt32 reads a single int32 from stdin.
func ReadInt32() int32 {
	var n int32
	fmt.Scanf("%d", &n)
	return n
}

// ReadInt16 reads a single int16 from stdin.
func ReadInt16() int16 {
	var n int16
	fmt.Scanf("%d", &n)
	return n
}

// ReadInt8 reads a single int8 from stdin.
func ReadInt8() int8 {
	var n int8
	fmt.Scanf("%d", &n)
	return n
}

// ReadByte reads a single byte from stdin.
func ReadByte() byte {
	var n byte
	fmt.Scanf("%c", &n)
	return n
}

// ReadRune reads a single rune from stdin.
func ReadRune() rune {
	var n rune
	fmt.Scanf("%c", &n)
	return n
}

// ReadBool reads a single bool from stdin.
func ReadBool() bool {
	var n bool
	fmt.Scanf("%t", &n)
	return n
}

// WriteInt writes a single integer to stdout.
func WriteInt(n int) {
	fmt.Printf("%d\n", n)
}

// WriteInt64 writes a single int64 to stdout.
func WriteInt64(n int64) {
	fmt.Printf("%d\n", n)
}

// WriteInt32 writes a single int32 to stdout.
func WriteInt32(n int32) {
	fmt.Printf("%d\n", n)
}

// WriteInt16 writes a single int16 to stdout.
func WriteInt16(n int16) {
	fmt.Printf("%d\n", n)
}

// WriteInt8 writes a single int8 to stdout.
func WriteInt8(n int8) {
	fmt.Printf("%d\n", n)
}

// WriteByte writes a single byte to stdout.
func WriteByte(n byte) {
	fmt.Printf("%c\n", n)
}

// WriteRune writes a single rune to stdout.
func WriteRune(n rune) {
	fmt.Printf("%c\n", n)
}

// WriteBool writes a single bool to stdout.
func WriteBool(n bool) {
	fmt.Printf("%t\n", n)
}

// WriteFloat64 writes a single float64 to stdout.
func WriteFloat64(n float64) {
	fmt.Printf("%f\n", n)
}

// WriteString writes a single string to stdout.
func WriteString(s string) {
	fmt.Printf("%s\n", s)
}

// WriteFloat writes a single float to stdout.
func WriteFloat(n float32) {
	fmt.Printf("%f\n", n)
}

// WriteSlice writes a slice of integers to stdout.
func WriteSlice(s []int) {
	fmt.Printf("%v\n", s)
}

// WriteSliceString writes a slice of strings to stdout.
func WriteSliceString(s []string) {
	fmt.Printf("%v\n", s)
}

// WriteSliceFloat64 writes a slice of float64s to stdout.
func WriteSliceFloat64(s []float64) {
	fmt.Printf("%v\n", s)
}

// WriteMatrix writes a matrix of integers to stdout.
func WriteMatrix(m [][]int) {
	for _, row := range m {
		fmt.Printf("%v\n", row)
	}
}

// WriteMatrixString writes a matrix of strings to stdout.
func WriteMatrixString(m [][]string) {
	for _, row := range m {
		fmt.Printf("%v\n", row)
	}
}

// WriteMatrixFloat64 writes a matrix of float64s to stdout.
func WriteMatrixFloat64(m [][]float64) {
	for _, row := range m {
		fmt.Printf("%v\n", row)
	}
}

// ReadLine reads a line from stdin.
func ReadLine() string {
	var line string
	fmt.Scanf("%s", &line)
	return line
}

// ReadLines reads multiple lines from stdin.
func ReadLines() []string {
	var lines []string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}
	return lines
}

// ReadWord reads a single word from stdin.
func ReadWord() string {
	var word string
	fmt.Scanf("%s", &word)
	return word
}

// ReadWords reads multiple words from stdin.
func ReadWords() []string {
	var words []string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		words = append(words, scanner.Text())
	}
	return words
}

// ReadMap reads a single map from stdin.
func ReadMap() map[string]string {
	var m map[string]string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = make(map[string]string)
		for _, kv := range strings.Split(scanner.Text(), " ") {
			k, v := strings.Split(kv, ":")
			m[k] = v
		}
	}
	return m
}

// ReadMapInt reads a single map of integers from stdin.
func ReadMapInt() map[string]int {
	var m map[string]int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = make(map[string]int)
		for _, kv := range strings.Split(scanner.Text(), " ") {
			k, v := strings.Split(kv, ":")
			m[k] = int(v)
		}
	}
	return m
}

// ReadMapInt64 reads a single map of int64s from stdin.
func ReadMapInt64() map[string]int64 {
	var m map[string]int64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = make(map[string]int64)
		for _, kv := range strings.Split(scanner.Text(), " ") {
			k, v := strings.Split(kv, ":")
			m[k] = int64(v)
		}
	}
	return m
}

// ReadMapFloat64 reads a single map of float64s from stdin.
func ReadMapFloat64() map[string]float64 {
	var m map[string]float64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = make(map[string]float64)
		for _, kv := range strings.Split(scanner.Text(), " ") {
			k, v := strings.Split(kv, ":")
			m[k] = float64(v)
		}
	}
	return m
}

// ReadMapBool reads a single map of bools from stdin.
func ReadMapBool() map[string]bool {
	var m map[string]bool
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = make(map[string]bool)
		for _, kv := range strings.Split(scanner.Text(), " ") {
			k, v := strings.Split(kv, ":")
			m[k] = v == "true"
		}
	}
	return m
}

// ReadMatrix reads a single matrix from stdin.
func ReadMatrix() [][]int {
	var m [][]int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = append(m, ReadInts())
	}
	return m
}

// ReadMatrixString reads a single matrix of strings from stdin.
func ReadMatrixString() [][]string {
	var m [][]string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = append(m, ReadStrings())
	}
	return m
}

// ReadMatrixFloat64 reads a single matrix of float64s from stdin.
func ReadMatrixFloat64() [][]float64 {
	var m [][]float64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = append(m, ReadFloat64s())
	}
	return m
}

// ReadMatrixInt64 reads a single matrix of int64s from stdin.
func ReadMatrixInt64() [][]int64 {
	var m [][]int64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = append(m, ReadInt64s())
	}
	return m
}

// ReadMatrixInt reads a single matrix of ints from stdin.
func ReadMatrixInt() [][]int {
	var m [][]int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = append(m, ReadInts())
	}
	return m
}

// ReadMatrixBool reads a single matrix of bools from stdin.
func ReadMatrixBool() [][]bool {
	var m [][]bool
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		m = append(m, ReadBools())
	}
	return m
}

// ReadBools reads a single bool slice from stdin.
func ReadBools() []bool {
	var bs []bool
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		bs = append(bs, ReadBool())
	}
	return bs
}

// ReadFloat64s reads a single float64 slice from stdin.
func ReadFloat64s() []float64 {
	var fs []float64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		fs = append(fs, ReadFloat64())
	}
	return fs
}

// ReadInts reads a single int slice from stdin.
func ReadInts() []int {
	var ns []int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		ns = append(ns, ReadInt())
	}
	return ns
}

// ReadInt64s reads a single int64 slice from stdin.
func ReadInt64s() []int64 {
	var ns []int64
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		ns = append(ns, ReadInt64())
	}
	return ns
}

// ReadStrings reads a single string slice from stdin.
func ReadStrings() []string {
	var ss []string
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		ss = append(ss, ReadString())
	}
	return ss
}

// ReadString reads a single string from stdin.
func ReadString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// ReadFloat reads a single float64 from stdin.
func ReadFloat() float64 {
	var n float64
	fmt.Scanf("%f", &n)
	return n
}

// ReadInt64 reads a single int64 from stdin.
func ReadInt64() int64 {
	var n int64
	fmt.Scanf("%d", &n)
	return n
}

// ReadInt32 reads a single int32 from stdin.
func ReadInt32() int32 {
	var n int32
	fmt.Scanf("%d", &n)
	return n
}

// ReadInt16 reads a single int16 from stdin.
func ReadInt16() int16 {
	var n int16
	fmt.Scanf("%d", &n)
	return n
}

// ReadInt8 reads a single int8 from stdin.
func ReadInt8() int8 {
	var n int8
	fmt.Scanf("%d", &n)
	return n
}

// ReadByte reads a single byte from stdin.
func ReadByte() byte {
	var n byte
	fmt.Scanf("%c", &n)
	return n
}

// ReadRune reads a single rune from stdin.
func ReadRune() rune {
	var n rune
	fmt.Scanf("%c", &n)
	return n
}

// ReadBool reads a single bool from stdin.
func ReadBool() bool {
	var n bool
	fmt.Scanf("%t", &n)
	return n
}

// WriteInt writes a single integer to stdout.
func WriteInt(n int) {
	fmt.Printf("%d\n", n)
}

// WriteInt64 writes a single int6