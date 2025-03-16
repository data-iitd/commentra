
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	fin, _ := os.Open("dataabc155A.txt")
	defer fin.Close()
	_fin := bufio.NewReader(fin)
	fout, _ := os.Create("dataabc155A.out")
	defer fout.Close()
	_fout := bufio.NewWriter(fout)

	a := readi()
	b := readi()

	if a < b {
		for i := 0; i < b; i++ {
			writei(a)
		}
		writeln()
	} else {
		for i := 0; i < a; i++ {
			writei(b)
		}
		writeln()
	}
}

func readc() byte {
	buf := make([]byte, 1)
	_fin.Read(buf)
	return buf[0]
}

func readi() int {
	res := 0
	sign := 1
	ch := readc()
	for ch <='' {
		ch = readc()
	}
	if ch == '-' {
		sign = -1
		ch = readc()
	}
	for ch >= '0' && ch <= '9' {
		res = res*10 + int(ch-'0')
		ch = readc()
	}
	return res * sign
}

func readll() int64 {
	res := int64(0)
	sign := int64(1)
	ch := readc()
	for ch <='' {
		ch = readc()
	}
	if ch == '-' {
		sign = -1
		ch = readc()
	}
	for ch >= '0' && ch <= '9' {
		res = res*10 + int64(ch-'0')
		ch = readc()
	}
	return res * sign
}

func reads(str []byte, maxsize int) int {
	slen := 0
	for {
		buf := make([]byte, 1)
		_fin.Read(buf)
		if buf[0] == '\n' || buf[0] == '\r' {
			break
		}
		str[slen] = buf[0]
		slen++
		if slen == maxsize-1 {
			break
		}
	}
	str[slen] = 0
	return slen
}

func writec(ch byte) {
	_fout.WriteByte(ch)
}

func writecsp(ch byte) {
	writec(ch)
	writec(' ')
}

func writecln(ch byte) {
	writec(ch)
	writec('\n')
}

func writei(num int) {
	if num < 0 {
		writec('-')
		num = -num
	}
	if num == 0 {
		writec('0')
		return
	}
	buf := make([]byte, 10)
	pos := 0
	for num > 0 {
		buf[pos] = byte(num%10 + '0')
		pos++
		num /= 10
	}
	for i := pos - 1; i >= 0; i-- {
		writec(buf[i])
	}
}

func writeisp(num int) {
	writei(num)
	writec(' ')
}

func writellsp(num int64) {
	writei(int(num))
	writec(' ')
}

func writeiln(num int) {
	writei(num)
	writec('\n')
}

func writellln(num int64) {
	writei(int(num))
	writec('\n')
}

func writefln(num float64) {
	fmt.Fprintf(_fout, "%f\n", num)
}

func writes(str string) {
	_fout.WriteString(str)
}

func writesp() {
	writec(' ')
}

func writeln() {
	writec('\n')
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	fin, _ := os.Open("dataabc155A.txt")
	defer fin.Close()
	_fin := bufio.NewReader(fin)
	fout, _ := os.Create("dataabc155A.out")
	defer fout.Close()
	_fout := bufio.NewWriter(fout)

	a := readi()
	b := readi()

	if a < b {
		for i := 0; i < b; i++ {
			writei(a)
		}
		writeln()
	} else {
		for i := 0; i < a; i++ {
			writei(b)
		}
		writeln()
	}
}

