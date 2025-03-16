
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	inf = 0x5fffffff
)

var (
	buf = make([]byte, 700002)
	p   = buf
)

func getint() int {
	var n int
	if *p == '-' {
		p++
		for *p >= '0' {
			n = (n<<3) + (n<<1) + int(*p-48)
			p++
		}
		return -n
	}
	for *p >= '0' {
		n = (n<<3) + (n<<1) + int(*p-48)
		p++
	}
	return n
}

func main() {
	var w, i, k, f, close, ans int
	var flag bool

	// read the number of elements in the array 'a'
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &w)

	// read the elements of array 'a'
	for i = 1; i <= w; i++ {
		// read an element of array 'a'
		k, _ = strconv.Atoi(string(p))
		p += len(strconv.Itoa(k))

		// check if the current element is zero
		if k == 0 {
			flag = true
			continue
		}

		// if the current element is negative, update the 'close' variable
		// and set flag 'f' to -2 if all elements are negative
		if k < 0 {
			if f < 0 || close-i+f > -k {
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
	if ans == 0 ||!(f&1) == 1 {
		fmt.Println(0) // print 0 if the condition is true
		return
	}

	// if all elements are not negative, calculate the minimum number of steps to reach from the start or end
	if!(f&2) == 2 {
		fmt.Println(ans) // print the answer
		return
	}

	// initialize variables for the second loop
	for close = 0, f = w, i = w; i >= 1; i-- {
		// read an element of array 'a'
		if a[i] == 0 {
			close = inf
			f = -1
			continue
		}

		if a[i] < 0 {
			// if the current element is negative, update the 'close' variable
			// and set flag 'f' to the index of the current element
			if f < 0 || close-i+f > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			// if the current element is positive, update the 'b' array
			b[i] = inf
			if f >= 0 {
				k := close - i + f // calculate the minimum number of steps to reach from the start to the current index
				if k < 0 {
					k = 0
				} // if the number is negative, set it to zero
				b[i] = k // update the 'b' array
			}
		}
	}

	// initialize variables for the third loop
	for close = 0, f = w, i = 1; i <= w; i++ {
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

