
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := newInputReader(inputStream)
	out := newPrintWriter(outputStream)
	a := in.nextInt()
	b := in.nextInt()
	c := in.nextInt()
	d := in.nextInt()
	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d) - c)
	} else {
		l := make([]int, 0)
		l = append(l, a)
		l = append(l, b)
		l = append(l, c)
		l = append(l, d)
		sort.Ints(l)
		fmt.Println(l[2] - l[1])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type inputReader struct {
	reader       *bufio.Reader
	tokenizer    *strings.Reader
	buffer       []byte
	bufferOffset int
	bufferSize   int
}

func newInputReader(stream io.Reader) *inputReader {
	return &inputReader{
		reader: bufio.NewReader(stream),
	}
}

func (in *inputReader) next() string {
	if in.tokenizer == nil {
		in.tokenizer = strings.NewReader(in.readLine())
	}
	return in.tokenizer.ReadString(' ')
}

func (in *inputReader) nextInt() int {
	return int(in.nextInt64())
}

func (in *inputReader) nextInt64() int64 {
	return int64(in.nextInt32())
}

func (in *inputReader) nextInt32() int32 {
	return int32(in.nextInt16())
}

func (in *inputReader) nextInt16() int16 {
	return int16(in.nextInt8())
}

func (in *inputReader) nextInt8() int8 {
	return int8(in.nextUint8())
}

func (in *inputReader) nextUint() uint {
	return uint(in.nextUint64())
}

func (in *inputReader) nextUint64() uint64 {
	return uint64(in.nextUint32())
}

func (in *inputReader) nextUint32() uint32 {
	return uint32(in.nextUint16())
}

func (in *inputReader) nextUint16() uint16 {
	return uint16(in.nextUint8())
}

func (in *inputReader) nextUint8() uint8 {
	return in.nextByte()
}

func (in *inputReader) nextFloat64() float64 {
	return float64(in.nextFloat32())
}

func (in *inputReader) nextFloat32() float32 {
	return float32(in.nextFloat())
}

func (in *inputReader) nextFloat() float64 {
	return float64(in.nextInt())
}

func (in *inputReader) nextString() string {
	return in.next()
}

func (in *inputReader) nextLine() string {
	return in.readLine()
}

func (in *inputReader) readLine() string {
	line, isPrefix, err := in.reader.ReadLine()
	for isPrefix && err == nil {
		line, isPrefix, err = in.reader.ReadLine()
	}
	if err != nil {
		panic(err)
	}
	return string(line)
}

func (in *inputReader) nextBytes() []byte {
	return []byte(in.nextString())
}

type printWriter struct {
	writer *bufio.Writer
}

func newPrintWriter(stream io.Writer) *printWriter {
	return &printWriter{
		writer: bufio.NewWriter(stream),
	}
}

func (out *printWriter) flush() {
	out.writer.Flush()
}

func (out *printWriter) printf(format string, a ...interface{}) {
	fmt.Fprintf(out.writer, format, a...)
}

func (out *printWriter) print(a ...interface{}) {
	fmt.Fprint(out.writer, a...)
}

func (out *printWriter) println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

// 