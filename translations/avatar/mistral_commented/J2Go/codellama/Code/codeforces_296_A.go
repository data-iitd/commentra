
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
    in := InputReader{inputStream}
    out := bufio.NewWriter(outputStream)
    solver := Task{}
    solver.solve(in, out)
    out.Flush()
}

type Task struct{}

func (solver Task) solve(in InputReader, out *bufio.Writer) {
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
}

func (in InputReader) next() string {
    var tokenizer *strings.StringTokenizer
    for tokenizer == nil || !tokenizer.HasMoreTokens() {
        var err error
        var line string
        if line, err = in.reader.ReadString('\n'); err != nil {
            if err == io.EOF {
                return ""
            }
            panic(err)
        }
        tokenizer = strings.NewTokenizer(line)
    }
    return tokenizer.NextToken()
}

func (in InputReader) nextInt() int {
    return int(in.nextInt64())
}

func (in InputReader) nextInt64() int64 {
    return int64(in.nextInt64())
}

func (in InputReader) nextFloat() float64 {
    return float64(in.nextFloat64())
}

func (in InputReader) nextFloat64() float64 {
    return float64(in.nextFloat64())
}

func (in InputReader) nextLine() string {
    var str string
    var err error
    if str, err = in.reader.ReadString('\n'); err != nil {
        if err == io.EOF {
            return ""
        }
        panic(err)
    }
    return str
}

