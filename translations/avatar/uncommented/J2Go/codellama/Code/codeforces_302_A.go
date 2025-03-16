
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, k int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i], _ = strconv.Atoi(scanner.Text())
	}
	var o, e int
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++
		} else {
			e++
		}
	}
	var res string
	for i := 0; i < k; i++ {
		scanner.Scan()
		l, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ := strconv.Atoi(scanner.Text())
		if (r-l+1)%2 == 1 {
			res += "0\n"
		} else {
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				res += "1\n"
			} else {
				res += "0\n"
			}
		}
	}
	fmt.Println(res)
}

