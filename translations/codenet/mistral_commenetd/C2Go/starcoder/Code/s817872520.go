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
		a [100002]int
		b [100002]int
		w int
		i int
		k int
		f int
		close int
		ans int
	)

	// read the number of elements in the array 'a'
	fmt.Fscan(bufio.NewReader(os.Stdin), &w)

	// read the elements of array 'a'
	fmt.Fscan(bufio.NewReader(os.Stdin), &a[1])

	// initialize variables for the first loop
	ans = 0
	f = 0
<<<<<<< HEAD
	i = 1

	// initialize variables for the second loop
	close = 0
	f = w
	i = w

	// initialize variables for the third loop
	close = 0
	f = w
	i = 1

	// read an element of array 'a'
	for i <= w {
=======
	close = 0

	// initialize variables for the second loop
	for i = 1; i <= w; i++ {
>>>>>>> 98c87cb78a (data updated)
		// read an element of array 'a'
		k = a[i]

		// check if the current element is zero
		if k == 0 {
			f |= 1
			continue
		}

		// if the current element is negative, update the 'close' variable
		// and set flag 'f' to -2 if all elements are negative
		if k < 0 {
			if f < 0 || close - (i-f) > -k {
				close = -k
				f = i
			}
			if f < 0 {
				f = -2
			}
		}

		// update the 'ans' variable
		ans += k
<<<<<<< HEAD

		// read an element of array 'a'
		i++
=======
>>>>>>> 98c87cb78a (data updated)
	}

	// check if the sum of all positive elements is zero or if flag 'f' is 1
	if ans == 0 || f&1 == 0 {
<<<<<<< HEAD
		fmt.Println(0) // print 0 if the condition is true
=======
		fmt.Println(0)
>>>>>>> 98c87cb78a (data updated)
		return
	}

	// if all elements are not negative, calculate the minimum number of steps to reach from the start or end
	if f&2 == 0 {
<<<<<<< HEAD
		fmt.Println(ans) // print the answer
=======
		fmt.Println(ans)
>>>>>>> 98c87cb78a (data updated)
		return
	}

	// initialize variables for the second loop
<<<<<<< HEAD
	for i = w; i >= 1; i-- {
		// read an element of array 'a'
		if a[i] == 0 {
			close = INF
=======
	for close = 0; i >= 1; i-- {
		// read an element of array 'a'
		if a[i] == 0 {
			close = 1000000000
>>>>>>> 98c87cb78a (data updated)
			f = -1
			continue
		}

		if a[i] < 0 {
			// if the current element is negative, update the 'close' variable
			// and set flag 'f' to the index of the current element
			if f < 0 || close - (f-i) > -a[i] {
				close = -a[i]
				f = i
			}
		} else {
			// if the current element is positive, update the 'b' array
<<<<<<< HEAD
			b[i] = INF
=======
			b[i] = 1000000000
>>>>>>> 98c87cb78a (data updated)
			if f >= 0 {
				k = close - (f-i) // calculate the minimum number of steps to reach from the start to the current index
				if k < 0 {
					k = 0
<<<<<<< HEAD
				} // if the number is negative, set it to zero
=======
				}
>>>>>>> 98c87cb78a (data updated)
				b[i] = k // update the 'b' array
			}
		}
	}

	// initialize variables for the third loop
<<<<<<< HEAD
	for i = 1; i <= w; i++ {
=======
	for close = 0; i <= w; i++ {
>>>>>>> 98c87cb78a (data updated)
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

