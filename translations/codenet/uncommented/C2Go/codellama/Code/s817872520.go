// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

package main

import (
	"fmt"
	"io"
	"os"
	"strconv"
)

func getint(r io.Reader) int {
	var n int
	if _, err := fmt.Fscan(r, &n); err != nil {
		panic(err)
	}
	return n
}

func main() {
	var w, i, k, f, close, ans int

	r := os.Stdin
	w = getint(r)
	var buf [700002]byte
	var p = buf[:]
	for i := 1; i <= w; i++ {
		a[i] = k = getint(r)
		if !k {
			f |= 1
		} else if k < 0 {
			f |= 2
		} else {
			ans += k
		}
	}
	if !ans || !(f&1) {
		fmt.Println(0)
		return
	}
	if !(f&2) {
		fmt.Println(ans)
		return
	}

	for close, f, i = 0, 0, 1; i <= w; i++ {
		if !a[i] {
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

	for close, f, i = 0, w, w; i >= 1; i-- {
		if !a[i] {
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

