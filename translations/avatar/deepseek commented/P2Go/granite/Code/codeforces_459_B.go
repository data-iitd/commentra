
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0])

	// Step 2: Take a space-separated string of integers, convert them into a list of integers, and store it in `l1`.
	l1 := make([]int, n)
	for i, v := range strings.Split(bufio.NewReader(os.Stdin).ReadLine()[0], " ") {
		l1[i], _ = strconv.Atoi(v)
	}

	// Step 3: Sort the list `l1` in ascending order.
	for i := 0; i < n; i++ {
		for j := 0; j < n-i-1; j++ {
			if l1[j] > l1[j+1] {
				l1[j], l1[j+1] = l1[j+1], l1[j]
			}
		}
	}

	// Step 4: Assign the last element of the sorted list `l1` to `a`, which is the maximum value in the list.
	a := l1[n-1]

	// Step 5: Assign the first element of the sorted list `l1` to `b`, which is the minimum value in the list.
	b := l1[0]

	// Step 6: Check if `a` is equal to `b`.
	if a == b {
		// Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
		fmt.Println(a-b, n*(n-1)/2)
	} else {
		// Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the list `l1`.
		ac, bc := 0, 0
		for _, v := range l1 {
			if v == a {
				ac++
			} else if v == b {
				bc++
			}
		}
		// Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
		fmt.Println(a-b, ac*bc)
	}
}
