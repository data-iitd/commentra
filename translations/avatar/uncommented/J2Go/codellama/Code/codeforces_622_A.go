
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

var sc = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func solve() {
	position := sc.nextLong()
	nrstSeqStartIndx := 1
	for getValueAtIndex(nrstSeqStartIndx*2) < position {
		nrstSeqStartIndx *= 2
	}
	for getValueAtIndex(nrstSeqStartIndx+1) <= position {
		nrstSeqStartIndx++
	}
	startIndex := getValueAtIndex(nrstSeqStartIndx)
	out.println((position - startIndex) + 1)
}

func getValueAtIndex(index int64) int64 {
	return 1 + ((index - 1) * index / 2)
}

func main() {
	in.init(os.Stdin)
	solve()
	out.close()
}

func (in *in) init(input io.Reader) {
	in.reader = bufio.NewReader(input)
	in.tokenizer = strings.Split(in.reader.ReadString('\n'), " ")
}

func (in *in) next() string {
	for !in.tokenizer.Scan() {
		in.tokenizer = strings.Split(in.reader.ReadString('\n'), " ")
	}
	return in.tokenizer.Text()
}

func (in *in) nextInt() int {
	return int(in.nextLong())
}

func (in *in) nextLong() int64 {
	return int64(in.nextLongLong())
}

func (in *in) nextLongLong() int64 {
	return int64(strconv.ParseInt(in.next(), 10, 64))
}

func (out *out) println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *out) print(a ...interface{}) {
	fmt.Fprint(out.writer, a...)
}

type in struct {
	reader     *bufio.Reader
	tokenizer  *strings.Splitter
	bufferSize int
}

type out struct {
	writer *bufio.Writer
}

