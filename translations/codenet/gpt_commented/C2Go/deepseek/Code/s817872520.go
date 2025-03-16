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

func getint() int {
	n := 0
	if *p == '-' {
		p++
		for *p >= '0' {
			n = (n << 3) + (n << 1) + int(*p&0xf)
			p++
		}
		return -n
	}
	for *p >= '0' {
		n = (n << 3) + (n << 1) + int(*p&0xf)
		p++
	}
	return n
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	buf := make([]byte, 700002)
	p := buf

	// Read the width of the evacuation route
	line, _ := reader.ReadString('\n')
	w, _ := strconv.Atoi(strings.TrimSpace(line))

	// Read the evacuation route values
	line, _ = reader.ReadString('\n')
	copy(buf, line)
	p = buf

	// Initialize answer and flags, and process the route values
	ans := 0
	f := 0
	for i := 1; i <= w; i++ {
		a[i] = getint()
		p++
		if a[i] == 0 {
			f |= 1
		} else if a[i] < 0 {
			f |= 2
		} else {
			ans += a[i]
		}
	}

	// Check for special cases: no positive values or only zeros
	if ans == 0 || (f&1) == 0 {
		fmt.Println(0)
		return
	}
	// If there are no negative values, print the total sum
	if (f & 2) == 0 {
		fmt.Println(ans)
		return
	}

	// Calculate the minimum distance to the closest zero from the left
	close := 0
	for f, i := -1, 1; i <= w; i++ {
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

	// Calculate the minimum distance to the closest zero from the right
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

	// Calculate the final answer based on the minimum distances
	for i := 1; i <= w; i++ {
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

