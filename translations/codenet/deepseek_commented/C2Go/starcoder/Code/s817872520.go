<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

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

	fmt.Fscan(p, &w)
	buf, _ = p.ReadBytes('\n')
	for i = 1; i <= w; i++ {
<<<<<<< HEAD
		k, _ = strconv.Atoi(strings.TrimSpace(string(buf[0 : buf.Index(buf, '\n')+1])))
=======
		k, _ = strconv.Atoi(strings.TrimSpace(string(buf[0:len(buf)-1])))
>>>>>>> 98c87cb78a (data updated)
		buf, _ = p.ReadBytes('\n')
		if k == 0 {
			f |= 1
			continue
		}
		if k < 0 {
			f |= 2
			continue
		}
		ans += k
	}
	if ans == 0 || f&1 == 0 {
		fmt.Println(0)
		return
	}
	if f&2 == 0 {
		fmt.Println(ans)
		return
	}

	// Calculate the minimum evacuation routes
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

