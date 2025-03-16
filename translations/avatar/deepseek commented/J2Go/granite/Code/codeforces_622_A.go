
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const BUFFERSIZE = 512000

var (
	sc  = bufio.NewScanner(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	sc.Buffer([]byte{}, BUFFERSIZE)
	sc.Split(bufio.ScanWords)

	solve()

	out.Flush()
}

func solve() {
	position := nextInt64()
	nrstSeqStartIndx := int64(1)

	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}

	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}

	startIndex := getValueAtIndex(nrstSeqStartIndx)
	fmt.Fprintln(out, position-startIndex+1)
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2)
}

func nextToken() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	i, _ := strconv.Atoi(nextToken())
	return i
}

func nextInt64() int64 {
	i, _ := strconv.ParseInt(nextToken(), 10, 64)
	return i
}

func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(nextToken(), 64)
	return f
}

func nextString() string {
	return nextToken()
}

func nextBytes() []byte {
	return []byte(nextToken())
}

func main() {
	sc.Buffer([]byte{}, BUFFERSIZE)
	sc.Split(bufio.ScanWords)

	solve()

	out.Flush()
}

func solve() {
	position := nextInt64()
	nrstSeqStartIndx := int64(1)

	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}

	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}

	startIndex := getValueAtIndex(nrstSeqStartIndx)
	fmt.Fprintln(out, position-startIndex+1)
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2)
}

func nextToken() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	i, _ := strconv.Atoi(nextToken())
	return i
}

func nextInt64() int64 {
	i, _ := strconv.ParseInt(nextToken(), 10, 64)
	return i
}

func nextFloat64() float64 {
	f, _ := strconv.ParseFloat(nextToken(), 64)
	return f
}

func nextString() string {
	return nextToken()
}

func nextBytes() []byte {
	return []byte(nextToken())
}

