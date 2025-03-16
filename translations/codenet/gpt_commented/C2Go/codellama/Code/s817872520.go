// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func getint() int {
	var n int
	if _, err := fmt.Sscanf(string(buf[p:]), "%d", &n); err != nil {
		panic(err)
	}
	p += len(strconv.Itoa(n))
	return n
}

var (
	buf []byte
	p   int
	w   int
	a   []int
	b   []int
)

func main() {
	var ans, f, close, k int

	// Read the width of the evacuation route
	fmt.Fscanf(os.Stdin, "%d", &w)
	// Read the evacuation route values
	buf, _ = bufio.NewReader(os.Stdin).ReadBytes('\n')
	p = 0

	// Initialize answer and flags, and process the route values
	for ans, f, i = 0, 0, 1; i <= w; i++ {
		a = append(a, k = getint())
		if !k {
			f |= 1
		} else if k < 0 {
			f |= 2
		} else {
			ans += k
		}
	}

	// Check for special cases: no positive values or only zeros
	if !ans || !(f&1) {
		fmt.Println(0)
		return
	}
	// If there are no negative values, print the total sum
	if !(f&2) {
		fmt.Println(ans)
		return
	}

	// Calculate the minimum distance to the closest zero from the left
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
				b = append(b, INF)
			} else {
				k = close - (i - f)
				if k < 0 {
					k = 0
				}
				b = append(b, k)
			}
		}
	}

	// Calculate the minimum distance to the closest zero from the right
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

	// Calculate the final answer based on the minimum distances
	for ans, i = 0, 1; i <= w; i++ {
		if a[i] > 0 {
			if b[i] > a[i] {
				ans += a[i]
			} else {
				ans += b[i]
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

// 