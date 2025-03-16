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
	in := NewInputReader(inputStream)
	out := bufio.NewWriter(outputStream)
	solver := new(Task)
	solver.solve(in, out)
	out.Flush()
}

type Task struct{}

func (solver *Task) solve(in *InputReader, out *bufio.Writer) {
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
			out.WriteString("YES\n")
		} else {
			out.WriteString("NO\n")
		}
	} else {
		if countMax <= n/2+1 {
			out.WriteString("YES\n")
		} else {
			out.WriteString("NO\n")
		}
	}
}

type InputReader struct {
	reader *bufio.Reader
	tokenizer *strings.Tokenizer
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		reader: bufio.NewReader(stream),
	}
}

func (in *InputReader) next() string {
	if in.tokenizer == nil || !in.tokenizer.Scan() {
		in.tokenizer = strings.NewTokenizer(in.reader.ReadString('\n'))
	}
	return in.tokenizer.Token().String()
}

func (in *InputReader) nextInt() int {
	return int(in.nextInt64())
}

func (in *InputReader) nextInt64() int64 {
	return int64(in.nextInt64AsFloat64())
}

func (in *InputReader) nextInt64AsFloat64() float64 {
	return float64(in.next())
}

func (in *InputReader) nextFloat() float64 {
	return float64(in.nextFloat64())
}

func (in *InputReader) nextFloat64() float64 {
	return float64(in.next())
}

func (in *InputReader) nextString() string {
	return in.next()
}

func (in *InputReader) nextLine() string {
	str := ""
	for {
		str += in.next()
		if str[len(str)-1] == '\n' {
			return str[:len(str)-1]
		}
	}
}

