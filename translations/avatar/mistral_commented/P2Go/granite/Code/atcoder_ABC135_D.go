
```go
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	readBuf  [1024]byte
	strBuf    [200000]byte
	strIdx    int
	readPtr   int
	strPtr    int
	writePtr   int
	bufPtr     int
	bufLen     int
	resultBuf [200000]byte
)

func Read() (result string) {
	readPtr = 0
	strPtr = 0
	for readBuf[readPtr]!= '\n' && readPtr < len(readBuf) {
		readPtr++
	}
	readPtr++
	result = string(readBuf[0:readPtr])
	copy(readBuf[0:], readBuf[readPtr:len(readBuf)])
	readPtr = 0
	return
}

func ReadInt() (result int) {
	result = 0
	sign := 1
	if strBuf[strPtr] == '-' {
		sign = -1
		strPtr++
	}
	for strBuf[strPtr] >= '0' && strBuf[strPtr] <= '9' {
		result = result*10 + int(strBuf[strPtr]-'0')
		strPtr++
	}
	result *= sign
	return
}

func WriteInt(result int) {
	writePtr = 0
	if result < 0 {
		bufPtr++
		strBuf[bufPtr] = '-'
		result = -result
	}
	for result > 0 {
		bufPtr++
		strBuf[bufPtr] = byte(result%10 + '0')
		result /= 10
	}
	for bufPtr > 0 {
		bufPtr--
		readBuf[writePtr] = strBuf[bufPtr]
		writePtr++
	}
	bufLen = writePtr
}

func WriteString(result string) {
	writePtr = 0
	for _, char := range result {
		bufPtr++
		strBuf[bufPtr] = byte(char)
	}
	bufLen = writePtr
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	var s string
	var dp [200000][13]int
	s = Read()
	n = len(s)
	if n == 1 {
		if s[0] == '5' || s[0] == '?' {
			WriteInt(1)
		} else {
			WriteInt(0)
		}
		fmt.Println(string(readBuf[0:bufLen]))
		return
	}
	for i := 0; i < n; i++ {
		if i == 0 {
			if s[i]!= '?' {
				dp[i][int(s[i]-'0')]++
			} else {
				for j := 0; j < 10; j++ {
					dp[i][j]++
				}
			}
		} else {
			if s[i]!= '?' {
				for j := 0; j < 13; j++ {
					dp[i][(j*10+int(s[i]-'0'))%13] += dp[i-1][j]
				}
			} else {
				for j := 0; j < 10; j++ {
					for k := 0; k < 13; k++ {
						dp[i][(k*10+j)%13] += dp[i-1][k]
					}
				}
				for k := 0; k < 13; k++ {
					dp[i][k] %= 100000007
				}
			}
		}
	}
	WriteInt(dp[n-1][5])
	fmt.Println(string(readBuf[0:bufLen]))
}

