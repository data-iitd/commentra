
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	N int
	i int64
	c int
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	N = nextInt()
	i = 357
	for i <= int64(N) {
		s := strconv.FormatInt(i, 10)
		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
			c++
		}
		var sb strings.Builder
		f := false
		for j := len(s) - 1; j >= 0; j-- {
			a := s[j]
			if f {
				sb.WriteByte(a)
			} else {
				switch a {
				case '3':
					sb.WriteByte('5')
					f = true
				case '5':
					sb.WriteByte('7')
					f = true
				default:
					sb.WriteByte('3')
				}
			}
		}
		if!f {
			sb.WriteByte('3')
		}
		s2 := sb.String()
		i, _ = strconv.ParseInt(s2, 10, 64)
	}
	fmt.Println(c)
}

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func nextBytes() []byte {
	scanner.Scan()
	return scanner.Bytes()
}

func nextInt() int {
	scanner.Scan()
	nextInt, err := strconv.Atoi(scanner.Text())
	if err!= nil {
		panic(err)
	}
	return nextInt
}

func nextInt64() int64 {
	scanner.Scan()
	nextInt64, err := strconv.ParseInt(scanner.Text(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return nextInt64
}

func nextFloat32() float32 {
	scanner.Scan()
	nextFloat32, err := strconv.ParseFloat(scanner.Text(), 32)
	if err!= nil {
		panic(err)
	}
	return float32(nextFloat32)
}

func nextFloat64() float64 {
	scanner.Scan()
	nextFloat64, err := strconv.ParseFloat(scanner.Text(), 64)
	if err!= nil {
		panic(err)
	}
	return nextFloat64
}

// 