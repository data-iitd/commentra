
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := newInputReader(inputStream)
	out := newPrintWriter(outputStream)
	solver := newTask()
	solver.solve(in, out)
	out.close()
}

type task struct {
}

func newTask() *task {
	return &task{}
}

func (t *task) solve(in *inputReader, out *printWriter) {
	n := in.nextInt()
	array := make([]int, 1001)
	for i := 0; i < n; i++ {
		index := in.nextInt()
		array[index]++
	}
	countMax := -1
	for i := 1; i < len(array); i++ {
		if countMax < array[i] {
			countMax = array[i]
		}
	}
	if n%2 == 0 {
		if countMax <= n/2 {
			out.println("YES")
		} else {
			out.println("NO")
		}
	} else {
		if countMax <= n/2+1 {
			out.println("YES")
		} else {
			out.println("NO")
		}
	}
}

type inputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

func newInputReader(stream io.Reader) *inputReader {
	return &inputReader{
		reader: bufio.NewReader(stream),
	}
}

func (in *inputReader) next() string {
	for in.tokenizer == nil || !in.tokenizer.Scan() {
		var err error
		in.tokenizer, err = in.reader.ReadString('\n')
		if err != nil {
			panic(err)
		}
	}
	return in.tokenizer.Text()
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
	return in.nextUint8()
}

func (in *inputReader) nextFloat64() float64 {
	return float64(in.nextFloat32())
}

func (in *inputReader) nextFloat32() float32 {
	return float32(in.nextFloat64())
}

func (in *inputReader) nextString() string {
	return in.next()
}

type printWriter struct {
	writer *bufio.Writer
}

func newPrintWriter(stream io.Writer) *printWriter {
	return &printWriter{
		writer: bufio.NewWriter(stream),
	}
}

func (out *printWriter) println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *printWriter) print(a ...interface{}) {
	fmt.Fprint(out.writer, a...)
}

func (out *printWriter) printf(format string, a ...interface{}) {
	fmt.Fprintf(out.writer, format, a...)
}

func (out *printWriter) close() {
	out.writer.Flush()
}

// 