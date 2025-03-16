
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
		readLen += copy(readBuf[readLen:], readBuf[0:readPos])
		readPos = 0
		n, err := os.Stdin.Read(readBuf[readLen:])
		if err!= nil {
			panic(err)
		}
		readLen += n
		if readLen < 32 {
			continue
		}
		break
	}
	return readBuf[0:readLen]
}

func ReadInt() int {
	return int(Read()[0] - '0')
}

func ReadString() string {
	return string(Read())
}

func Write(buf []byte) {
	writeLen += copy(writeBuf[writeLen:], buf)
	if writeLen >= 32768 {
		flush()
	}
}

func flush() {
	os.Stdout.Write(writeBuf[0:writeLen])
	writeLen = 0
}

func main() {
	const MOD = 100000007
	N := ReadInt()
	A := ReadInt()
	B := ReadInt()
	rep := N / (A + B)
	ans := int64(rep) * int64(A)
	res := N - rep*(A+B)
	ans += int64(min(res, A))
	Write([]byte(fmt.Sprintf("%d\n", ans)))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

