package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n, k int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &k)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &arr[i])
	}

	var res string
	var o, e int

	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++
		} else {
			e++
		}
	}

	for i := 0; i < k; i++ {
		var l, r int
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &l)
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &r)

		if (r-l+1)%2 == 1 {
			res += "0\n"
		} else {
			if (r-l+1)/2 <= o {
				res += "1\n"
			} else {
				res += "0\n"
			}
		}
	}

	fmt.Print(res)
}

