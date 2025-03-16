package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

const BUFFERSIZE = 512000

var sc = bufio.NewScanner(bufio.NewReader(os.Stdin))
var out = bufio.NewWriter(os.Stdout)

func solve() {
	var position int64
	sc.Scan()
	fmt.Sscan(sc.Text(), &position)
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

func main() {
	sc.Split(bufio.ScanWords)
	solve()
	out.Flush()
}

