package main

import (
 "bufio"
 "fmt"
 "os"
)

const BUFFER_SIZE = 512000

var sc *bufio.Scanner = bufio.NewScanner(bufio.NewReader(os.Stdin))
var out *bufio.Writer = bufio.NewWriter(os.Stdout)

func main() {
 defer out.Flush()
 init()
 solve()
}

func init() {
 sc.Split(bufio.ScanWords)
 sc.Buffer(make([]byte, BUFFER_SIZE), BUFFER_SIZE)
}

func solve() {
 position := nextLong()
 solveHelper(position)
}

func solveHelper(position int64) {
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
 return 1 + (index-1)*index/2
}

func nextLong() int64 {
 sc.Scan()
 num, _ := sc.Text(), sc.Err()
 if sc.Err() != nil {
 panic(sc.Err())
 }
 result, _ := strconv.ParseInt(num, 10, 64)
 return result
}

