package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n, i, k, p int
	var flag bool
	a := make([]int, 1000)

	// Step 5: Read the value of n from the user input
	scanner.Scan()
	n = toInt(scanner.Text())
	i = 0

	// Step 6: Enter a while loop that continues until k is less than or equal to n
	for k <= n {
		// Step 7: Update the value of i by adding k to it
		i += k

		// Step 8: Adjust the value of i if it is greater than or equal to n
		if i >= n {
			for i >= n {
				i -= n
			}
		}

		// Step 9: Increment the value of a[i] by 1
		a[i]++

		// Step 10: Increment the value of k by 1
		k++
	}

	// Step 11: Enter a for loop to check if any value in the array a is 0
	flag = true
	for i := 0; i < n; i++ {
		if a[i] == 0 {
			flag = false
			break
		}
	}

	// Step 12: Check the value of flag and print "YES" if flag is true, otherwise print "NO"
	if flag {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

