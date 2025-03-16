
// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	buf = make([]byte, 0)
	r   = bufio.NewReader(os.Stdin)
	w   = 0
	a   = make([]int, 100002)
	b   = make([]int, 100002)
	p   = 0
)

func getint() int {
	res := 0
	for {
		if buf[p] >= '0' && buf[p] <= '9' {
			res = (res << 3) + (res << 1) + int(buf[p]-'0')
			p++
		} else {
			p++
			break
		}
	}
	return res
}

func main() {
	var f, close, ans int
	var k int

	fgets(buf, 10, r)
	w = getint()
	fgets(buf, 700002, r)
	for ans = 0, f = 0, i = 1; i <= w; i++ {
		a[i] = k = getint()
		if k == 0 {
			f |= 1
		} else if k < 0 {
			f |= 2
		} else {
			ans += k
		}
	}
	if ans == 0 ||!(f&1)!= 0 {
		fmt.Println(0)
		return
	}
	if!(f&2)!= 0 {
		fmt.Println(ans)
		return
	}

	for close = 0, f = 0, i = 1; i <= w; i++ {
		if a[i] == 0 {
			close = 100000000
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-i+f > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = 100000000
			} else {
				k = close - i + f
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	for close = 0, f = w, i = w; i >= 1; i-- {
		if a[i] == 0 {
			close = 100000000
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close+i-f > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = 100000000
			} else {
				k = close + i - f
				if k < 0 {
					k = 0
				}
				if k > b[i] {
					b[i] = k
				}
			}
		}
	}

	for ans = 0, i = 1; i <= w; i++ {
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

