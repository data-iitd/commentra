package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

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
		fmt.Fscan(reader, &l, &r)
		if (r-l+1)%2 == 1 {
			fmt.Fprintln(writer, "0")
		} else {
			if (r-l+1)/2 <= o && (r-l+1)/2 <= e {
				fmt.Fprintln(writer, "1")
			} else {
				fmt.Fprintln(writer, "0")
			}
		}
	}
}

