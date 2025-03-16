package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var w int
	var a, b []int
	var ans int
	var f, close, k int
	var i int

	fmt.Scan(&w)
	a = make([]int, w+1)
	b = make([]int, w+1)
	for i = 1; i <= w; i++ {
		fmt.Scan(&a[i])
	}
	for i = 1; i <= w; i++ {
		if a[i] == 0 {
			close = 0x5fffffff
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-i+f > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = 0x5fffffff
			} else {
				k = close - i + f
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}
	for i = w; i >= 1; i-- {
		if a[i] == 0 {
			close = 0x5fffffff
			f = -1
		} else if a[i] < 0 {
			if f < 0 || close-f+i > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			if f < 0 {
				b[i] = 0x5fffffff
			} else {
				k = close - f + i
				if k < 0 {
					k = 0
				}
				if k > b[i] {
					b[i] = k
				}
			}
		}
	}
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

