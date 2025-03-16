package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var w int
	var a [100002]int
	var b [100002]int
	var ans int
	var close int
	var f int
	var i int
	var k int

	// read the number of elements in the array 'a'
	fmt.Scan(&w)

	// read the elements of array 'a'
	for i = 1; i <= w; i++ {
		fmt.Scan(&k)
		a[i] = k
	}

	// check if the sum of all positive elements is zero or if flag 'f' is 1
	for i = 1; i <= w; i++ {
		if a[i] > 0 {
			ans += a[i]
		}
	}
	if ans == 0 || f == 1 {
		fmt.Println(0)
		return
	}

	// if all elements are not negative, calculate the minimum number of steps to reach from the start or end
	if f != 2 {
		fmt.Println(ans)
		return
	}

	// initialize variables for the second loop
	for i = w; i >= 1; i-- {
		if a[i] == 0 {
			close = 2147483647
			f = -1
			continue
		}

		if a[i] < 0 {
			// if the current element is negative, update the 'close' variable
			// and set flag 'f' to the index of the current element
			if f < 0 || close-f+i > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			// if the current element is positive, update the 'b' array
			b[i] = 2147483647
			if f >= 0 {
				k = close - f + i
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	// initialize variables for the third loop
	for i = 1; i <= w; i++ {
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

