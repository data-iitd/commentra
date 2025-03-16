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
	var n int
	if *p == '-' {
		p++
		for *p >= '0' {
			n = (n * 10) + int(*p-'0')
			p++
		}
		return -n
	}
	for *p >= '0' {
		n = (n * 10) + int(*p-'0')
		p++
	}
	return n
}

func main() {
	var w, i, k, f, close, ans int
	var p *rune

	// read the number of elements in the array 'a'
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	w, _ = strconv.Atoi(line)

	// read the elements of array 'a'
	buf := make([]byte, 700002)
	p = &buf[0]
	line, _ = reader.ReadString('\n')
	copy(buf, line)

	for ans, f, i = 0, 0, 1; i <= w; i++ {
		// read an element of array 'a'
		k = getint()
		p = &buf[0]

		// check if the current element is zero
		if k == 0 {
			f |= 1
			continue
		}

		// if the current element is negative, update the 'close' variable
		// and set flag 'f' to -2 if all elements are negative
		if k < 0 {
			if f < 0 || close-(i-f) > -k {
				close = -k
				f = i
			}
			if f < 0 {
				f = -2
			}
		}

		// update the 'ans' variable
		ans += k
	}

	// check if the sum of all positive elements is zero or if flag 'f' is 1
	if ans == 0 || !(f&1 == 1) {
		fmt.Println("0")
		return
	}

	// if all elements are not negative, calculate the minimum number of steps to reach from the start or end
	if !(f&2 == 2) {
		fmt.Println(ans)
		return
	}

	// initialize variables for the second loop
	for close, f = 0, w; i >= 1; i-- {
		// read an element of array 'a'
		if a[i] == 0 {
			close = INF
			f = -1
			continue
		}

		if a[i] < 0 {
			// if the current element is negative, update the 'close' variable
			// and set flag 'f' to the index of the current element
			if f < 0 || close-(f-i) > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			// if the current element is positive, update the 'b' array
			b[i] = INF
			if f >= 0 {
				k := close - (f - i)
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	// initialize variables for the third loop
	for close, f = 0, w; i <= w; i++ {
		// read an element of array 'a'
		if a[i] > 0 {
			// if the current element is positive, update the 'ans' variable
			if b[i] > a[i] {
				ans += a[i]
			} else {
				ans += b[i]
			}
		}
	}

	// print the answer
	fmt.Println(ans)
}

