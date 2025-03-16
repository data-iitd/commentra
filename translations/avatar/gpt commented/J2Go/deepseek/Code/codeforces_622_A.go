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

var sc *bufio.Scanner = bufio.NewScanner(bufio.NewReader(os.Stdin))
var out io.Writer = bufio.NewWriter(os.Stdout)

func solve() {
	position := nextLong()
	nrstSeqStartIndx := int64(1)

	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}

	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}

	startIndex := getValueAtIndex(nrstSeqStartIndx)
	fmt.Fprintln(out, (position-startIndex)+1)
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index-1)*index/2)
}

func nextLong() int64 {
	sc.Scan()
	num, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return num
}

func main() {
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 0, BUFFERSIZE), BUFFERSIZE)
	defer out.(*bufio.Writer).Flush()

	solve()
}

