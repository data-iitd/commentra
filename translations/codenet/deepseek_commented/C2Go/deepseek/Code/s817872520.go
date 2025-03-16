package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const INF = 0x5fffffff

var a [100002]int
var b [100002]int
var buf []byte
var p int

func getint() int {
	n := 0
	if buf[p] == '-' {
		p++
		for p < len(buf) && buf[p] >= '0' {
			n = (n * 10) + int(buf[p] - '0')
			p++
		}
		return -n
	}
	for p < len(buf) && buf[p] >= '0' {
		n = (n * 10) + int(buf[p] - '0')
		p++
	}
	return n
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	fields := strings.Fields(line)
	w := len(fields)
	for i := 1; i <= w; i++ {
		a[i] = getint()
	}
	buf = []byte(line)
	p = 0
	ans := 0
	f := 0
	for i := 1; i <= w; i++ {
		k := a[i]
		if k == 0 {
			f |= 1
		} else if k < 0 {
			f |= 2
		} else {
			ans += k
		}
	}
	if ans == 0 || (f & 1) == 0 {
		fmt.Println(0)
		return
	}
	if (f & 2) == 0 {
		fmt.Println(ans)
		return
	}
	close := 0
	for i := 1; i <= w; i++ {
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close - (i - f) > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF
			} else {
				k := close - (i - f)
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}
	for i := 1; i <= w; i++ {
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close - (f - i) > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF
			} else {
				k := close - (f - i)
				if k < 0 {
					k = 0
				}
				if k > b[i] {
					b[i] = k
				}
			}
		}
	}
	for i := 1; i <= w; i++ {
		if a[i] > 0 {
			if b[i] > a[i] {
				ans += a[i]
			} else {
				ans += b[i]
			}
		}
	}
	fmt.Println(ans)
}
