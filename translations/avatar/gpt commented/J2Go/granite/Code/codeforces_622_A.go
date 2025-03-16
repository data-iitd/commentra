
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const (
	BUFFERSIZE = 512000
)

var (
	sc  = bufio.NewScanner(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func solve() {
	position, _ := strconv.ParseInt(sc.Text(), 10, 64)
	nrstSeqStartIndx := int64(1)
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}
	startIndex := getValueAtIndex(nrstSeqStartIndx)
	out.WriteString(strconv.FormatInt((position-startIndex)+1, 10))
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2)
}

func main() {
	sc.Buffer(make([]byte, BUFFERSIZE), BUFFERSIZE)
	sc.Split(bufio.ScanWords)
	solve()
	out.Flush()
}

// END-OF-CODE