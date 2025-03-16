// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		w, i, k, f, close, ans int
		buf                    []byte
		p                      = bufio.NewReader(os.Stdin)
	)
	fmt.Fscanf(p, "%d\n", &w)
	fmt.Fscanf(p, "%s", &buf)
	for i = 1; i <= w; i++ {
		fmt.Fscanf(p, "%d", &k)
		if k == 0 {
			f |= 1
		} else if k < 0 {
			f |= 2
		} else {
			ans += k
		}
	}
	if ans == 0 ||!(f&1) {
		fmt.Println("0")
		return
	}
	if!(f&2) {
		fmt.Printf("%d\n", ans)
		return
	}

	for close = 0, f = 0, i = 1; i <= w; i++ {
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
				k = close - (i-f)
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	for close = 0, f = w, i = w; i >= 1; i-- {
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
				k = close - (f-i)
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
	fmt.Printf("%d\n", ans)
}

