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

var (
	sc  *bufio.Scanner
	out *bufio.Writer
)

func init() {
	sc = bufio.NewScanner(bufio.NewReader(os.Stdin))
	sc.Buffer(make([]byte, BUFFERSIZE), BUFFERSIZE)
	out = bufio.NewWriter(os.Stdout)
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index-1)*index/2)
}

func solve() {
	var position int64
	fmt.Scan(&position)
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

func main() {
	solve()
	out.Flush()
}

