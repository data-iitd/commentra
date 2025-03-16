package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const BUFFERSIZE = 512000

// Step 2: Define the Scanner and PrintWriter for input and output operations.
var sc = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

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
	fmt.Fprintln(out, (position-startIndex)+1)
}

// Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
func getValueAtIndex(index int64) int64 {
	return 1 + ((index-1)*index)/2
}

// Step 5: Implement the main method to initialize the input and call the solve method.
func main() {
	// Step 7: Initialize the input reader for the in class.
	in.Init(os.Stdin)
	solve()
	out.Flush()
}

// Step 7: Implement the in class to handle input operations.
type in struct {
	reader *bufio.Reader
	tokenizer *strings.Reader
}

func (in *in) Init(input io.Reader) {
	in.reader = bufio.NewReader(input)
	in.tokenizer = &strings.Reader{}
}

func (in *in) Next() string {
	for !in.tokenizer.Scan() {
		in.tokenizer = strings.NewReader(in.reader.Text())
	}
	return in.tokenizer.Text()
}

func (in *in) NextInt() int {
	return int(in.NextInt64())
}

func (in *in) NextInt64() int64 {
	i, _ := strconv.ParseInt(in.Next(), 10, 64)
	return i
}

func (in *in) NextFloat() float64 {
	f, _ := strconv.ParseFloat(in.Next(), 64)
	return f
}

func (in *in) NextFloat64() float64 {
	return in.NextFloat()
}

func (in *in) NextString() string {
	return in.Next()
}

func (in *in) NextLine() string {
	return in.reader.Text()
}

// 