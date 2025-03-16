
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader = bufio.NewReader(os.Stdin)
)

func readInt() int {
	sum := 0
	for {
		c := readByte()
		if c =='' || c == '\n' {
			break
		}
		sum = sum*10 + int(c-'0')
	}
	return sum
}

func readByte() byte {
	for {
		b := byte(0)
		for {
			b, _ = reader.ReadByte()
			if b!='' && b!= '\n' {
				break
			}
		}
		return b
	}
}

func readInt64() int64 {
	sum := int64(0)
	for {
		c := readByte()
		if c =='' || c == '\n' {
			break
		}
		sum = sum*10 + int64(c-'0')
	}
	return sum
}

func readStr() string {
	s := ""
	for {
		c := readByte()
		if c =='' || c == '\n' {
			break
		}
		s += string(c)
	}
	return s
}

func readStrs() []string {
	s := readStr()
	s = s[:len(s)-1]
	return strings.Split(s, " ")
}

func main() {
	N := readInt64()
	A := readInt64()
	B := readInt64()
	k := int64(0)
	if 1 <= N && N <= 1e18 && 0 <= A && 0 <= B && 0 < A+B && A+B <= 1e18 {
		if A+B <= N {
			k = N / (A + B)
			if N-k*(A+B) > A {
				fmt.Println(A*k + (N-k*(A+B)) - (N-(k*(A+B)+A)))
			} else {
				fmt.Println(A * k + (N - k * (A + B)))
			}
		} else if A+B > N && A <= N {
			fmt.Println(A)
		} else {
			fmt.Println(N)
		}
	}
}

