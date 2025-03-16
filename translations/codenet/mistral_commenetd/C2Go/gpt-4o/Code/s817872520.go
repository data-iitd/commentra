package main

import (
	"fmt"
	"math"
	"strings"
)

const INF = 0x5fffffff

func getInt(p *string) (int, *string) {
	n := 0
	if (*p)[0] == '-' {
		*p = (*p)[1:]
		for len(*p) > 0 && (*p)[0] >= '0' && (*p)[0] <= '9' {
			n = (n << 3) + (n << 1) + int((*p)[0]-'0')
			*p = (*p)[1:]
		}
		return -n, p
	}
	for len(*p) > 0 && (*p)[0] >= '0' && (*p)[0] <= '9' {
		n = (n << 3) + (n << 1) + int((*p)[0]-'0')
		*p = (*p)[1:]
	}
	return n, p
}

func main() {
	var w, k, f, close, ans int
	var a [100002]int
	var b [100002]int
	var buf string

	// Read the number of elements in the array 'a'
	fmt.Scanln(&buf)
	p := &buf
	w, p = getInt(p)

	// Read the elements of array 'a'
	fmt.Scanln(&buf)
	p = &buf
	for ans = 0; f = 0; k = 1; k <= w; k++ {
		var num int
		num, p = getInt(p)
		if num == 0 {
			f |= 1
			continue
		}
		if num < 0 {
			if f < 0 || close-(k-f) > -num {
				close = -num
				f = k
			}
			if f < 0 {
				f = -2
			}
		}
		ans += num
	}

	if ans == 0 || f&1 == 0 {
		fmt.Println("0")
		return
	}

	if f&2 == 0 {
		fmt.Println(ans)
		return
	}

	for close = 0; f = w; k = w; k >= 1; k-- {
		if a[k] == 0 {
			close = INF
			f = -1
			continue
		}
		if a[k] < 0 {
			if f < 0 || close-(f-k) > -a[k] {
				close = -a[k]
				f = k
			}
		} else {
			b[k] = INF
			if f >= 0 {
				temp := close - (f - k)
				if temp < 0 {
					temp = 0
				}
				b[k] = temp
			}
		}
	}

	for close = 0; f = w; k = 1; k <= w; k++ {
		if a[k] > 0 {
			if b[k] > a[k] {
				ans += a[k]
			} else {
				ans += b[k]
			}
		}
	}

	fmt.Println(ans)
}
