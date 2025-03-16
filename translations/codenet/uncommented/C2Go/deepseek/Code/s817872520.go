package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const INF = 0x5fffffff

var a [100002]int
var b [100002]int

func getint() int {
	var n int
	for *p == '-' {
		p++
		for *p >= '0' {
			n = n*10 + int(*p-'0')
			p++
		}
		return -n
	}
	for *p >= '0' {
		n = n*10 + int(*p-'0')
		p++
	}
	return n
}

func main() {
	var w, i, k, f, close, ans int
	var buf = make([]byte, 700002)
	p := buf

	fmt.Scan(&w)
	bufio.NewReader(os.Stdin).ReadBytes('\n')
	for i = 1; i <= w; i++ {
		k = getint()
		a[i] = k
		p++
		if k == 0 {
			f |= 1
		} else if k < 0 {
			f |= 2
		} else {
			ans += k
		}
	}
	if ans == 0 || (f&1) == 0 {
		fmt.Println(0)
		return
	}
	if (f & 2) == 0 {
		fmt.Println(ans)
		return
	}

	for close, f = 0, 0; i <= w; i++ {
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-(i-f) > -a[i] {
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

	for close, f = 0, w; i >= 1; i-- {
		if a[i] == 0 {
			close = INF
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-(f-i) > -a[i] {
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

	for ans, i = 0, 1; i <= w; i++ {
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
