package main

import (
	"bufio"
	"fmt"
	"os"
)

const BUFFERSIZE = 512000

func main() {
	scanner := bufio.NewScanner(bufio.NewReaderSize(os.Stdin, BUFFERSIZE))
	scanner.Scan()
	var position int64
	fmt.Sscan(scanner.Text(), &position)
	solve(position)
}

func solve(position int64) {
	nrstSeqStartIndx := int64(1)
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}
	startIndex := getValueAtIndex(nrstSeqStartIndx)
	fmt.Println((position - startIndex) + 1)
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2)
}
