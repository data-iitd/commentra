
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	readBuf  [1024]byte
	readPos   int
	readLen   int
	writeBuf  [1024]byte
	writePos  int
	writeLen  int
	writeFlush bool
)

func init() {
	readPos = 0
	readLen = 0
	writePos = 0
	writeLen = 0
	writeFlush = false
}

func Read() []byte {
	readLen = 0
	for {
		readBuf[readLen] = byte(getChar())
		readLen++
		if readBuf[readLen-1] == '\n' {
			break
		}
	}
	return readBuf[:readLen]
}

func ReadInt() int {
	return int(readInt64())
}

func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64())
}

func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64())
}

func ReadInt6() (int64, int64) {
	return readInt64(), readInt64()
}

func ReadFloat64() float64 {
	var f float64
	fmt.Sscanf(readToken(), "%f", &f)
	return f
}

func ReadString() string {
	return readToken()
}

func readToken() string {
	if readPos == readLen {
		readLen = 0
		readPos = 0
		readBuf = readBuf[:cap(readBuf)]
		n, err := os.Stdin.Read(readBuf)
		if err!= nil {
			panic(err)
		}
		if n == 0 {
			panic("input end")
		}
		readBuf = readBuf[:n]
	}
	pos := readPos
	for readBuf[pos] =='' || readBuf[pos] == '\n' {
		pos++
	}
	readPos = pos
	for readPos < readLen && readBuf[readPos]!='' && readBuf[readPos]!= '\n' {
		readPos++
	}
	res := string(readBuf[pos:readPos])
	return res
}

func readInt64() int64 {
	if readPos == readLen {
		readLen = 0
		readPos = 0
		readBuf = readBuf[:cap(readBuf)]
		n, err := os.Stdin.Read(readBuf)
		if err!= nil {
			panic(err)
		}
		if n == 0 {
			panic("input end")
		}
		readBuf = readBuf[:n]
	}
	var res int64
	sign := 1
	if readBuf[readPos] == '-' {
		sign = -1
		readPos++
	}
	for readPos < readLen && readBuf[readPos] >= '0' && readBuf[readPos] <= '9' {
		res = res*10 + int64(readBuf[readPos]-'0')
		readPos++
	}
	res *= int64(sign)
	return res
}

func WriteInt(x int) {
	writeBuf = append(writeBuf, []byte(fmt.Sprintf("%d", x))...)
	writeFlush = true
}

func WriteString(s string) {
	writeBuf = append(writeBuf, s...)
	writeFlush = true
}

func WriteStringln(s string) {
	writeBuf = append(writeBuf, s...)
	writeBuf = append(writeBuf, '\n')
	writeFlush = true
}

func WriteIntln(x int) {
	writeBuf = append(writeBuf, []byte(fmt.Sprintf("%d\n", x))...)
	writeFlush = true
}

func WriteInt64(x int64) {
	writeBuf = append(writeBuf, []byte(fmt.Sprintf("%d", x))...)
	writeFlush = true
}

func WriteInt64ln(x int64) {
	writeBuf = append(writeBuf, []byte(fmt.Sprintf("%d\n", x))...)
	writeFlush = true
}

func WriteFloat64(x float64) {
	writeBuf = append(writeBuf, []byte(fmt.Sprintf("%f", x))...)
	writeFlush = true
}

func WriteFloat64ln(x float64) {
	writeBuf = append(writeBuf, []byte(fmt.Sprintf("%f\n", x))...)
	writeFlush = true
}

func flush() {
	os.Stdout.Write(writeBuf)
	writeBuf = writeBuf[:0]
	writeFlush = false
}

func main() {
	N := ReadInt()
	K := ReadInt()
	graph := make([][]int, N)
	for i := 0; i < N; i++ {
		graph[i] = make([]int, 0)
	}
	for i := 0; i < N-1; i++ {
		a := ReadInt() - 1
		b := ReadInt() - 1
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	mod := int64(1e9 + 7)
	var dfs func(fro int, to int, f int) int64
	dfs = func(fro int, to int, f int) int64 {
		caseNum := int64(f)
		colorNum := int64(K - 1)
		if f == K {
			colorNum = int64(K - 2)
		}
		for _, u := range graph[fro] {
			if u == to {
				continue
			}
			pat := dfs(u, fro, int(colorNum))
			if pat == 0 {
				caseNum = 0
				break
			}
			caseNum = caseNum * pat % mod
			colorNum--
		}
		return caseNum
	}
	ans := dfs(0, -1, K)
	WriteIntln(int(ans))
	flush()
}

