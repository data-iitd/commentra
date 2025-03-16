
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	ioReader  = bufio.NewReader(os.Stdin)
	ioWriter  = bufio.NewWriter(os.Stdout)
	ioReaders = []*bufio.Reader{ioReader}
	ioWriters = []*bufio.Writer{ioWriter}
)

func main() {
	// Initialization of the dp array
	dp := make([]int, 101000)
	for i := 0; i < 101000; i++ {
		dp[i] = 1 << 30
	}
	dp[0] = 0
	// input
	N, K := readInt(), readInt()
	h := make([]int, N)
	for i := 0; i < N; i++ {
		h[i] = readInt()
	}

	// Dynamic Programming Loop
	for i := 0; i < N; i++ {
		for j := 1; j <= K; j++ {
			dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]))
		}
	}

	// Output
	fmt.Fprintln(ioWriter, dp[N-1])
	ioWriter.Flush()
}

func read() (x int) {
	ioReader.Scan()
	for _, b := range ioReader.Bytes() {
		x = x*10 + int(b-'0')
	}
	return
}

func readInt() (x int) {
	ioReader.Scan()
	x = 0
	for _, b := range ioReader.Bytes() {
		x = x*10 + int(b-'0')
	}
	return
}

func readInt64() (x int64) {
	ioReader.Scan()
	x = 0
	for _, b := range ioReader.Bytes() {
		x = x*10 + int64(b-'0')
	}
	return
}

func readFloat64() (x float64) {
	ioReader.Scan()
	x, _ =...