package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Step 2: Define the Scanner and PrintWriter for input and output operations.
var (
	sc = bufio.NewScanner(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

// Step 3: Implement the solve method to find the position of a given value in a sequence.
func solve() {
	position, _ := strconv.ParseInt(sc.Text(), 10, 64)
	nrstSeqStartIndx := int64(1)

	// Step 4: Find the starting index of the sequence where the position might be located.
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}

	// Step 4: Find the exact position within the sequence.
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}

	startIndex := getValueAtIndex(nrstSeqStartIndx)
	out.WriteString(fmt.Sprintf("%d\n", position-startIndex+1))
}

// Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
func getValueAtIndex(index int64) int64 {
	return 1 + ((index-1)*index/2)
}

// Step 5: Implement the main method to initialize the input and call the solve method.
func main() {
	// Step 7: Initialize the input reader for the in class.
	in.init(os.Stdin)
	solve()
	out.Flush()
}

// Step 7: Implement the in class to handle input operations.
type in struct {
	reader *bufio.Reader
	tokenizer *bufio.Scanner
}

func (i *in) init(input io.Reader) {
	i.reader = bufio.NewReader(input)
	i.tokenizer = bufio.NewScanner(i.reader)
}

func (i *in) next() string {
	i.tokenizer.Scan()
	return i.tokenizer.Text()
}

func (i *in) nextInt() int {
	i.tokenizer.Scan()
	n, _ := strconv.Atoi(i.tokenizer.Text())
	return n
}

func (i *in) nextLong() int64 {
	i.tokenizer.Scan()
	n, _ := strconv.ParseInt(i.tokenizer.Text(), 10, 64)
	return n
}

func (i *in) nextFloat() float64 {
	i.tokenizer.Scan()
	n, _ := strconv.ParseFloat(i.tokenizer.Text(), 64)
	return n
}

func (i *in) nextString() string {
	i.tokenizer.Scan()
	return i.tokenizer.Text()
}

func (i *in) nextStrings(n int) []string {
	var ss []string
	for _ = range ss {
		ss = append(ss, i.next())
	}
	return ss
}

func (i *in) nextIntSlice(n int) []int {
	var ss []int
	for _ = range ss {
		ss = append(ss, i.nextInt())
	}
	return ss
}

func (i *in) nextInt64Slice(n int) []int64 {
	var ss []int64
	for _ = range ss {
		ss = append(ss, i.nextLong())
	}
	return ss
}

func (i *in) nextFloat64Slice(n int) []float64 {
	var ss []float64
	for _ = range ss {
		ss = append(ss, i.nextFloat())
	}
	return ss
}

func (i *in) nextRunes(n int) []rune {
	var ss []rune
	for _ = range ss {
		ss = append(ss, i.next()[0])
	}
	return ss
}

func (i *in) nextBool() bool {
	i.tokenizer.Scan()
	s := i.tokenizer.Text()
	if s == "true" {
		return true
	}
	return false
}

// Step 8: Implement the out class to handle output operations.
type out struct {
	writer *bufio.Writer
}

func (o *out) init(output io.Writer) {
	o.writer = bufio.NewWriter(output)
}

func (o *out) flush() {
	o.writer.Flush()
}

func (o *out) println(a...interface{}) (int, error) {
	return fmt.Fprintln(o.writer, a...)
}

func (o *out) printf(format string, a...interface{}) (int, error) {
	return fmt.Fprintf(o.writer, format, a...)
}

func (o *out) printStrings(ss []string) (int, error) {
	return fmt.Fprint(o.writer, strings.Join(ss, " "))
}

func (o *out) printInts(xs []int) (int, error) {
	return o.printStrings(intsToStrings(xs))
}

func (o *out) printInt64s(xs []int64) (int, error) {
	return o.printStrings(int64sToStrings(xs))
}

func (o *out) printFloat64s(xs []float64) (int, error) {
	return o.printStrings(float64sToStrings(xs))
}

func (o *out) printRunes(xs []rune) (int, error) {
	return o.printStrings(runesToStrings(xs))
}

func (o *out) printBools(xs []bool) (int, error) {
	return o.printStrings(boolsToStrings(xs))
}

func intsToStrings(xs []int) []string {
	var ss []string
	for _, x := range xs {
		ss = append(ss, strconv.Itoa(x))
	}
	return ss
}

func int64sToStrings(xs []int64) []string {
	var ss []string
	for _, x := range xs {
		ss = append(ss, strconv.FormatInt(x, 10))
	}
	return ss
}

func float64sToStrings(xs []float64) []string {
	var ss []string
	for _, x := range xs {
		ss = append(ss, strconv.FormatFloat(x, 'f', -1, 64))
	}
	return ss
}

func runesToStrings(xs []rune) []string {
	var ss []string
	for _, x := range xs {
		ss = append(ss, string(x))
	}
	return ss
}

func boolsToStrings(xs []bool) []string {
	var ss []string
	for _, x := range xs {
		if x {
			ss = append(ss, "true")
		} else {
			ss = append(ss, "false")
		}
	}
	return ss
}

// Step 9: Implement the in class to handle input operations.
var in = in{}

// Step 9: Implement the out class to handle output operations.
var out = out{}

