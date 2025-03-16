
###
# Code
###

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

func Read() (int, error) {
	readLen, err := os.Stdin.Read(readBuf[readPos:])
	readPos = 0
	if err!= nil {
		return 0, err
	}
	if readLen == 0 {
		return 0, fmt.Errorf("end of file")
	}
	return readLen, nil
}

func Write() (int, error) {
	writeFlush = true
	if writeLen == 0 {
		return 0, nil
	}
	n, err := os.Stdout.Write(writeBuf[0:writeLen])
	if err!= nil {
		return n, err
	}
	writeLen = 0
	return n, nil
}

func WriteString(s string) (int, error) {
	writeFlush = true
	return Write([]byte(s)...)
}

func WriteInt(x int) (int, error) {
	return WriteString(fmt.Sprintf("%d", x))
}

func WriteInt64(x int64) (int, error) {
	return WriteString(fmt.Sprintf("%d", x))
}

func WriteFloat(x float64, prec int) (int, error) {
	return WriteString(fmt.Sprintf("%.*f", prec, x))
}

func WriteFlush() (int, error) {
	writeFlush = true
	return Write()
}

func ReadString() (string, error) {
	var s string
	for {
		b, err := ReadByte()
		if err!= nil {
			return s, err
		}
		if b =='' || b == '\n' || b == '\r' || b == '\t' {
			break
		}
		s += string(b)
	}
	return s, nil
}

func ReadInt() (int, error) {
	s, err := ReadString()
	if err!= nil {
		return 0, err
	}
	x, err := fmt.Atoi(s)
	if err!= nil {
		return 0, err
	}
	return x, nil
}

func ReadInt64() (int64, error) {
	s, err := ReadString()
	if err!= nil {
		return 0, err
	}
	x, err := fmt.ParseInt(s, 10, 64)
	if err!= nil {
		return 0, err
	}
	return x, nil
}

func ReadFloat() (float64, error) {
	s, err := ReadString()
	if err!= nil {
		return 0, err
	}
	x, err := fmt.ParseFloat(s, 64)
	if err!= nil {
		return 0, err
	}
	return x, nil
}

func ReadByte() (byte, error) {
	if readPos >= readLen {
		readLen, err := Read()
		if err!= nil {
			return 0, err
		}
		if readLen == 0 {
			return 0, fmt.Errorf("end of file")
		}
	}
	b := readBuf[readPos]
	readPos++
	return b, nil
}

func main() {
	D, G := ReadInt()
	PC := make([][]int, D)
	for i := 0; i < D; i++ {
		p, c := ReadInt(), ReadInt()
		PC[i] = []int{p, c}
	}
	ans := 1000000000
	for i := 0; i < 1<<D; i++ {
		score := 0
		problem := 0
		for j := 0; j < D; j++ {
			if (i>>j)&1 == 1 {
				score += 100*(j+1)*PC[j][0] + PC[j][1]
				problem += PC[j][0]
			}
		}
		if score > G {
			continue
		}
		left := G - score
		for j := 0; j < D; j++ {
			if (i>>j)&1 == 1 {
				continue
			}
			tmp := (left + (100*(j+1) - 1) / (100 * (j + 1)))
			if tmp > PC[j][0] {
				tmp = PC[j][0]
			}
			ans = min(ans, problem+int(tmp))
		}
	}
	WriteInt(ans)
	WriteFlush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

