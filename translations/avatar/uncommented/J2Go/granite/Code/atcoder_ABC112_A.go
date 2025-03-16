
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
	var n int
	var strs []string
	var err error
	var reader *bufio.Reader
	if reader == nil {
		reader = bufio.NewReader(os.Stdin)
	}
	if n, err = strconv.Atoi(strings.TrimSpace(readLine(reader))); err!= nil {
		panic(err)
	}
	if n == 1 {
		fmt.Println("Hello World")
	} else {
		if strs, err = readLineSlice(reader, 2); err!= nil {
			panic(err)
		}
		fmt.Println( MustInt(strs[0]) + MustInt(strs[1]) )
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	if err!= nil {
		panic(err)
	}
	return string(str)
}

func readLineSlice(reader *bufio.Reader, n int) ([]string, error) {
	var strs []string
	for i := 0; i < n; i++ {
		str, _, err := reader.ReadLine()
		if err == io.EOF {
			break
		}
		if err!= nil {
			return nil, err
		}
		strs = append(strs, string(str))
	}
	return strs, nil
}

func MustInt(str string) int {
	i, err := strconv.Atoi(str)
	if err!= nil {
		panic(err)
	}
	return i
}

