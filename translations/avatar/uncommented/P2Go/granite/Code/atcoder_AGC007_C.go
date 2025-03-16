
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

var (
	readBuf  = bytes.NewBuffer(make([]byte, 1024*1024))
	readStr   = func() string {
		scanBuf := bufio.NewScanner(readBuf)
		scanBuf.Buffer(readBuf, 1024*1024)
		scanBuf.Scan()
		return scanBuf.Text()
	}
	readBytes = func() []byte {
		scanBuf := bufio.NewScanner(readBuf)
		scanBuf.Buffer(readBuf, 1024*1024)
		scanBuf.Scan()
		return scanBuf.Bytes()
	}
	readints = func() []int {
		line := readStr()
		var ints []int
		ints, _ = fmt.Sscanf(line, "%d %d %d", &ints[0], &ints[1], &ints[2])
		return ints
	}
)

func main() {
	buf := new(bytes.Buffer)
	readBuf.ReadFrom(bufio.NewReader(os.Stdin))
	ints := readints()
	N, d, x := ints[0], ints[1], ints[2]
	var ret int64
	for N > 0 {
		ret += int64(d) + (N-0.5)*int64(x)
		d = d + (d/N) + (5*x)/(2*N)
		x += 2 * x / N
		N--
	}
	fmt.Println(ret)
}
