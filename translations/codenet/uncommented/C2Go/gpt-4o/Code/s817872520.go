package main

import (
	"fmt"
	"math"
)

const INF = 0x5fffffff

func getInt(p *string) (int, int) {
	n := 0
	if (*p)[0] == '-' {
		*p = (*p)[1:]
		for (*p)[0] >= '0' && (*p)[0] <= '9' {
			n = (n << 3) + (n << 1) + int((*p)[0]-'0')
			*p = (*p)[1:]
		}
		return -n, 0
	}
	for (*p)[0] >= '0' && (*p)[0] <= '9' {
		n = (n << 3) + (n << 1) + int((*p)[0]-'0')
		*p = (*p)[1:]
	}
	return n, 0
}

func main() {
	var w, i, k, f, close, ans int
	var a [100002]int
	var b [100002]int

	var buf [700002]byte
	var p *string

	n, _ := fmt.Scanf("%s", &buf)
	pStr := string(buf[:n])
	p = &pStr

	w, _ = getInt(p)

	n, _ = fmt.Scanf("%s", &buf)
	pStr = string(buf[:n])
	p = &pStr

	ans = 0
	f = 0
	for i = 1; i <= w; i++ {
		a[i], _ = getInt(p)
		if a[i] == 0 {
			f |= 1
		} else if a[i] < 0 {
			f |= 2
		} else {
			ans += a[i]
		}
	}

	if ans == 0 || f&1 == 0 {
		fmt.Println("0")
		return
	}
	if f&2 == 0 {
		fmt.Println(ans)
		return
	}

	close = 0
	f = 0
	for i = 1; i <= w; i++ {
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
				k = close - (i - f)
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	close = 0
	f = w
	for i = w; i >= 1; i-- {
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
				k = close - (f - i)
				if k < 0 {
					k = 0
				}
				if k > b[i] {
					b[i] = k
				}
			}
		}
	}

	ans = 0
	for i = 1; i <= w; i++ {
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

// <END-OF-CODE>
